/* Titan Protect Gameguard System
 * Escrito por Celso Inácio
 * celso@portaltitan.net, celsoinacio_@hotmail.com	
 * http://portaltitan.net
 *
 * Se um dia ler esta linha e não for propietário do código, faça bom uso dele.
 * Use com sabedoria!
*/
#include <Windows.h>
#include "stdafx.h"
bool Wallhack()
{	
	if( *(WORD*)0x00502E43  != 0x3289|| *(WORD*)0x40C81E != 0x3289 )
	{
	return true;
	}else{
    return false;
	}
}
bool IsNameESPActive()
{

    if( *(DWORD*)0x403209 != 0xCC0004C2 ||*(WORD*)0x40A322 != 0xCF8B || *(WORD*)0x40A31F != 0x08EB || *(WORD*)0x40A329 != 0x9F8D)
		{
	return true;
	}else{
    return false;
	}
}
bool Respawn()
{ 
	
   if( *(WORD*)0x4B40BE != 0x05EB ) // respawn
	{
	return true;
	}else{
    return false;
	}
}
bool Ninja()
{
	if( *(WORD*)0x485D0B != 0x840F ) // ninja
	{
	return true;
	}else{
    return false;
	}
}
bool Defense()
{
	if( *(WORD*)0x484822 != 0xC1F6 ) // inifiniteblock
	{
	return true;
	}else{
    return false;
	}
}
bool InfinitJump()
{
	if( *(WORD*)0x485F8A != 0x840F ) // infinity jump
	{
	return true;
	}else{
    return false;
	}
}
bool enemyview()
{ 
	
    if( *(WORD*)0x4106CC != 0xE674 || *(WORD*)0x4106DE != 0xD474 ) // enemy view points
	{
	return true;
	}else{
    return false;
	}
}
bool RLPocket()
{ 
	
   if( *(WORD*)0x4A1C22 != 0x850F ) // rl rocket
	{
	return true;
	}else{
    return false;
	}
}
		
bool NameKorean()
{ 
	
   if(*(WORD*)0x44D51B != 0x4F75)
   {
	return true;
	}else{
    return false;
	}
}
bool ZAntiSpam()
{ 
	
   if(*(WORD*)0x42B04D != 0x1372)
	{
	return true;
	}else{
    return false;
	}
}
bool ZUc()
{
	if( *(unsigned long*)QueryPerformanceCounter != 2337669003 ){
	return true;
	}else{
	return false;
	}
}

void Memory()
{
	Sleep(5000);
	ExitProcess(0);
	ExitThread(0);
}

void Msg(char * szMsg)
{
	    char bufaf[50];
		ShowWindow(FindWindowA(0, "The Duel"), SW_MINIMIZE);
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Memory, NULL, 0, NULL);
		HWND Active;
		sprintf(bufaf, "[Anti-Hack] %s foi detectado, seu jogo será crashado em instantes.", szMsg);
	    MessageBoxA(0, bufaf, "Factory Gaming Guard", MB_ICONSTOP);
		return;
}
void MemoryEdit()
{
	if(Wallhack()) {
	Msg("WallHack");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(IsNameESPActive()) {
	Msg("Name ESP");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(Respawn()) {
	Msg("Respawn");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(Ninja())
	{
	Msg("Ninja Hack");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(Defense())
	{
	Msg("Infinite Block");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(InfinitJump())
	{
	Msg("Infinite Jump");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	if(enemyview())
	{
	Msg("Enemy View");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(RLPocket())
	{
	Msg("RL Rocket");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(NameKorean())
	{
	Msg("Name Hack");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(ZAntiSpam())
	{
	Msg("Flood");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
	if(ZUc()) {
	Msg("Underclock");
	Log("Edições na memória encontradas, seu jogo foi crashado.\n");
	}
}
}