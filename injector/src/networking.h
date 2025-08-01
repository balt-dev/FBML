#pragma once
#include <stdint.h>

typedef int NetworkErrorCode;

extern bool networkInit;
NetworkErrorCode initNetworking();
NetworkErrorCode sendRawData(const char* data, size_t len);
NetworkErrorCode recvRawData(char* outBuf, size_t outLen, size_t * sentLen);
NetworkErrorCode recvAllRawData(char* outBuf, size_t outLen);
