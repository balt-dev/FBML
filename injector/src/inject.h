#pragma once

#include <lua.h>
#include <lauxlib.h>

void * scanForSig(char sig[32]);
bool injectDetour(void *target, void *hook, void **orig);
void injectLibraries(lua_State * state);
lua_State* __cdecl Hooked_lua_newstate(lua_Alloc f, void* ud);
void __cdecl Hooked_CheckAgainstWhiteList(int param_11);

typedef lua_State* (__cdecl *lua_newstate_t)(lua_Alloc f, void* ud);

extern lua_newstate_t g_pOriginal_lua_newstate;
extern lua_newstate_t g_pTrampoline_lua_newstate;
