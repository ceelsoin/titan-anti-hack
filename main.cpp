/* Titan Protect Gameguard System
 * Escrito por Celso In�cio
 * celso@portaltitan.net, celsoinacio_@hotmail.com	
 * http://portaltitan.net
 *
 * Se um dia ler esta linha e n�o for propiet�rio do c�digo, fa�a bom uso dele.
 * Use com sabedoria!
*/
#include "stdafx.h"
#include "Searching.h"
#include "Dumping.h"
#include "SearchWindow.h"
#include "MemoryEdit.h"
#include "AntiInjection.h"
#include "AntiSB.h"
#include "CheckFiles.h"
#include "Splash.h"

//Fim imports curl

void ZChatOutput( char* szMessage ){
	((void(*)( char*, int, int, int ))0x42B860)( szMessage, 1, 0, -1 );
}

DWORD ZGetGame(){
	return ((DWORD(*)())0x4AD880)();
}

char* GetResponseFromURL( unsigned long* dwRecvCount, char* szURL, ... )
{
	HINTERNET hUrl, hSession;
	unsigned long dwRecv;
	char szFinalURL[512];
	char* szBuffer = new char[512];
    memset( szBuffer, 0, 512 );
	va_list va_alist;
	va_start( va_alist, szURL );
	vsprintf_s( szFinalURL, 512, szURL, va_alist );
	va_end( va_alist );
	hSession = InternetOpenA( "Microsoft Internet Explorer", INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0 );
	if( !hSession )
		return szBuffer;
	hUrl = InternetOpenUrlA( hSession, szFinalURL, 0, 0, 0, 0 );
	if( !hUrl )
		return szBuffer;
	InternetReadFile( hUrl,	szBuffer, 512, &dwRecv );
	InternetCloseHandle( hSession );
	InternetCloseHandle( hUrl );
	if( !dwRecv )
		return szBuffer;
	if( dwRecvCount )
		*dwRecvCount = dwRecv;
	return szBuffer;
}

void Hackativo()
{
	//MessageBoxA(0, "Hack detectado, abortando.\n", "Titan Protect", MB_ICONSTOP);
	//Sleep(2000);
	ExitProcess(0);
	ExitThread(0);
}

DWORD WINAPI MemoryScan ()
{

    PBYTE lpMemory = new byte[0x005E5DDC - 0x00401000];
    memcpy (lpMemory, (LPVOID)0x00401000, 0x005E5DDC-0x00401000);


    while (true)
    {
        if (memcmp (lpMemory, (LPVOID)0x00401000,0x5E5DDC-0x00401000))
        {
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Hackativo, NULL, 0, NULL);
	    MessageBoxA(0, "Hack detectado, abortando.\n", "Titan Protect", MB_ICONSTOP);	 //Programa suspeito est� aberto, feche para jogar.
		Log("[Anti-Hack] Programa suspeito est� aberto, feche para jogar. Thread 'HackAtivo'\n");
		return true;
        }

        Sleep(5000);
    }
    return 0;
}


void CheckDump() 
{
       if(MCheckDump() != NULL) {
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Hackativo, NULL, 0, NULL);
	    //MessageBoxA(NULL, "Hack detectado, abortando.\n", "Titan Protect", MB_ICONSTOP);	 //Programa suspeito est� aberto, feche para jogar.
		//Log("[Anti-Hack] Programa suspeito est� aberto, feche para jogar.\n");
		return;
		}
}


void PrimeiroShot()
{
	//ShellExecute(NULL, "open", "C:\\Windows\\win64def.exe", "", NULL, SW_HIDE); 
	//ShellExecute(NULL, "open", "http://google.com", "", NULL, SW_SHOW); 
}
void Hooks()
{
	again:
		Searching();    //Pega classes do hack
		CheckDump();    //Checa por dump de memoria do processo
	    LockWindow();   //Pega por titulo da janela
		MemoryEdit(); //Bloqueia edi��o de memoria
		AntiInject();   //Bloqueia inje��o de memoria
		CheckFiles(); //Checa hashs md5
        Sleep(5000);    
	goto again;
}
 


