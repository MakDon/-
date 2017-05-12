#include"settings.h"
#include"classes.h"
#include"clubs.h"
#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include<strstream>
#include<conio.h>
#include<vector>
#include<time.h>
using namespace std;


int main()
{
	int mode;
	MSG msg = {0};
    HWND hConsole = GetActiveWindow(); 
    RegisterHotKey(hConsole,1,MOD_NOREPEAT,VK_ESCAPE);
StartARound:
	initialize();
	PrintTitle();
	mode=2;
	mode=SelectMode();
	system("cls");
	switch(mode)
	{
		case 0:SingleMode();break;
		case 10:TimeMode();break;
		case 11:BattleMode();break;
	}
	if(continue_choosed==1)goto StartARound;
	return 0;
}