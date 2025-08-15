#include <windows.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "inject.h"
#include "detour.h"

HMODULE g_original_dll = NULL;

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

BOOL injectDLL() {
    printf("Proxy DLL attached.\n");

    LPVOID pNewstateAddress = scanForSig(LUA_NEWSTATE_SIG, 32);
    if (!pNewstateAddress) {
      printf("Failed to find address of lua_newstate.");
      return FALSE;
    }
    g_pOriginal_lua_newstate = (lua_newstate_t)pNewstateAddress;

    if (!injectDetour(pNewstateAddress, Hooked_lua_newstate, (void**) &g_pTrampoline_lua_newstate, 7)) {
      printf("Error: Failed to detour lua_newstate.\n");
      return FALSE;
    }

    LPVOID pWhitelistAddress = scanForSig(WHITELIST_CHK_SIG, 32);
    if (!pWhitelistAddress) {
      printf("Failed to find address of CheckAgainstWhiteList.");
      return FALSE;
    }

    if (!injectDetour(pWhitelistAddress, Hooked_CheckAgainstWhiteList, NULL, 7)) {
      printf("Error: Failed to detour CheckAgainstWhiteList.\n");
      return FALSE;
    }

    g_original_dll = LoadLibraryA("zlib1-orig.dll");

    if (!g_original_dll) {
        return FALSE;
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);

            FreeConsole();
            AllocConsole();
            freopen("CONOUT$", "w", stdout);

            BOOL ret = injectDLL();

            MessageBoxA(NULL, ret ? "Codemod injector loaded." : "Codemod injector failed :(\nCheck the console output.", "FBML", 0);

            return ret;

            break;
        case DLL_PROCESS_DETACH:
            if (g_original_dll) {
                FreeLibrary(g_original_dll);
            }
            break;
    }
    return TRUE;
}