

#include <iostream>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<WinSock2.h>
#include<WS2tcpip.h>
#include <regex>
#include<string.h>


#pragma comment(lib,"ws2_32")
using namespace std;

bool checkDomain(string doMain) {
	if (std::regex_match(doMain, std::regex("(\\.*|[a-zA-Z0-9-]*)*"))) {
		
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	//khoi tao thu vien
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	addrinfo* info;
	sockaddr_in addr;
	string doMain;
	
	while (true)
	{
		cin>>(doMain);

		// chuyen doi tu string sang char*
		char const* domain = doMain.c_str();
		if (checkDomain) {
			int ret = getaddrinfo(domain, "http",NULL, &info);
			//neu thanh cong tra ve 0
			if (ret == 0) {
				memcpy(&addr, info->ai_addr, info->ai_addrlen);
				printf("phan giai ten mien thanh cong\n");
				printf("Dia chi IP:%s\n", inet_ntoa(addr.sin_addr));
			}
			else {
				printf("khong phan giai duoc ten mien");
			}
		}
	}
	



	
		
}

