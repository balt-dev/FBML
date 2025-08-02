#include <windows.h>
#include <stdio.h>
#include <fileapi.h>
#include <shlwapi.h>
#include "inject.h"

// Warning: This code is spaghetti. Very spaghetti. I am an amateur at C and it shows. But it works.

#define BAIL(err) { printf(err "\n"); return 0; }

#define PRINT_LAST_ERROR() do { \
    LPVOID lpMsgBuf; \
	DWORD dw = GetLastError(); \
	if (FormatMessage( \
        FORMAT_MESSAGE_ALLOCATE_BUFFER | \
        FORMAT_MESSAGE_FROM_SYSTEM | \
        FORMAT_MESSAGE_IGNORE_INSERTS, \
        NULL, \
        dw, \
        0, \
        (LPTSTR) &lpMsgBuf, \
        0, NULL \
    ) == 0) printf("Error code: %d\n", dw); \
	else { \
		printf("Error: %s\n", lpMsgBuf); \
		LocalFree(lpMsgBuf); \
	} \
} while (0)

#define EBAIL(err) { printf(err); PRINT_LAST_ERROR(); return 0; }

char * concat(char * a, const char * b) {
	size_t aLen = strlen(a);
	size_t bLen = strlen(b);
	char * ret = malloc(aLen + bLen + 1);
	if (!ret) return 0;
	memcpy(ret, a, aLen);
	memcpy(ret+aLen, b, bLen + 1);
	return ret;
}

// There's a few small memory leaks on the failure path, but I don't really care that much
HANDLE getModDLLs(LPWIN32_FIND_DATAA fileData, char ** codemodDir) {
	// Get the current directory
	DWORD currDirLength = GetCurrentDirectory(0, NULL);
	LPTSTR currDir = malloc(currDirLength);
	DWORD writtenChars = GetCurrentDirectory(currDirLength, currDir);
	if (!writtenChars) BAIL("Failed to get current directory.");

	// Go 2 up, so we're in the root directory
	LPTSTR lastBackslash = strrchr(currDir, '\\');
	if (!lastBackslash) BAIL("Failed to get parent directory of executable.");
	*lastBackslash = 0;
	lastBackslash = strrchr(currDir, '\\');
	if (!lastBackslash) BAIL("Failed to get parent directory of executable.");
	*lastBackslash = 0;

	if (!(*codemodDir = concat(currDir, "\\Codemods"))) BAIL("Failed to concatenate with current directory.");
	free(currDir);

	printf("Looking for code mods...\n");

	// Make the Coremods dir if it doesn't exist - if it does, check it's actually a directory
	if (!PathFileExistsA(*codemodDir)) {
		if (!CreateDirectoryA(*codemodDir, NULL)) BAIL("Failed to create Codemods directory.");
		printf("Created Codemods directory.\n");
		return (void *) 1;
	} else {
		if (!PathIsDirectoryA(*codemodDir)) BAIL("Path leading to Codemods is not a directory.");
	}

	char * searchString;

	if (!(searchString = concat(*codemodDir, "\\*.dll"))) BAIL("Failed to concatenate with current directory.");

	printf("Search string: %s\n", searchString);

	HANDLE searchHandle = FindFirstFileA(searchString, fileData);
	if (searchHandle == INVALID_HANDLE_VALUE) {
		DWORD err = GetLastError();
		if (err == ERROR_FILE_NOT_FOUND) { printf("No codemods found."); return (void *) 1; }
		EBAIL("Failed to search for .dll files.");
	}

	//free(searchString); For some reason the search handle reuses it. We can't free it.

	return searchHandle;
}

/// Returns a list of mod DLLs, with its length stored in the input pointer.
/// Returns NULL on error.
char * * findModDLLs(size_t * len) {
	*len = 0;
	// Allocate for each directory
	char * * ret = malloc(sizeof(char*) * 8);
	if (!ret) BAIL("Failed to allocate.");
	unsigned int allocated = 0;

	// Find the DLLs we need to load
	WIN32_FIND_DATA fileData = {0};
	char * codemodDir;
	HANDLE dllsToLoad = getModDLLs(&fileData, &codemodDir);

	if (!dllsToLoad) return 0;
	if (dllsToLoad == (void*) 1) { *len = 0; return (void*) 1; }

	while (true) {
		char * codemodPath = concat(codemodDir, "\\");
		if (!codemodPath) {free(codemodDir); FindClose(dllsToLoad); BAIL("Failed to allocate.")}
		char * dllPath = concat(codemodPath, fileData.cFileName);
		free(codemodPath);
		if (!dllPath) {free(codemodDir); FindClose(dllsToLoad); BAIL("Failed to allocate.")}

		(*len)++;
		allocated++;
		if (allocated >= 8) {
			allocated = 0;
			ret = realloc(ret, sizeof(char*) * *len);
			if (!ret) {free(codemodDir); FindClose(dllsToLoad); BAIL("Failed to allocate.")}
		}
		ret[*len - 1] = dllPath;

		if (!FindNextFileA(dllsToLoad, &fileData)) {
			DWORD err = GetLastError();
			if (err == ERROR_NO_MORE_FILES) break;
			free(codemodDir);
			FindClose(dllsToLoad);
			EBAIL("Failed while finding codemods.");
		}
	};

	free(codemodDir);
	FindClose(dllsToLoad);

	return ret;
}

DLLHandle * loadedDLLs;
size_t loadedDLLCount = 0;

bool attachDLLs() {
	size_t modsToLoad = 0;
	char * * modDLLs = findModDLLs(&modsToLoad);
	if (!modDLLs) return false;
	if (!modsToLoad) return true;

	loadedDLLs = malloc(sizeof(DLLHandle) * modsToLoad);

	for (size_t i = 0; i < modsToLoad; i++) {
		char* dllPath = modDLLs[i];

		HMODULE module = LoadLibraryA(dllPath);
		if (!module) {
			printf("Failed to load DLL %s. ", dllPath);
			PRINT_LAST_ERROR();
			continue;
		}

		free(dllPath);

		loadedDLLs[loadedDLLCount++] = (struct DLLHandle) {.moduleHandle = module};

		free(dllPath);
	}
	free(modDLLs);
}

void freeDLLs() {
	for (size_t i = 0; i < loadedDLLCount; i++) {
		DLLHandle handle = loadedDLLs[i];
        FreeLibrary(handle.moduleHandle);
	}
	free(loadedDLLs);
}

