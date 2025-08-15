#include <windows.h>
#include <memoryapi.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "luaimport.h"
#include "inject.h"
#include "lib.h"

#define LUA_NEWSTATE_OFFSET 0x0110b3d0

lua_newstate_t g_pOriginal_lua_newstate = NULL;
lua_newstate_t g_pTrampoline_lua_newstate = NULL;

bool pointersSetUp = false;

lua_State* __cdecl Hooked_lua_newstate(lua_Alloc f, void* ud) {
    if (!pointersSetUp) {
        printf("lua_newstate is at 0x%p\n", g_pOriginal_lua_newstate);
        LPBYTE baseAddr = (LPBYTE)g_pOriginal_lua_newstate - LUA_NEWSTATE_OFFSET;
        printf("Address offset: %p\n", baseAddr);
        setupFunctionPointers((DWORD) baseAddr);
        pointersSetUp = true;
    }
    lua_State* L = g_pTrampoline_lua_newstate(f, ud);
    injectLibraries(L);

    return L;
}

void __cdecl Hooked_CheckAgainstWhiteList(int param_11) {}
