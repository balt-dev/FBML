#pragma once

typedef struct lua_State lua_State;
typedef int (*lua_CFunction) (lua_State *L);
typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;

#define FPTR_S(ret, name, sig) \
	typedef ret ( *name##_t ) sig; \
	extern name##_t p_##name; \

#define p_lua_newtable(L)		p_lua_createtable(L, 0, 0)

FPTR_S(void, luaL_setfuncs, (lua_State *L, const luaL_Reg *l, int nup));
FPTR_S(void, lua_setglobal, (lua_State *L, const char *var));
FPTR_S(void, lua_createtable, (lua_State *L, int narr, int nrec));
FPTR_S(const char *, lua_pushstring, (lua_State *L, const char *s));

void setupFunctionPointers(long unsigned int ptr_offset);
