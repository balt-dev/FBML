#pragma once

typedef struct lua_State lua_State;
typedef int (*lua_CFunction) (lua_State *L);
typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;
typedef void* lua_Alloc;

#define FPTR_S(ret, name, sig) \
	typedef ret ( *name##_t ) sig; \
	extern name##_t p_##name; \

#define p_lua_newtable(L)		p_lua_createtable(L, 0, 0)
#define lua_isnil(L,n)		(p_lua_type(L, (n)) == 0)

FPTR_S(lua_State *, lua_newstate, (lua_Alloc f, void *ud));

FPTR_S(void, luaL_openlibs, (lua_State *L));
FPTR_S(void, lua_pushcclosure, (lua_State *L, lua_CFunction fn, int n));
FPTR_S(void, lua_setglobal, (lua_State *L, const char *var));
FPTR_S(void, luaL_openlibs, (lua_State *L));

void setupFunctionPointers(long unsigned int ptr_offset);
