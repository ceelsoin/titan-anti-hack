#include <WinSock.h>
#include <WinInet.h>
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <Psapi.h>
#include <string>
#include <string.h>
#include <TlHelp32.h>
#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "Wininet.lib")


using namespace std;

void ProgramaIlegalActive();
void Log(const char* Log);
void Hackativo();