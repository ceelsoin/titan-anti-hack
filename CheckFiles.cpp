/* Titan Protect Gameguard System
 * Escrito por Celso Inácio
 * celso@portaltitan.net, celsoinacio_@hotmail.com	
 * http://portaltitan.net
 *
 * Se um dia ler esta linha e não for propietário do código, faça bom uso dele.
 * Use com sabedoria!
*/
#include "stdafx.h"
#include "MD5Wrapper.h"
#pragma warning( disable : 4996 4102 )

using namespace std;

int FileCount(const char *szDir, bool bCountHidden = false)
{
        char path[MAX_PATH];
        WIN32_FIND_DATA fd;
        DWORD dwAttr = FILE_ATTRIBUTE_DIRECTORY;
        if( !bCountHidden) dwAttr |= FILE_ATTRIBUTE_HIDDEN;
		sprintf( path, "%s\\*.HGZ", szDir);
        HANDLE hFind = FindFirstFile( path, &fd);
                int count = 0;
                do
                {
                        if( !(fd.dwFileAttributes & dwAttr))
                        {
                                puts( fd.cFileName);
                                string lol = fd.cFileName;
                                if(lol.find(".HGZ") != std::string::npos){
                                        count++;
                                }
                        }
                } while( FindNextFile( hFind, &fd));
                FindClose( hFind);
                return count;
}
void CheckFiles()
{
	md5wrapper md5;	

		 if(stricmp(md5.getHashFromFile("System.HGZ").c_str(),  "4FF079DD7C603ECE1F5B0FBC3B7B5095"))
			{
				//Edite os MD5 que desejar aqui  \/
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Hackativo, NULL, 0, NULL);
	    MessageBoxA(0, "Foram corrompidos arquivos do jogo, por favor reinstale para jogar.\n", "Titan Protect", MB_ICONSTOP);	 
		Log("[Anti-Hack] Houve um erro ao iniciar o jogo, desinstale-o e tente novamente.\n");
		return;
            }
		 if(stricmp(md5.getHashFromFile("Update1.HGZ").c_str(),  "3D89C17A4E5CDDB296F87F034CD60C0B"))
			{
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Hackativo, NULL, 0, NULL);
	    MessageBoxA(0, "Foram corrompidos arquivos do jogo, por favor reinstale para jogar.\n", "Titan Protect", MB_ICONSTOP);	 
		Log("[Anti-Hack] Houve um erro ao iniciar o jogo, desinstale-o e tente novamente.\n");
		return;
            }
		
	if(FileCount("./",false) != 4) 
		 {
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Hackativo, NULL, 0, NULL);
	    MessageBoxA(0, "Foram corrompidos arquivos do jogo, por favor reinstale para jogar.\n", "Titan Protect", MB_ICONSTOP);	 
		Log("[Anti-Hack] Arquivo ilegal encontrado na pasta.\n");
		return;		  
}
}