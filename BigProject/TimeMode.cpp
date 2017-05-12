#include"settings.h"
#include"classes.h"
#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include<strstream>
#include<conio.h>
#include<time.h>

void TimeMode()
{
	system("cls");
	srand(time(NULL));
	DrawPad(TRUE);
	SetCursor(2,6);cout<<"       ";
	SetCursor(55,6);cout<<"       ";
	TempClub club0(rand(),0,0);
	TempClub club1(rand(),1,1);
	int a=rand()%19+1;
	int b=rand()%19+1;
	NextClubRefresh(a);
	NextClubRefresh(b,1);
	ScoreFresh(0);
	continue_choosed=3;
	while(TRUE)
	{
		for(int n=1;n<=(fps/100);++n)
		{
			Sleep(50);
			if(KEYDOWN(VK_A))						{club0.MoveLeft();}
			if(KEYDOWN(VK_LEFT) )					{club1.MoveLeft();}
			if(KEYDOWN(VK_D))						{club0.MoveRight();}
			if(KEYDOWN(VK_RIGHT))					{club1.MoveRight();}
			if(KEYDOWN(VK_W))						{club0.Rotation();Sleep(50);}
			if(KEYDOWN(VK_UP))						{club1.Rotation();Sleep(50);}
			if(KEYDOWN(VK_DOWN) || KEYDOWN(VK_S))	{n+=8;}
		}
		if(club0.isMoveable()==0)					{club0.refresh(a,1);if((continue_choosed==0)||(continue_choosed==1)){break;}a=rand()%19+1;NextClubRefresh(a,0);}
		if(club1.isMoveable()==0)					{club1.refresh(b,1);if((continue_choosed==0)||(continue_choosed==1)){break;}b=rand()%19+1;NextClubRefresh(b,1);}
		if(isFull(0)==1)							{deleteLine(0);ScoreFresh(1);}
		if(isFull(1)==1)							{deleteLine(1);ScoreFresh(1);}
		club0.MoveDown();
		club1.MoveDown();
	}
}