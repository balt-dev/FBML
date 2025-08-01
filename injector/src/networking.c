#pragma comment(lib, "ws2_32.lib")

#include "networking.h"
#include <winsock2.h>
#include <stdbool.h>
#include <stdio.h>

#define ERR(step) { int errcode = WSAGetLastError(); printf("Failed while " step ".\nError code: %d\n", errcode); return errcode; }
#define ERRC(step, code) { int errcode = code; printf("Failed while " step ".\nError code: %d\n", errcode); return errcode; }

struct sockaddr_in server;
SOCKET s;

bool networkInit = false;

int initNetworking() {
	networkInit = false;
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
		ERR("initializing winsock");

	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		ERR("initializing socket");

	server.sin_addr.s_addr = inet_addr("127.0.0.1"); // TODO: Replace with configured IP
	server.sin_family = AF_INET;
	server.sin_port = htons( 20000 );

	int code = connect(s, (struct sockaddr *) &server, sizeof(server));
	if (code < 0) ERRC("connecting to server", code);

	printf("Connected to server!\n");
	networkInit = true;
	return 0;
}

int sendRawData(const char* data, size_t len) {
	if (!networkInit) return -1;
	int code = send(s, data, len, 0);
	if (code < 0) ERRC("sending data", code);
	return 0;
}

int recvRawData(char* outBuf, size_t outLen, size_t * sentLen) {
	if (!networkInit) return -1;
	*sentLen += recv(s, outBuf, outLen , 0);
	if (*sentLen == SOCKET_ERROR) ERRC("recieving data", -1);
	return 0;
}

int recvAllRawData(char* outBuf, size_t outLen) {
	if (!networkInit) return -1;
	size_t cur = 0;
	int ret;
	while (cur < outLen) {
		ret = recvRawData(outBuf + cur, outLen - cur, &cur);
		if (ret != 0) return ret;
	}
	return 0;
}

void cleanup() {
	networkInit = false;
	closesocket(s);
	WSACleanup();
}
