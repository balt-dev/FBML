#include <windows.h>
#include <stdint.h>

// DLL stuff

static HMODULE g_original_dll = NULL;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);

            g_original_dll = LoadLibraryA("lua52.orig.dll");

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

// Patch in our library

#include <lua.h>
#include <lauxlib.h>

static int l_getOne (lua_State *L) {
  lua_pushnumber(L, 1.0);
  return 1;
};

static const struct luaL_Reg testlib [] = {
  {"getOne", l_getOne},
  {NULL, NULL}
};

int luaopen_testlib(lua_State *L) {
    return 1;
};

typedef lua_State *(*PROXY_lua_newstate_FUNC)(lua_Alloc f, void *ud);
__declspec(dllexport) lua_State *lua_newstate(lua_Alloc f, void *ud) {
  static PROXY_lua_newstate_FUNC orig = NULL;
  orig = orig ? orig
              : (PROXY_lua_newstate_FUNC)GetProcAddress(g_original_dll,
                                                        "lua_newstate");

  lua_State *state = orig(f, ud);
  luaL_newlib(state, testlib);
  return state;
};
