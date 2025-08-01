#pragma once

#define DBGPRINT(ptr) \
 printf("Bytes at " #ptr ":\n\t"); \
  for (size_t i = 0; i < 64; ++i) { \
    printf("%02X ", ((unsigned char*)(ptr))[i]); \
  } \
  printf("\n");
