#pragma once

#include <stdint.h>

bool injectDetour(void *original, void *hook, void **trampoline, size_t stolenBytes);
void * scanForSig(char * sig, size_t len);