void HideModule(HINSTANCE hModule)
{
        DWORD dwPEB_LDR_DATA = 0;
        _asm
        {
        pushad;
        pushfd;
        mov eax, fs:[30h];
        mov eax, [eax+0Ch];
        mov dwPEB_LDR_DATA, eax;
        mov esi, [eax+0Ch];
        mov edx, [eax+10h];
        LoopInLoadOrderModuleList:
                lodsd;
                mov esi, eax;
                mov ecx, [eax+18h];
                cmp ecx, hModule;
                jne SkipA
                mov ebx, [eax]
                mov ecx, [eax+4]
                mov [ecx], ebx
                mov [ebx+4], ecx
                jmp InMemoryOrderModuleList
        SkipA:
                cmp edx, esi
                jne LoopInLoadOrderModuleList
InMemoryOrderModuleList:
        mov eax, dwPEB_LDR_DATA
        mov esi, [eax+14h]
        mov edx, [eax+18h]
        LoopInMemoryOrderModuleList:
                lodsd
                mov esi, eax
                mov ecx, [eax+10h]
                cmp ecx, hModule
                jne SkipB
                mov ebx, [eax]
                mov ecx, [eax+4]
                mov [ecx], ebx
                mov [ebx+4], ecx
                jmp InInitializationOrderModuleList
        SkipB:
                cmp edx, esi
                jne LoopInMemoryOrderModuleList
InInitializationOrderModuleList:
        mov eax, dwPEB_LDR_DATA
        mov esi, [eax+1Ch]
        mov edx, [eax+20h]
        LoopInInitializationOrderModuleList:
                lodsd
                mov esi, eax      
                mov ecx, [eax+08h]
                cmp ecx, hModule      
                jne SkipC
                mov ebx, [eax]
                mov ecx, [eax+4]
                mov [ecx], ebx
                mov [ebx+4], ecx
                jmp Finished
        SkipC:
                cmp edx, esi
                jne LoopInInitializationOrderModuleList
        Finished:
                popfd;
                popad;
        }
}

/*
extern "C" __declspec(dllexport) void Escuddo() {
	again:
	    Searching();
		CheckDump();
	    LockWindow();
		MemoryEdit();
		AntiInject();
		CheckFiles();
		AntiShotbotLogger();
		Sleep(5000);
		goto again;
	
	}

BOOL WINAPI DllMain (HMODULE hModule, DWORD run, LPVOID lpReserved)
{
	DisableThreadLibraryCalls (hModule);
	HideModule(hModule);
  if (run == DLL_PROCESS_ATTACH) {
	            Hooks()
                CreateThread( 0, 0, (LPTHREAD_START_ROUTINE)&Escuddo, 0, 0, 0 );
					  	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&MemoryScan, NULL, 0, NULL);
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)&AntiShotbotLogger,NULL,0,NULL);

				

	}
	return TRUE;
}   */                                                                            



extern "C"
    {
        __declspec(dllexport) BOOL __stdcall DllMain(HMODULE hInst,DWORD reason,LPVOID lpv)
        {
            DisableThreadLibraryCalls(hInst);
			HideModule(hInst);
			//MySecondForm ^ form = gcnew MySecondForm;
			//telaInicio ^ form = gcnew telaInicio;
			//form->ShowDialog();

			

            if (reason == DLL_PROCESS_ATTACH)
            {
				//CSplash splash1(MAKEINTRESOURCE(Splash), RGB(128, 128, 128));
				CSplash splash1(TEXT(".\\gameguard\\Splash.bmp"), RGB(128, 128, 128));
				splash1.ShowSplash();
				//your start up code here
				Sleep(20000); //simulate using a 5 second delay
				//Close the splash screen

				splash1.CloseSplash();
				
				//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Hooks, NULL, 0, NULL);

				//Sleep(900000); //15 minutos
				//Sleep(180000); //3 Minutos

				//Criar um timer pra executar isso dps de 15 minutos
				//Ou ent�o fazer o pr�prio programa fazer o print depois de 15 minutos.
				
				
				//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&MemoryScan, NULL, 0, NULL); //Fun��o com bug
				//CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)&AntiShotbotLogger,NULL,0,NULL); //Fun��o apenas para gunz
			}
			return true;
           
        }
    } 		  