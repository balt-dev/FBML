#include "luaimport.h"
#include <stdio.h>

#define p_lua_newtable(L)		p_lua_createtable(L, 0, 0)

#define DPTR(name) name##_t p_##name;

DPTR(luaL_setfuncs);
DPTR(lua_setglobal);
DPTR(lua_createtable);
DPTR(lua_pushstring);

void setupFunctionPointers(long unsigned int baseAddr) {
	printf("Setting up function pointers...\n");
    printf("Base address: 0x%p\n", (void*) baseAddr);

	#define FPTR(addr, name) \
		p_##name = (name##_t) (addr + baseAddr); \
		printf("\t" #name ": %p\n", p_##name);

	FPTR(0x010f8100, luaL_setfuncs);
	FPTR(0x010e6d20, lua_setglobal);
	FPTR(0x010e6c10, lua_createtable);
	FPTR(0x010e6700, lua_pushstring);
}
