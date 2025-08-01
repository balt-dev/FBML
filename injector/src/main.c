#include <windows.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <lua.h>
#include <lauxlib.h>
#include "luaimport.h"
#include "utils.h"

// The first 32 bytes of the function signature
static char LUA_NEWSTATE_SIG [32] = {
  0x55, 0x57, 0x56, 0x53, 0x83, 0xec, 0x3c, 0x8b,
  0x44, 0x24, 0x54, 0x8b, 0x6c, 0x24, 0x50, 0xc7,
  0x44, 0x24, 0x0c, 0x38, 0x03, 0x00, 0x00, 0xc7,
  0x44, 0x24, 0x08, 0x08, 0x00, 0x00, 0x00, 0xc7,
};

// Patch in our library

void * scanForSig(char sig[32]) {
    HMODULE hModule = GetModuleHandleA(NULL);

    MODULEINFO moduleInfo = {0};
    GetModuleInformation(GetCurrentProcess(), hModule, &moduleInfo, sizeof(MODULEINFO));

    char * base = (char *) moduleInfo.lpBaseOfDll;
    char * end = base + moduleInfo.SizeOfImage;

    for (char *current = base; current < end - 32; ++current) {
        bool found = true;
        for (size_t i = 0; i < 32; ++i) {
            if (current[i] != sig[i]) {
                found = false;
                break;
            }
        }
        if (found) {
            printf("Signature found at address: 0x%p\n", current);
            return current;
        }
    }
    printf("Signature not found.\n");
    return NULL;
}

bool injectDetour(void *target, void *hook, void *orig);
bool yeetWhitelist(DWORD baseAddr);
typedef lua_State* (__cdecl *lua_newstate_t)(lua_Alloc f, void* ud);

static HMODULE g_original_dll = NULL;
lua_newstate_t g_pOriginal_lua_newstate = NULL;
lua_newstate_t g_pTrampoline_lua_newstate = NULL;

void injectLibraries(lua_State * state);

bool pointersSetUp = false;

lua_State* __cdecl Hooked_lua_newstate(lua_Alloc f, void* ud) {
    if (!pointersSetUp) {
        #define LUA_NEWSTATE_GHIDRA 0x010F0430
        printf("lua_newstate is at 0x%p\n", g_pOriginal_lua_newstate);
        LPBYTE baseAddr = (LPBYTE)g_pOriginal_lua_newstate - LUA_NEWSTATE_GHIDRA;
        printf("Address offset: %p\n", baseAddr);
        setupFunctionPointers((DWORD) baseAddr);
        pointersSetUp = true;
    }
    lua_State* L = g_pTrampoline_lua_newstate(f, ud);
    printf("Injecting libraries...\n");
    injectLibraries(L);
    return L;
}

void __cdecl Hooked_CheckAgainstWhiteList(int param_11) {}

static char WHITELIST_CHK_SIG [32] = {
    0x55, 0x57, 0x56, 0x53, 0x83, 0xec, 0x4c, 0x8d,
    0x44, 0x24, 0x2c, 0xc7, 0x44, 0x24, 0x2c, 0x00,
    0x00, 0x00, 0x00, 0x8b, 0x5c, 0x24, 0x60, 0x89,
    0x44, 0x24, 0x34, 0x89, 0x44, 0x24, 0x38, 0x8d
};

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);

            AllocConsole();
            freopen("CONOUT$", "w", stdout);
            printf("Proxy DLL attached. Attempting to hook lua_newstate...\n");

            LPVOID pNewstateAddress = scanForSig(LUA_NEWSTATE_SIG);
            if (!pNewstateAddress) {
              printf("Failed to find address of lua_newstate.");
              return FALSE;
            }
            g_pOriginal_lua_newstate = (lua_newstate_t)pNewstateAddress;

            if (!injectDetour(pNewstateAddress, Hooked_lua_newstate, &g_pTrampoline_lua_newstate)) {
              printf("Error: Failed to detour lua_newstate.\n");
              return FALSE;
            }

            LPVOID pWhitelistAddress = scanForSig(WHITELIST_CHK_SIG);
            if (!pWhitelistAddress) {
              printf("Failed to find address of CheckAgainstWhiteList.");
              return FALSE;
            }

            if (!injectDetour(pWhitelistAddress, Hooked_CheckAgainstWhiteList, NULL)) {
              printf("Error: Failed to detour CheckAgainstWhiteList.\n");
              return FALSE;
            }

            g_original_dll = LoadLibraryA("zlib1-orig.dll");

            if (!g_original_dll) {
                return FALSE;
            }

            break;
        case DLL_PROCESS_DETACH:
            if (g_original_dll) {
                FreeLibrary(g_original_dll);
            }
            break;
    }
    return TRUE;
}
