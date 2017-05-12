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



void SingleMode()
{
	system("cls");
	srand(time(NULL));
	TempClub club(rand(),0,0);

	{
		strstream ss,hh;
		string w,h;
		ss << WidthOfWindow/2+10;
		ss >> w;
		hh << HeightOfWindow;
		hh >> h;
		string mode;mode="mode con cols="+w+" lines="+h;
		const char * mode_p=mode.data();
		system(mode_p);
	}
	DrawPad(FALSE);
	int a=rand()%19+1;
	NextClubRefresh(a);
	ScoreFresh(0);
	continue_choosed=3;
	while(TRUE)
	{
		for(int n=1;n<=(fps/100);++n)
		{
			Sleep(50);
			if(KEYDOWN(VK_LEFT))				{club.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_RIGHT))				{club.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_UP))					{club.Rotation();Sleep(50);}
			if(KEYDOWN(VK_DOWN))				{n+=8;}
		}
		if(club.isMoveable()==0)				{club.refresh(a,0);if((continue_choosed==0)||(continue_choosed==1)){break;}a=rand()%19+1;NextClubRefresh(a);}
		if(isFull(0)==1)						{deleteLine(0);ScoreFresh(0);}
		club.MoveDown();
	}
}
