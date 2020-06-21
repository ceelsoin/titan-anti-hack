/* Titan Protect Gameguard System
 * Escrito por Celso Inácio
 * celso@portaltitan.net, celsoinacio_@hotmail.com	
 * http://portaltitan.net
 *
 * Se um dia ler esta linha e não for propietário do código, faça bom uso dele.
 * Use com sabedoria!
*/
#include "stdafx.h"
HHOOK MouseHook;

LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		if(wParam == WM_RBUTTONDOWN || wParam == WM_LBUTTONDOWN)
		{
			MSLLHOOKSTRUCT *info=(MSLLHOOKSTRUCT*)lParam;     
			if((info->flags & LLMHF_INJECTED) == LLMHF_INJECTED)
			{
				ExitProcess(-1);
			}
		}
	}
	return CallNextHookEx(MouseHook,nCode,wParam,lParam);
}


void AntiShotbotLogger()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);

    MouseHook = SetWindowsHookEx( WH_MOUSE_LL, MouseHookProc, hInstance, NULL );
    MSG message;
    while (GetMessage(&message,NULL,0,0)) {
        TranslateMessage( &message );
        DispatchMessage( &message );
    }

    UnhookWindowsHookEx(MouseHook);
    return;
}