#pragma once

bool attachDLLs();
void freeDLLs();

typedef struct DLLHandle {
	HMODULE moduleHandle;
} DLLHandle;

extern DLLHandle * loadedDLLs;
extern size_t loadedDLLCount;

