#include "luaimport.h"
#include <stdio.h>
#include <windows.h>

int fix_libs(lua_State *L) {
  p_luaL_openlibs(L);
  return 0;
}

void injectLibraries(lua_State * L) {
  printf("Injecting...\n");
  p_lua_pushcclosure(L, (fix_libs), 0);
  p_lua_setglobal(L, "fixlibs");

  fix_libs(L);
}
