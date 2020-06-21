/* Titan Protect Gameguard System
 * Escrito por Celso Inácio
 * celso@portaltitan.net, celsoinacio_@hotmail.com	
 * http://portaltitan.net
 *
 * Se um dia ler esta linha e não for propietário do código, faça bom uso dele.
 * Use com sabedoria!
*/
#include "stdafx.h"
#include "Searching.h"	 
HWND searchhwnd;
int Kill;
POINT point;
int x;
char a[250];
char BUFFER[255];
void Log(const char* Log)
{
	         FILE* file = NULL;
	         fopen_s(&file, "TitanLog.txt", "a");
			 fprintf_s(file,Log);
	         fclose(file);
}
void HeuristicaCrash()
{
	//MessageBoxA(NULL, "Hack detectado, abortando.\n", "Titan Protect", MB_ICONSTOP);
	//Sleep(2000);
	ExitProcess(0);
	ExitThread(0);
}
Search szString[] =  
{	
{"Cheat"}, 
	{"AutoIt"}, 
	{"Shotbot"},
	{"Olly"},
	{"Hack"},
	{"Aimfix"},
	{"SetFSB"},
	{"FSB"},
	{"Front Side Bus"},
	{"Engine"},
	{"Injector"},
	{"Injetor"},
	{"InjeX"},
	{"SetFSB"},
	{"FSB"},
	{"CPUCooL"},
	{"PowerStrip"},
	{"HideToolz"},
	{"MmViewer"},
	{"Memory Viewer"},
	{"Debugger"},
	{"Debug"},
	{"window title changer"},
	{"Underclock"},
	{"AnVir"}
    };


void Searching() {
for (int countery = 0 ;countery < sizeof(a); countery++)
{
		for ( int counterx = 0 ; counterx < sizeof(a) ; counterx++)
		{
			point.x = counterx * 20;
			point.y = countery * 20;
			searchhwnd = WindowFromPoint(point);
			GetWindowTextA( searchhwnd , a , 250);
			for(x = 0; x < (sizeof(szString) / sizeof(Search)); x++) {
				if (strstr(a, szString[x].Palavras))
				{
				       CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&HeuristicaCrash, NULL, 0, NULL);
					   sprintf(BUFFER, "Hack \"%s\" detectado, abortando. Thread Heuristica \n", szString[x].Palavras);
					   Log(BUFFER);
					   MessageBoxA(0, BUFFER, "Titan Protect", MB_ICONSTOP);
					   return;
			}}}
}
}
