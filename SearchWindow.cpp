/* Titan Protect Gameguard System
 * Escrito por Celso Inácio
 * celso@portaltitan.net, celsoinacio_@hotmail.com	
 * http://portaltitan.net
 *
 * Se um dia ler esta linha e não for propietário do código, faça bom uso dele.
 * Use com sabedoria!
*/
#include "stdafx.h"
#include "SearchWindow.h"

char BUFFER1[255];
void FindAtivo()
{
	//MessageBoxA(NULL, "Hack detectado, abortando.\n", "Titan Protect", MB_ICONSTOP);
	//Sleep(2000);
	ExitProcess(0);
	ExitThread(0);
}

void SearchWindow(char* classe, char * window)
{
	for(int x = 0; x < sizeof(window) / sizeof(classe); x++) {
		if(FindWindowA(classe, window) != NULL) {
			if(classe) {
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&FindAtivo, NULL, 0, NULL);
			sprintf(BUFFER1, "[Anti-Hack] Hack \"%s\" detectado, abortando. Thread FindAtivo\n", classe);
			Log(BUFFER1);
			MessageBoxA(0, BUFFER1, "Titan Protect", MB_ICONSTOP);
			return;
			}else{
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&FindAtivo, NULL, 0, NULL);
			sprintf(BUFFER1, "[Anti-Hack] Hack \"%s\" detectado, abortando. Thread FindAtivo \n", window);
			Log(BUFFER1);
			MessageBoxA(0, BUFFER1, "Titan Protect", MB_ICONSTOP);
			return;
			}
		}
	}
}


void LockWindow()
{
        SearchWindow(0, "Cheat Engine 6.1");
        SearchWindow( "OLLYDBG", 0 );
		SearchWindow( 0, "Cheat Engine 3.2" );
		SearchWindow( 0, "Cheat Engine 3.6" );
		SearchWindow( 0, "Cheat Engine 6.0" );
		SearchWindow( 0, "Cheat Engine 5.5" ); 
		SearchWindow( 0, "Cheat Engine 5.6" );
		SearchWindow( 0, "Cheat Engine 5.6.1" );
		SearchWindow( "Cheat Engine 6.0", 0 );
		SearchWindow( "Cheat Engine 5.5", 0 );
		SearchWindow( "Cheat Engine 5.6", 0 );
		SearchWindow( "Cheat Engine 5.6.1", 0 );
		SearchWindow( "Thunder Engine", 0 );
		SearchWindow( "Cheat", 0 );
		SearchWindow( "Hack", 0 );
		//SearchWindow( 0, "Conexão de Área de Trabalho Remota" },
		SearchWindow( 0, "HideToolz" );
		SearchWindow( 0, "SetFSB 2.2.134.98" );
		SearchWindow( 0, "SetFSB 2.3.157.122" );
		SearchWindow( 0, "SetFSB" );
		SearchWindow( "TMemoryBrowser", "Memory Viewer" );
		SearchWindow( "TMmBrowser", "MmViewer" );
		SearchWindow( 0, "MoonLight Engine" );
		SearchWindow( 0, "MoonLight Engine 1224.15 by IlvMoney A.K.A FaaF" );
		SearchWindow( 0, "Process List" );
		SearchWindow( 0, "Process watcher" );
		SearchWindow( 0, "Moon Light Engine settings" );
		SearchWindow( 0, "by IlvMoney A.K.A FaaF" );
		SearchWindow( 0, "SetFSB 2.3.153.118" );
		SearchWindow( 0, "SetFSB 2.3.153.119" );
		SearchWindow( 0, "SetFSB 2.3.154.120" );
		SearchWindow( 0, "SetFSB 2.3.155.121" );
		SearchWindow( 0, "SetFSB 2.2.134.98" );
		SearchWindow( 0, "SetFSB ID 1484484651" );
		SearchWindow( 0, "AMD OverDrive" );
		SearchWindow( 0, "CPU Burn-in v1.01" );
		SearchWindow( 0, "CPUCooL" );
		SearchWindow( 0, "ParetoLogic PC Health Advisor" );
		SearchWindow( 0, "SpeedswitchXP V1.52 - © 2002-2006 Christian Diefer" );
		SearchWindow( 0, "ATITool" );
		SearchWindow( 0, "A64Info-beta" );
		SearchWindow( 0, "PowerStrp" );
		SearchWindow( 0, "EasyTune5 Build 2007.09.21" );
		SearchWindow( 0, "EasyTune4 Build 2004.10.19" );
		//SearchWindow( 0, "AutoIt v3" );
		//SearchWindow( "AutoIt v3", 0 );
		//SearchWindow( "AutoIt v3", "AutoIt v3");
		SearchWindow( 0, "N-Jector By Noob" );
		SearchWindow( 0, "Winject" );
		SearchWindow( 0, "Elitehax" );
		SearchWindow( 0, "xh<xjkBXClxjdoxcXCLcmmcmcd`DÈ****33___$§24234dsdhrtghrtghrthÈ`WRWER`F");
		SearchWindow( 0, "SandBox");
		SearchWindow( 0, "Sand Box");
		SearchWindow( 0, "Sand");
		SearchWindow( 0, "Dup");
		SearchWindow( 0, "Dupe");
		SearchWindow( 0, "Duper");
		SearchWindow( 0, "AnVir");
		//TO DO: Adicionar warz all emulator, rondar foruns a procura de hacks novos na area.
}