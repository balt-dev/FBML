#include <windows.h>
#include <memoryapi.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <lua.h>
#include <lauxlib.h>
#include "utils.h"
#include "luaimport.h"
#include "inject.h"

lua_newstate_t g_pOriginal_lua_newstate = NULL;
lua_newstate_t g_pTrampoline_lua_newstate = NULL;

// Trampoline injection
bool injectDetour(void *original, void *hook, void **trampoline) {
  #define STOLEN_BYTES 7
  #define JMP_SIZE 5
  #define JMP 0xE9
  #define NOP 0x90

  if (trampoline) {
    printf("Allocating memory for trampoline...\n");

    *trampoline = VirtualAlloc(NULL, STOLEN_BYTES + JMP_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!*trampoline) {
        printf("Error: Failed to allocate memory for trampoline.\n");
        return false;
    }
    memcpy(*trampoline, original, STOLEN_BYTES);

    LPBYTE jumpBackLocation = (LPBYTE)*trampoline + STOLEN_BYTES;
    *jumpBackLocation = JMP;

    LPBYTE jumpBackAddress = original + STOLEN_BYTES;
    DWORD jumpOffset = (DWORD)(jumpBackAddress - (jumpBackLocation + JMP_SIZE));
    *((DWORD*)(jumpBackLocation + 1)) = jumpOffset;
    printf("  Trampoline at: 0x%p\n", *trampoline);
    printf("  Jump-back instruction at:  0x%p\n", jumpBackLocation);
    printf("  Jump-back address: 0x%p\n", jumpBackAddress);
    printf("  Jump-back offset: 0x%p\n", jumpOffset);
  }

  printf("  Original at: 0x%p\n", original);
  printf("  Hook at: 0x%p\n", hook);

  DWORD oldProtect = 0;
  if (!VirtualProtect(original, STOLEN_BYTES, PAGE_EXECUTE_READWRITE, &oldProtect)) {
      printf("Error: VirtualProtect failed to change permissions on target function.\n");
      return false;
  }

  LPBYTE originalAddr = (LPBYTE)original;
  *originalAddr = JMP;
  DWORD hookOffset = (((LPBYTE) hook) - (originalAddr + JMP_SIZE));
  printf("  Hook offset: 0x%p\n", hookOffset);
  *((DWORD*)(originalAddr + 1)) = hookOffset;

  for (size_t i = JMP_SIZE; i < STOLEN_BYTES; ++i) {
      originalAddr[i] = NOP;
  }

  if (!VirtualProtect(original, STOLEN_BYTES, oldProtect, &oldProtect)) {
      printf("Error: VirtualProtect failed to restore permissions.\n");
      return false;
  }

  return true;
}

void * scanForSig(char sig[32]) {
    HMODULE hModule = GetModuleHandleA(NULL);

    MODULEINFO moduleInfo = {0};
    GetModuleInformation(GetCurrentProcess(), hModule, &moduleInfo, sizeof(MODULEINFO));

    char * base = (char *) moduleInfo.lpBaseOfDll;
    char * end = base + moduleInfo.SizeOfImage;

    for (char *current = base; current < end - 32; ++current) {
        bool found = true;
        for (size_t i = 0; i < 32; ++i) {
            if (current[i] != sig[i]) {
                found = false;
                break;
            }
        }
        if (found) {
            printf("Signature found at address: 0x%p\n", current);
            return current;
        }
    }
    printf("Signature not found.\n");
    return NULL;
}

bool pointersSetUp = false;

lua_State* __cdecl Hooked_lua_newstate(lua_Alloc f, void* ud) {
    if (!pointersSetUp) {
        #define LUA_NEWSTATE_GHIDRA 0x010F0430
        printf("lua_newstate is at 0x%p\n", g_pOriginal_lua_newstate);
        LPBYTE baseAddr = (LPBYTE)g_pOriginal_lua_newstate - LUA_NEWSTATE_GHIDRA;
        printf("Address offset: %p\n", baseAddr);
        setupFunctionPointers((DWORD) baseAddr);
        pointersSetUp = true;
    }
    lua_State* L = g_pTrampoline_lua_newstate(f, ud);
    printf("Injecting libraries...\n");
    injectLibraries(L);

    return L;
}

void __cdecl Hooked_CheckAgainstWhiteList(int param_11) {}
