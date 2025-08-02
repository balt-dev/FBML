#include <windows.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "inject.h"

static HMODULE g_original_dll = NULL;

BOOL injectDLL() {
    printf("Proxy DLL attached.\n");

    if (!attachDLLs()) {
        printf("Failed to attach mods.\n");
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
            freeDLLs();
            if (g_original_dll) {
                FreeLibrary(g_original_dll);
            }
            break;
    }
    return TRUE;
}

/*
    Old code for hooking, for reference:

    LPVOID pNewstateAddress = scanForSig(LUA_NEWSTATE_SIG, 32);
    if (!pNewstateAddress) {
      printf("Failed to find address of lua_newstate.");
      return FALSE;
    }
    g_pOriginal_lua_newstate = (lua_newstate_t)pNewstateAddress;

    if (!injectDetour(pNewstateAddress, Hooked_lua_newstate, (void**) &g_pTrampoline_lua_newstate)) {
      printf("Error: Failed to detour lua_newstate.\n");
      return FALSE;
    }
*/
