#include"settings.h"
#include"classes.h"
#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include<strstream>
#include<conio.h>
#include<time.h>665321

void BattleMode()
{
	system("cls");
	srand(time(NULL));
	DrawPad(TRUE);
	AttackOfPlayer0=0;
	AttackOfPlayer1=0;
	TempClub club0(rand()%19+1,0,0);
	TempClub club1(rand()%19+1,1,1);
	int a=rand()%19+1;
	int b=rand()%19+1;
	int flag0=0,flag1=0;
	NextClubRefresh(a);
	NextClubRefresh(b,1);
	ScoreFresh(1);
	continue_choosed=3;
	AttackFresh(0);
	AttackFresh(1);
GamePlay:
	while(TRUE)
	{
		for(int n=1;n<=(fps/100);++n)
		{
			Sleep(50);
			if(KEYDOWN(VK_A))								{club0.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_LEFT) )							{club1.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_D))								{club0.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_RIGHT))							{club1.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_W))								{club0.Rotation();Sleep(50);}
			if(KEYDOWN(VK_UP))								{club1.Rotation();Sleep(50);}
			if(KEYDOWN(VK_DOWN) || KEYDOWN(VK_S))			{n+=8;}
			if(KEYDOWN(VK_SPACE) && AttackOfPlayer0>0 )		{AttackOfPlayer0--;AttackFresh(0);SetCursor(2,15);cout<<"Attack";Sleep(50);goto AAttackB;}
			if(KEYDOWN(VK_NUMPAD0) && AttackOfPlayer1>0 )	{AttackOfPlayer1--;AttackFresh(1);SetCursor(55,15);cout<<"Attack";Sleep(50);goto BAttackA;}
		}
		if(club0.isMoveable()==0)							{club0.refresh(a,1);if((continue_choosed==0)||(continue_choosed==1)){break;}a=rand()%19+1;NextClubRefresh(a,0);}
		if(club1.isMoveable()==0)							{club1.refresh(b,1);if((continue_choosed==0)||(continue_choosed==1)){break;}b=rand()%19+1;NextClubRefresh(b,1);}
		if(isFull(0)==1)									{AttackOfPlayer0 +=deleteLine(0);AttackFresh(0);AttackFresh(1);ScoreFresh(0);}
		if(isFull(1)==1)									{AttackOfPlayer1 +=deleteLine(1);AttackFresh(1);AttackFresh(1);ScoreFresh(1);}
		club0.MoveDown();
		club1.MoveDown();
	}
	goto END;

AAttackB:
	flag0=0,flag1=0;
	while(TRUE)
	{
		for(int n=1;n<=(fps/100);++n)
		{
			Sleep(50);
			if(KEYDOWN(VK_A))								{club0.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_LEFT) )							{club1.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_D))								{club0.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_RIGHT))							{club1.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_W))								{club0.Rotation();Sleep(50);}
			if(KEYDOWN(VK_UP))								{club1.Rotation();Sleep(50);}
			if(KEYDOWN(VK_DOWN) || KEYDOWN(VK_S))			{n+=8;}
			if(KEYDOWN(VK_SPACE))							{SetCursor(2,15);cout<<"      ";AttackOfPlayer0++;AttackFresh(0);Sleep(50);goto GamePlay;}
		}
		if(club0.isMoveable()==0&&flag0==0)					{flag0=1;for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)playground[club0.X+n][club0.Y+m]=(club0.ClubType[n][m] || playground[club0.X+n][club0.Y+m]);}
		if(club1.isMoveable()==0&&flag1==0)					{flag1=1;for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)playground[club1.X+n][club1.Y+m]=(club1.ClubType[n][m] || playground[club1.X+n+50][club1.Y+m]);}
		if(isFull(0)==1)									{AttackOfPlayer0+=deleteLine(0);AttackFresh(0);ScoreFresh(1);}
		if(isFull(1)==1)									{AttackOfPlayer1+=deleteLine(1);AttackFresh(1);ScoreFresh(1);}
		club0.MoveDown();
		club1.MoveDown();
		if(club0.isMoveable()==0&&club1.isMoveable()==0)break;
	}
	club1.fresh(rand()%19+1);
	while(TRUE)
	{
		for(int n=1;n<=(fps/100);++n)
		{
			Sleep(50);
			if(KEYDOWN(VK_A) )								{club1.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_D))								{club1.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_W))								{club1.Rotation();Sleep(50);}
			if(KEYDOWN(VK_S))								{n+=8;}
		}	
		club1.MoveDown();
	if(club1.isMoveable()==0)								{for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)playground[club1.X+n][club1.Y+m]=(club1.ClubType[n][m] || playground[club1.X+n][club1.Y+m]);break;}
	}
	if(isFull(1)==1)										{deleteLine(1);}
	club0.fresh(a);
	a=rand()%19+1;
	NextClubRefresh(a,0);
	club1.fresh(b);
	b=rand()%19+1;
	NextClubRefresh(b,1);
	SetCursor(2,15);cout<<"      ";
	goto GamePlay;

