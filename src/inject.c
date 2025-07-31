#include <windows.h>
#include <memoryapi.h>
#include <psapi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <lua.h>
#include <lauxlib.h>

// Trampoline injection
bool injectDetour(void *target, void *hook, void **patch) {
  #define STOLEN_BYTES 7
  #define JMP_SIZE 5
  #define JMP 0xE9
  #define NOP 0x90

  printf("Allocating memory for trampoline...\n");

  *patch = VirtualAlloc(NULL, STOLEN_BYTES + JMP_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
  if (!*patch) {
      printf("Error: Failed to allocate memory for trampoline.\n");
      return false;
  }

  memcpy(*patch, target, STOLEN_BYTES);

  LPBYTE jumpBack = (void *) (*patch) + STOLEN_BYTES;
  *jumpBack = JMP;

  DWORD jumpOffset = (jumpBack - ((LPBYTE)target + JMP_SIZE));
  *((DWORD*)(jumpBack + 1)) = jumpOffset;

  printf("  Target at: 0x%p\n", target);
  printf("  Patch at: 0x%p\n", *patch);
  printf("  Jump-back instruction at:  0x%p\n", jumpBack);
  printf("  Jump-back address: 0x%p\n", jumpOffset);

  DWORD oldProtect = 0;
  if (!VirtualProtect(target, STOLEN_BYTES, PAGE_EXECUTE_READWRITE, &oldProtect)) {
      printf("Error: VirtualProtect failed to change permissions on target function.\n");
      return false;
  }

  LPBYTE targetAddr = (LPBYTE)target;
  *targetAddr = JMP;
  DWORD trampolineOffset = ((targetAddr + JMP_SIZE) - (LPBYTE)*patch);
  printf("  Trampoline offset: 0x%p\n", trampolineOffset);
  *((DWORD*)(targetAddr + 1)) = trampolineOffset;

  for (size_t i = JMP_SIZE; i < STOLEN_BYTES; ++i) {
      targetAddr[i] = NOP; // NOP
  }

  if (!VirtualProtect(target, STOLEN_BYTES, oldProtect, &oldProtect)) {
      printf("Error: VirtualProtect failed to restore permissions.\n");
      return false;
  }

  return true;
}
