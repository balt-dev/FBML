#include "luaimport.h"
#include <stdio.h>

#define DPTR(name) name##_t p_##name;

DPTR(lua_setglobal);
DPTR(lua_pushcclosure);
DPTR(luaL_openlibs);

void setupFunctionPointers(long unsigned int baseAddr) {
	printf("Setting up function pointers...\n");
    printf("Base address: 0x%p\n", (void*) baseAddr);

	#define FPTR(addr, name) \
		p_##name = (name##_t) addr + baseAddr; \
		printf("\t" #name ": %p\n", p_##name);

	FPTR(0x01101cc0, lua_setglobal);
	FPTR(0x01101790, lua_pushcclosure);
	FPTR(0x011134f0, luaL_openlibs);
}
