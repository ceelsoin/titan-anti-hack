/* Titan Protect Gameguard System
 * Escrito por Celso In�cio
 * celso@portaltitan.net, celsoinacio_@hotmail.com	
 * http://portaltitan.net
 *
 * Se um dia ler esta linha e n�o for propiet�rio do c�digo, fa�a bom uso dele.
 * Use com sabedoria!
*/
#include "stdafx.h"
#include "AntiInjection.h"

void Injetou()
{
	MessageBoxA(0, "Hack detectado, abortando. Thread injetou \n", "Titan Protect", MB_ICONSTOP);
	//Sleep(5000);
	Log("[Anti-Hack] Injecao de DLL's encontrado, o jogo foi crashado! Thread Injetou \n");

	ExitProcess(0);
	ExitThread(0);
}


DWORD g_dwLoadLibraryAJMP;

DWORD WINAPI jumphook( DWORD AddressToPerformJump, DWORD AddressOfMyFunction, DWORD LenghOfTheAreaToPerformTheJump	)
{
	if( LenghOfTheAreaToPerformTheJump < 5 )
		return 0;

	DWORD RelativeJump, 
		  NextInstructionAddress,
		  Flag;

	if ( ! VirtualProtect((LPVOID)AddressToPerformJump, LenghOfTheAreaToPerformTheJump, PAGE_EXECUTE_READWRITE, &Flag) )
		return 0;

	NextInstructionAddress = AddressToPerformJump + LenghOfTheAreaToPerformTheJump;

	*(BYTE*)AddressToPerformJump = 0xE9;

	for( DWORD i = 5; i < LenghOfTheAreaToPerformTheJump; i++)
		*(BYTE*)(AddressToPerformJump+i) = 0x90;

	RelativeJump = AddressOfMyFunction - AddressToPerformJump - 0x5;

	*(DWORD*)(AddressToPerformJump + 0x1) = RelativeJump;

	VirtualProtect((LPVOID)AddressToPerformJump, LenghOfTheAreaToPerformTheJump, Flag, &Flag);

	return NextInstructionAddress; 
}


HMODULE WINAPI hLoadLibraryA( LPCSTR lpLibFileName )
{	
	__asm
	{
		mov eax, dword ptr ss:[esp + 0x18]
		cmp dword ptr ds:[eax-0x12], 0x8B55FF8B
		je erro
	}
	

	if( lpLibFileName )
	{
		if( !strcmp( lpLibFileName, "twain_32.dll" ) )
			__asm jmp g_dwLoadLibraryAJMP
	}			

	return LoadLibraryExA( lpLibFileName, 0, 0 );

erro:



	                   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Injetou, NULL, 0, NULL);
					   //MessageBoxA(0, "Hack detectado, abortando.", "Titan Protect", MB_ICONSTOP);// Inje��o de DLL's detectado! Seu jogo ser� fechado.
					   //Log("[Anti-Hack] Inje��o de DLL's encontrado, o jogo foi crashado!\n");
					   return 0;
}

void AntiInject()
{
	g_dwLoadLibraryAJMP = (DWORD)GetModuleHandle( "kernel32" ) + 0x6E2A1;

	jumphook( (DWORD)LoadLibraryA, (DWORD)&hLoadLibraryA, 57 );
}