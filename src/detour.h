#pragma once

#include <lua.h>
#include <lauxlib.h>

void * scanForSig(char * sig, size_t len);
bool injectDetour(void *target, void *hook, void **orig);
void injectLibraries(lua_State * state);
