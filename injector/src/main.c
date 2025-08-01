#include <windows.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "luaimport.h"
#include "utils.h"
#include "inject.h"


// Patch in our library

static char LUA_NEWSTATE_SIG [32] = {
  0x55, 0x57, 0x56, 0x53, 0x83, 0xec, 0x3c, 0x8b,
  0x44, 0x24, 0x54, 0x8b, 0x6c, 0x24, 0x50, 0xc7,
  0x44, 0x24, 0x0c, 0x38, 0x03, 0x00, 0x00, 0xc7,
  0x44, 0x24, 0x08, 0x08, 0x00, 0x00, 0x00, 0xc7,
};
static char WHITELIST_CHK_SIG [32] = {
    0x55, 0x57, 0x56, 0x53, 0x83, 0xec, 0x4c, 0x8d,
    0x44, 0x24, 0x2c, 0xc7, 0x44, 0x24, 0x2c, 0x00,
    0x00, 0x00, 0x00, 0x8b, 0x5c, 0x24, 0x60, 0x89,
    0x44, 0x24, 0x34, 0x89, 0x44, 0x24, 0x38, 0x8d
};

static HMODULE g_original_dll = NULL;

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

            if (!injectDetour(pNewstateAddress, Hooked_lua_newstate, (void**) &g_pTrampoline_lua_newstate)) {
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
