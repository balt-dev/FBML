#include <windows.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <lua.h>
#include <lauxlib.h>

// The first 64 bytes of the function signature
static char LUA_NEWSTATE_SIG [] = {
  0x55, 0x57, 0x56, 0x53, 0x83, 0xec, 0x3c, 0x8b,
  0x44, 0x24, 0x54, 0x8b, 0x6c, 0x24, 0x50, 0xc7,
  0x44, 0x24, 0x0c, 0x38, 0x03, 0x00, 0x00, 0xc7,
  0x44, 0x24, 0x08, 0x08, 0x00, 0x00, 0x00, 0xc7,
  0x44, 0x24, 0x04, 0x00, 0x00, 0x00, 0x00, 0x89,
  0x04, 0x24, 0xff, 0xd5, 0x85, 0xc0, 0x89, 0xc3,
  0x0f, 0x84, 0x3d, 0x02, 0x00, 0x00, 0x8d, 0x70,
  0x04, 0x31, 0xc9, 0x8d, 0xb8, 0x80, 0x00, 0x00
};

// Patch in our library

void * scanForSig() {
    HMODULE hModule = GetModuleHandleA(NULL);

    MODULEINFO moduleInfo = {0};
    GetModuleInformation(GetCurrentProcess(), hModule, &moduleInfo, sizeof(MODULEINFO));

    char * base = (char *) moduleInfo.lpBaseOfDll;
    char * end = base + moduleInfo.SizeOfImage;

    for (char *current = base; current < end - 64; ++current) {
        bool found = true;
        for (size_t i = 0; i < 64; ++i) {
            if (current[i] != LUA_NEWSTATE_SIG[i]) {
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
typedef lua_State* (__cdecl *lua_newstate_t)(lua_Alloc f, void* ud);

static HMODULE g_original_dll = NULL;
lua_newstate_t g_pOriginal_lua_newstate = NULL;
lua_newstate_t g_pTrampoline_lua_newstate = NULL;

lua_State* __cdecl Hooked_lua_newstate(lua_Alloc f, void* ud) {
  printf("Function is being called!\n");
  lua_State* L = g_pTrampoline_lua_newstate(f, ud);
  printf("Function called!\n");
  return L;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);

            AllocConsole();
            freopen("CONOUT$", "w", stdout);
            printf("Proxy DLL attached. Attempting to hook lua_newstate...\n");

            LPVOID pTargetAddress = scanForSig();
            if (!pTargetAddress) {
              printf("Failed to find address of lua_newstate.");
              MessageBoxA(NULL, "!", "!", 0);
              return FALSE;
            }
            g_pOriginal_lua_newstate = (lua_newstate_t)pTargetAddress;

            if (!injectDetour(pTargetAddress, Hooked_lua_newstate, &g_pTrampoline_lua_newstate)) {
              printf("Error: Failed to detour lua_newstate.\n");
              MessageBoxA(NULL, "!", "!", 0);
              return FALSE;
            }

            printf("Bytes at original:\n\t");
            for (size_t i = 0; i < 16; ++i) {
              printf("%02X ", ((unsigned char*)(g_pOriginal_lua_newstate))[i]);
            }
            printf("\n");

            printf("Bytes at trampoline:\n\t");
            for (size_t i = 0; i < 16; ++i) {
              printf("%02X ", ((unsigned char*)(g_pTrampoline_lua_newstate))[i]);
            }
            printf("\n");

            MessageBoxA(NULL, "!", "!", 0);

            freopen("CON", "w", stdout);

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

static int l_getOne (lua_State *L) {
  lua_pushnumber(L, 1.0);
  return 1;
};

static const struct luaL_Reg multiplayerLib [] = {
  {"getOne", l_getOne},
  {NULL, NULL}
};

int luaopen_testlib(lua_State *L) {
    return 1;
};
