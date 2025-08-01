#include "luaimport.h"
#include <stdio.h>
#include "utils.h"

static int l_testFunction (lua_State *L) {
  p_lua_pushstring(L, ":3");
  return 1;
};

static const struct luaL_Reg multiplayerLib [] = {
  {"testFunction", l_testFunction},
  {NULL, NULL}
};

void injectLibraries(lua_State * L) {
  printf("Injecting libraries...\n");
  DBGPRINT(p_lua_createtable);
  DBGPRINT(p_luaL_setfuncs);
  DBGPRINT(p_lua_setglobal);
  p_lua_newtable(L);
  printf("Created table\n");
  p_luaL_setfuncs(L, multiplayerLib, 0);
  printf("Set functions\n");
  p_lua_setglobal(L, "multiplayerLib");
  printf("Set global\n");
}
