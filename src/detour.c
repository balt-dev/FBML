#include <windows.h>
#include <memoryapi.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

// Trampoline injection
bool injectDetour(void *original, void *hook, void **trampoline, size_t stolenBytes) {
  #define JMP_SIZE 5
  #define JMP 0xE9
  #define NOP 0x90

  if (trampoline) {
    *trampoline = VirtualAlloc(NULL, stolenBytes + JMP_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!*trampoline) {
        printf("Error: Failed to allocate memory for trampoline.\n");
        return false;
    }
    memcpy(*trampoline, original, stolenBytes);

    LPBYTE jumpBackLocation = (LPBYTE)*trampoline + stolenBytes;
    *jumpBackLocation = JMP;

    LPBYTE jumpBackAddress = original + stolenBytes;
    DWORD jumpOffset = (DWORD)(jumpBackAddress - (jumpBackLocation + JMP_SIZE));
    *((DWORD*)(jumpBackLocation + 1)) = jumpOffset;
  }

  DWORD oldProtect = 0;
  if (!VirtualProtect(original, stolenBytes, PAGE_EXECUTE_READWRITE, &oldProtect)) {
      printf("Error: VirtualProtect failed to change permissions on target function.\n");
      return false;
  }

  LPBYTE originalAddr = (LPBYTE)original;
  *originalAddr = JMP;
  DWORD hookOffset = (((LPBYTE) hook) - (originalAddr + JMP_SIZE));
  *((DWORD*)(originalAddr + 1)) = hookOffset;

  for (size_t i = JMP_SIZE; i < stolenBytes; ++i) {
      originalAddr[i] = NOP;
  }

  if (!VirtualProtect(original, stolenBytes, oldProtect, &oldProtect)) {
      printf("Error: VirtualProtect failed to restore permissions.\n");
      return false;
  }

  return true;
}

void * scanForSig(char * sig, size_t len) {
    HMODULE hModule = GetModuleHandleA(NULL);

    MODULEINFO moduleInfo = {0};
    GetModuleInformation(GetCurrentProcess(), hModule, &moduleInfo, sizeof(MODULEINFO));

    char * base = (char *) moduleInfo.lpBaseOfDll;
    char * end = base + moduleInfo.SizeOfImage;

    for (char *current = base; current < end - len; ++current) {
        bool found = true;
        for (size_t i = 0; i < len; ++i) {
            if (current[i] != sig[i]) {
                found = false;
                break;
            }
        }
        if (found) {
            return current;
        }
    }
    return NULL;
}