BAttackA:
	flag0=0,flag1=0;
	while(TRUE)
	{
		for(int n=1;n<=(fps/100);++n)
		{
			Sleep(50);
			if(KEYDOWN(VK_A))								{club0.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_LEFT) )							{club1.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_D))								{club0.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_RIGHT))							{club1.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_W))								{club0.Rotation();Sleep(50);}
			if(KEYDOWN(VK_UP))								{club1.Rotation();Sleep(50);}
			if(KEYDOWN(VK_DOWN) || KEYDOWN(VK_S))			{n+=8;}
			if(KEYDOWN(VK_NUMPAD0))							{SetCursor(55,15);cout<<"      ";AttackOfPlayer1++;AttackFresh(1);Sleep(50);goto GamePlay;}
		}
		if(club0.isMoveable()==0&&flag0==0)					{flag0=1;for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)playground[club0.X+n][club0.Y+m]=(club0.ClubType[n][m] || playground[club0.X+n][club0.Y+m]);}
		if(club1.isMoveable()==0&&flag1==0)					{flag1=1;for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)playground[club1.X+n][club1.Y+m]=(club1.ClubType[n][m] || playground[club1.X+n+50][club1.Y+m]);}
		if(isFull(0)==1)									{AttackOfPlayer0+=deleteLine(0);AttackFresh(0);ScoreFresh(1);}
		if(isFull(1)==1)									{AttackOfPlayer1+=deleteLine(1);AttackFresh(1);ScoreFresh(1);}
		club0.MoveDown();
		club1.MoveDown();
		if(club0.isMoveable()==0&&club1.isMoveable()==0)break;
	}
	club0.fresh(rand()%19+1);
	while(TRUE)
	{
		for(int n=1;n<=(fps/100);++n)
		{
			Sleep(50);
			if(KEYDOWN(VK_LEFT) )								{club0.MoveLeft();Sleep(50);}
			if(KEYDOWN(VK_RIGHT))								{club0.MoveRight();Sleep(50);}
			if(KEYDOWN(VK_UP))									{club0.Rotation();Sleep(50);}
			if(KEYDOWN(VK_DOWN))								{n+=8;}
		}	
		club0.MoveDown();
	if(club0.isMoveable()==0)								{for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)playground[club0.X+n][club0.Y+m]=(club0.ClubType[n][m] || playground[club0.X+n][club0.Y+m]);break;}
	}
	if(isFull(1)==1)										{deleteLine(1);}
	club0.fresh(a);
	a=rand()%19+1;
	NextClubRefresh(a,0);
	club1.fresh(b);
	b=rand()%19+1;
	NextClubRefresh(b,1);
	SetCursor(55,15);cout<<"      ";
	goto GamePlay;
	
END:;
}