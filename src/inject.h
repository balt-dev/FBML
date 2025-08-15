#pragma once

#include "luaimport.h"

lua_State* __cdecl Hooked_lua_newstate(lua_Alloc f, void* ud);
void __cdecl Hooked_CheckAgainstWhiteList(int param_11);

extern lua_newstate_t g_pOriginal_lua_newstate;
extern lua_newstate_t g_pTrampoline_lua_newstate;