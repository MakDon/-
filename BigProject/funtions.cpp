#include"settings.h"
#include"classes.h"
#include"clubs.h"
#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include<strstream>
#include<conio.h>
#include<iomanip>

using namespace std;
int continue_choosed=3;
short int AttackOfPlayer0=0;
short int AttackOfPlayer1=0;
bool playground[100][50];

static int winner;

void initialize()
{
	winner=3;
	continue_choosed=3;
	for(int n=0;n<=99;++n)for(int m=0;m<=49;++m){playground[n][m]=0;}
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cci;
		GetConsoleCursorInfo(hOut,&cci);
		cci.bVisible=false;
		SetConsoleCursorInfo(hOut,&cci);
	}

	{
		strstream ss,hh;
		string w,h;
		ss << WidthOfWindow;
		ss >> w;
		hh << HeightOfWindow;
		hh >> h;
		string mode;mode="mode con cols="+w+" lines="+h;
		const char * mode_p=mode.data();
		system(mode_p);
	}
	system("title=俄罗斯方块·魔改版 for Windows");
	ScoreOfPlayer0=0;
	ScoreOfPlayer1=0;
	AttackOfPlayer0=0;
	AttackOfPlayer1=0;
}
void SetCursor(int x,int y)
{
	COORD coord;coord.X=x;coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void PrintTitle()
{
	Title title_of_game(TitleX,TitleY);
	title_of_game.SetPrintContinueOn();
	title_of_game.print();
	title_of_game.SetPrintContinueOff();
	/*cout<<"…………………………………◆……………………………◆……………………………………………………◆…………………………………………………◆…………………………………◆◆…………◆◆…………………\n"
		<<"…………………◆◆…………◆◆………………………◆◆……………◆◆◆◆◆◆◆…………◆◆……◆◆………………◆◆…………………………◆◆………………………………◆◆◆…………◆◆………………\n"
		<<"…………………◆◆………◆◆◆…………………………◆◆◆◆◆◆◆◆◆◆◆◆……………◆◆……◆◆…◆……◆◆◆◆…………………………◆◆◆………………………………◆◆…………◆◆………………\n"
		<<"………………◆◆◆……◆◆◆◆◆◆◆…………………◆◆…◆………◆……◆◆……………◆………◆……◆◆◆◆◆…………………………………◆◆………………………………◆……………◆…………………\n"
		<<"………………◆◆…◆◆◆◆◆◆…◆◆…………………◆……◆………◆……◆◆……………◆…◆◆◆◆◆◆◆◆………………………………………◆◆………………………………◆……………◆…………………\n"
		<<"……………◆◆◆◆◆◆◆……◆……◆…………………◆……◆……◆◆◆◆◆◆……◆◆◆◆◆◆◆◆◆◆◆◆……………………………………◆◆◆◆◆◆◆◆◆◆◆……………◆……………◆…◆◆◆◆……\n"
		<<"……………◆◆…◆……◆……◆…◆◆◆◆……………◆◆◆◆◆◆◆◆◆◆◆◆………◆◆◆………◆……◆◆…………◆………◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆……………◆……◆◆◆◆◆◆◆◆◆……\n"
		<<"…………◆◆◆……◆◆◆◆◆◆◆◆◆◆◆……………◆◆…◆◆◆……………………………◆◆◆◆◆……◆◆◆◆◆◆◆◆………◆◆………◆◆◆…………………………◆◆◆◆◆◆◆◆…◆……◆◆………\n"
		<<"………◆◆◆◆◆◆◆◆◆◆◆◆……◆…………………◆……◆◆…………◆◆………………◆◆◆…◆……◆◆◆◆◆◆…………………………◆◆…………◆………………◆◆◆◆◆◆………◆……◆◆………\n"
		<<"………◆◆…◆…………◆……◆…◆◆………………………◆◆◆◆◆◆◆◆◆◆……………◆◆◆◆◆……◆◆……◆……………………………◆◆◆◆◆◆◆◆……………………◆…………◆◆……◆◆………\n"
		<<"……◆◆……◆…………◆◆◆◆◆◆◆……………………◆◆◆◆◆◆◆◆◆◆………………◆◆◆◆◆……◆………◆……………………………◆◆◆◆◆◆◆………………………◆…◆◆◆◆◆◆◆◆◆◆◆◆\n"
		<<"………………◆……◆◆◆◆…◆◆◆……………………◆◆◆◆…………◆◆…………………◆……◆◆◆◆◆………◆…………………………◆◆…………◆◆………………………◆…◆◆◆◆◆◆◆◆◆………\n"
		<<"………………◆◆◆◆◆◆……◆◆◆…………………◆◆◆…◆◆……◆◆…………………◆◆◆◆◆◆◆◆◆………◆…………………………◆◆…………◆◆………………………◆◆◆◆…◆◆◆◆……………\n"
		<<"………………◆…◆……◆…◆◆◆………◆………◆◆◆……◆◆◆◆◆………………◆◆◆◆◆◆◆……◆◆………◆………………………◆◆……………◆……………………◆◆◆◆◆…◆◆……◆◆…………\n"
		<<"………………◆…………◆…◆◆◆◆……◆………◆……………◆◆◆…………………………◆◆…◆◆◆◆◆………◆………………………◆◆…………◆◆………………◆◆◆◆◆………◆◆……◆◆…………\n"
		<<"………………◆…◆……◆◆◆…◆◆◆◆◆……………………◆◆◆…………………………◆◆◆……◆◆◆…………◆……………………◆◆……◆……◆◆………………◆◆◆…………◆◆…………◆◆………\n"
		<<"………………◆…◆◆◆◆◆………◆◆◆◆………………◆◆◆……………………………◆◆◆…………◆◆………◆◆…………………◆◆………◆◆…◆◆………………………………◆◆……………◆◆◆……\n"
		<<"……………◆◆……◆◆◆……………◆◆◆………◆◆◆◆◆……………………………◆◆◆…………◆◆…………◆◆………………◆◆……………◆◆◆………………………………◆◆◆………………◆◆◆◆\n"
		<<"………………◆………◆◆………………◆◆…◆◆◆◆……………………………………◆……………◆◆……………◆◆…………◆◆◆…………………◆◆……………………………◆◆……………………◆◆◆◆\n"
		<<"……………………………………………………………………………………………………………………………………………◆………………………………………………………………………◆…………………………………\n"
		<<"……………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………………\n";*/
	//此处应加入居中之类的，然后调节位置和颜色
	//COORD coord;coord.X=35;coord.Y=11;
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//cout<<"xswa";
	_getch();
	system("cls");
}
int SelectMode()
{
	Title title_of_game(TitleX,TitleY);
	title_of_game.SetPrintContinueOff();
	title_of_game.up();
	title_of_game.print();
	Sleep(50);
	title_of_game.up();
	title_of_game.print();
	Sleep(50);
	title_of_game.up();
	title_of_game.print();
	Sleep(50);
	cin.clear();
	int temp=0;
	{
	SelectBox single(10,20,"Singleplayer");
	SelectBox multi(60,20,"Multiplayer");
	single.Print0();single.Print21();multi.Print0();
	int ch;
	while(TRUE)
	{
		if(KEYDOWN(VK_LEFT)==1)
		{single.Print21();multi.Print20();temp=0;}
		if(KEYDOWN(VK_RIGHT)==1)
		{single.Print20();multi.Print21();temp=1;}
		if(_kbhit()==1){ch=_getch();if(ch==13){break;}};
	}
	}
	if(temp==1)
	{
		SelectBox Time(10,20,"Time Mode");
		SelectBox Battle(60,20,"Battle Mode");
		Time.Print0();Time.Print21();Battle.Print0();
		temp=10;
		int ch;
		while(TRUE)
		{
			if(KEYDOWN(VK_LEFT)==1)
			{Time.Print21();Battle.Print20();temp=10;}
			if(KEYDOWN(VK_RIGHT)==1)
			{Time.Print20();Battle.Print21();temp=11;}
			if(_kbhit()==1){ch=_getch();if(ch==13){break;}};
		}
	}
	return temp;
}
void NextClubRefresh(int a,bool b)
{
	bool NextClub[4][4];
	switch(a)
	{
		case 1:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type1[n][m];break;
		case 2:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type2[n][m];break;
		case 3:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type3[n][m];break;
		case 4:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type4[n][m];break;
		case 5:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type5[n][m];break;
		case 6:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type6[n][m];break;
		case 7:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type7[n][m];break;
		case 8:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type8[n][m];break;
		case 9:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type9[n][m];break;
		case 10:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type10[n][m];break;
		case 11:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type11[n][m];break;
		case 12:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type12[n][m];break;
		case 13:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type13[n][m];break;
		case 14:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type14[n][m];break;
		case 15:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type15[n][m];break;
		case 16:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type16[n][m];break;
		case 17:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type17[n][m];break;
		case 18:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type18[n][m];break;
		case 19:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)NextClub[n][m]=type19[n][m];break;
	}
	//system("cls");system("pause");
	if(b==0)
	{
		SetCursor(NextOfPlayer0X+1,NextOfPlayer0Y+1);
		for(int n=0;n<=3;++n)cout<<((NextClub[n][0]==1)?"█":"  ");
		SetCursor(NextOfPlayer0X+1,NextOfPlayer0Y+2);
		for(int n=0;n<=3;++n)cout<<((NextClub[n][1]==1)?"█":"  ");
		SetCursor(NextOfPlayer0X+1,NextOfPlayer0Y+3);
		for(int n=0;n<=3;++n)cout<<((NextClub[n][2]==1)?"█":"  ");
		SetCursor(NextOfPlayer0X+1,NextOfPlayer0Y+4);
		for(int n=0;n<=3;++n)cout<<((NextClub[n][3]==1)?"█":"  ");
	}
	else if(b==1)
	{
		SetCursor(NextOfPlayer1X+1,NextOfPlayer1Y+1);
		for(int n=0;n<=3;++n)cout<<((NextClub[n][0]==1)?"█":"  ");
		SetCursor(NextOfPlayer1X+1,NextOfPlayer1Y+2);
		for(int n=0;n<=3;++n)cout<<((NextClub[n][1]==1)?"█":"  ");
		SetCursor(NextOfPlayer1X+1,NextOfPlayer1Y+3);
		for(int n=0;n<=3;++n)cout<<((NextClub[n][2]==1)?"█":"  ");
		SetCursor(NextOfPlayer1X+1,NextOfPlayer1Y+4);
		for(int n=0;n<=3;++n)cout<<((NextClub[n][3]==1)?"█":"  ");
	}
}
bool isFull(bool a)
{
	if(a==0)
	{
		bool flag=1;
		for(int m=0;m<=PlaygroundHeight-1;++m)
		{
			int n=0;
			flag=1;
			for(n=0;n<=PlaygroundWidth-1;++n)
			if(playground[n][PlaygroundHeight-1-m]==0)flag=0;
			if(flag==1)return 1;
		}
	}
	else if(a==1)
	{
		bool flag=1;
		for(int m=0;m<=PlaygroundHeight-1;++m)
		{
			int n=0;
			flag=1;
			for(n=0;n<=PlaygroundWidth-1;++n)
			if(playground[n+50][PlaygroundHeight-1-m]==0)flag=0;
			if(flag==1)return 1;
		}
	}
	return 0;
}
int deleteLine(bool a)
{
	int AttackCalculatoer=0;
	bool flag=1;
	if(a==0)
	{
		for(int m=PlaygroundHeight-1;m>=0;--m)
		{
			flag=1;
			for(int n=0;n<=PlaygroundWidth-1;++n)
			if(playground[n][m]==0)flag=0;
			if(flag==1)
			{
				for(int M=m;M>=1;--M)
				for(int n=0;n<=PlaygroundWidth-1;++n)
				{playground[n][M]=playground[n][M-1];}
				for(int n=0;n<=PlaygroundWidth-1;++n)
				{playground[n][0]=0;}
				ScoreOfPlayer0+=5;
				m++;
				AttackCalculatoer++;
			}
		}
		for(int m=0;m<=FrameHeight-3;++m)
		{
			SetCursor(Frame0X+2,FrameY+1+m);
			for(int n=0;n<=FrameWidth/2-3;++n)
			cout<<((playground[n][m]==1)?"█":"  ");
		}
	}
	else if(a==1)
	{
		for(int m=PlaygroundHeight-1;m>=0;--m)
		{
			flag=1;
			for(int n=0;n<=PlaygroundWidth-1;++n)
			if(playground[n+50][m]==0)flag=0;
			if(flag==1)
			{
				for(int M=m;M>=1;--M)
				for(int n=0;n<=PlaygroundWidth-1;++n)
				{playground[n+50][M]=playground[n+50][M-1];}
				for(int n=0;n<=PlaygroundWidth-1;++n)
				{playground[n+50][0]=0;}
				ScoreOfPlayer1+=5;
				m++;
				AttackCalculatoer++;
			}
		}
		for(int m=0;m<=FrameHeight-3;++m)
		{
			SetCursor(Frame1X+2,FrameY+1+m);
			for(int n=0;n<=FrameWidth/2-3;++n)
			cout<<((playground[n+50][m]==1)?"█":"  ");
		}
	}
	return AttackCalculatoer;
}
void ScoreFresh(bool flag)
{
	SetCursor(ScoreOfPlayer0X+1,ScoreOfPlayer0Y+1);
	cout<<ScoreOfPlayer0;
	if(flag==1)
	{
		SetCursor(ScoreOfPlayer1X+1,ScoreOfPlayer1Y+1);
		cout<<ScoreOfPlayer1;
	}
}
void AttackFresh(bool player_)
{
	if(player_==0)
	{
		SetCursor(AttackOfPlayer0X+1,AttackOfPlayer0Y+1);
		cout<<AttackOfPlayer0;
	}
	else if (player_==1)
	{
		SetCursor(AttackOfPlayer1X+1,AttackOfPlayer1Y+1);
		cout<<AttackOfPlayer1;
	}
}
void PrintRules()
{
	cout<<"\n\n\n\n\n\n             此处应有规则介绍\n           press any key to continue";
	cin.get();
	system("cls");
}
void DrawPad(bool flag)//flag=0single,flag=1multi
{
	system("cls");

	//中间分割线
	if(flag==1)
	{
	CenterLine centerline(WidthOfWindow);
	centerline.print();
	}
	GameFrame Frame0(Frame0X,FrameY,FrameWidth,FrameHeight);Frame0.Print();
	if(flag==1)
	{GameFrame Frame1(Frame1X,FrameY,FrameWidth,FrameHeight);Frame1.Print();}


	//文字：
	{
		SetCursor(NextOfPlayer0X,NextOfPlayer0Y);cout<<"next:";
		if(flag==1){SetCursor(NextOfPlayer1X,NextOfPlayer1Y);cout<<"next:";}
	}
	{
		if(flag==1){SetCursor(AttackOfPlayer0X,AttackOfPlayer0Y);cout<<"attack:";
		SetCursor(AttackOfPlayer1X,AttackOfPlayer1Y);cout<<"attack:";}
	}
	{
		//if(flag==0)SetCursor(AttackOfPlayer0X,AttackOfPlayer0Y);cout<<"score:";
		SetCursor(ScoreOfPlayer0X,ScoreOfPlayer0Y);cout<<"score:";
		if(flag==1){SetCursor(ScoreOfPlayer1X,ScoreOfPlayer1Y);cout<<"score:";}
	}
	//cin.get();
}
void PrintGameOver()
{
	continue_choosed=1;
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n      ";
	cout<<"*****************************************"
		<<"\n      *                                       *"
		<<"\n      *             Your score:"<<setw(3)<<ScoreOfPlayer0<<"            *"
		<<"\n      *               Continue?               *"
		<<"\n      *                                       *"
		<<"\n      *                                       *"
		<<"\n      *                                       *"
		<<"\n      *                                       *"
		<<"\n      *                                       *\n      "
		<<"*****************************************";
	SelectBox yes(9,14,"Yes"),no(34,14,"No");
	yes.Print0();yes.Print21();no.Print0();
	int ch;
	while(TRUE)
	{
		if(KEYDOWN(VK_LEFT)){yes.Print21();no.Print20();continue_choosed=1;}
		if(KEYDOWN(VK_RIGHT)){yes.Print20();no.Print21();continue_choosed=0;}
		if(_kbhit()==1){ch=_getch();if(ch==13){break;}};
	}
}
void ShowWinner()
{
	continue_choosed=1;
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n                           ";
	cout<<"*****************************************"
		<<"\n                           *                                       *";
	//if(ScoreOfPlayer0==ScoreOfPlayer1)cout<<"\n                           *               Standoff                *";
	
		cout<<"\n                           *          Winner is: Player"<<(winner==0?"1":(winner==1?"2":"error"))<<"           *";
		cout<<"\n                           *               Continue?               *"
		<<"\n                           *                                       *"
		<<"\n                           *                                       *"
		<<"\n                           *                                       *"
		<<"\n                           *                                       *"
		<<"\n                           *                                       *\n                           "
		<<"*****************************************";
	SelectBox yes(33,15,"Yes"),no(54,15,"No");
	yes.Print0();yes.Print21();no.Print0();
	int ch;
	while(TRUE)
	{
		if(KEYDOWN(VK_LEFT)){yes.Print21();no.Print20();continue_choosed=1;}
		if(KEYDOWN(VK_RIGHT)){yes.Print20();no.Print21();continue_choosed=0;}
		//if(KEYDOWN(VK_RETURN)){break;Sleep(100);}
		if(_kbhit()==1){ch=_getch();if(ch==13){break;}};
	}
}
void ContinueOrNot(){}
void PrintBye(){}




//Title funtion:
Title::Title(short int x=TitleX,short int y=TitleY)								{X=x;Y=y;PrintContinue=1;}
void Title::print()
{
	system("cls");
	for(int n=1;n<=Y-1;++n)	/*print \n*/										{cout<<"\n"	;}
	{for(int n=1;n<=X-1;++n){cout<<" ";}}
	cout<<"___________     __         .__ \n";									{for(int n=1;n<=X-1;++n){cout<<' ';}}
	cout<<"\\__    ___/____/  |________|__| ______\n";							{for(int n=1;n<=X-1;++n){cout<<' ';}}
	cout<<"  |    |_/ __ \\   __ \\_  __\\  |/  ___/\n";						{for(int n=1;n<=X-1;++n){cout<<' ';}}
	cout<<"  |    |\\  ___/|  |   |  |\\/  |\\___ \\ \n";						{for(int n=1;n<=X-1;++n){cout<<' ';}}
	cout<<"  |____| \\___ >|__|   |__| |__/____  >\n";							{for(int n=1;n<=X-1;++n){cout<<' ';}}
	cout<<"          \\/                       \\/ \n";							{for(int n=1;n<=X-1;++n){cout<<' ';}}
	if(PrintContinue==1)
	{
		cout<<"        Press Any Key to Continue\n\n";
	}
	else
		cout<<"\n\n";
	for(int n=1;n<=WidthOfWindow;++n)/*   print =====  */						{cout<<'=';}
}
void Title::up()																{Y-=1;}
void Title::SetPrintContinueOn()												{PrintContinue=1;}
void Title::SetPrintContinueOff()												{PrintContinue=0;}
//End Title funtions


//SelectBox funtions:
SelectBox::SelectBox(int x,int y,string str)									{X=x;Y=y;Selection=str;length=str.length();}
int SelectBox::GetX()															{return X;}
int SelectBox::GetY()															{return Y;}
void SelectBox::Print0()
{
	SetCursor(X,Y);
	cout<<' ';
	for(int n=1;n<=length+4;++n)cout<<'*';
	SetCursor(X,Y+1);
	cout<<" * "<<Selection<<" *";
	SetCursor(X,Y+2);
	cout<<' ';
	for(int n=1;n<=length+4;++n)cout<<'*';
}
void SelectBox::Print21()
{
	SetCursor(X,Y+1);
	cout<<"-> ";
}
void SelectBox::Print20()
{
	SetCursor(X,Y+1);
	cout<<" * ";
}
SelectBox::~SelectBox()
{
	COORD coord;coord.X=X;coord.Y=Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for(int n=1;n<=length+5;++n)cout<<' ';
	coord.X=X;coord.Y=Y+1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for(int n=1;n<=length+5;++n)cout<<' ';
	coord.X=X;coord.Y=Y+2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for(int n=1;n<=length+5;++n)cout<<' ';
}
//End SelectBox funtions


//GameFrame funtions:
GameFrame::GameFrame(short int x=10,short int y=1,short int w=FrameWidth,short int h=FrameHeight)		{X=x;Y=y;width=(w%2==0)?w:w+1;height=h;}
void GameFrame::SetPoint(short int x,short int y)														{X=x;Y=y;}
void GameFrame::SetWidth(short int w)																	{width=(w%2==0)?w:w+1;}
void GameFrame::SetHeight(short int h)																	{height=h;}
void GameFrame::Print()	
{
	{
		SetCursor(X,Y);
		cout<<"┏";
	}
	for(int m=X+2;m<=X+width-4;m+=2)
	{
		SetCursor(m,Y);
		cout<<"━";
	}
	{
		SetCursor(X+width-2,Y);
		cout<<"┓";
	}
	for(int m=Y+1;m<=Y+height-2;m++)
	{
		SetCursor(X,m);
		cout<<"┃";
	}
	for(int m=Y+1;m<=Y+height-2;m++)
	{
		SetCursor(X+width-2,m);
		cout<<"┃";
	}
	{
		SetCursor(X,Y+height-1);
		cout<<"┗";
	}
	for(int m=X+2;m<=X+width-4;m+=2)
	{
		SetCursor(m,Y+height-1);
		cout<<"━";
	}
	{
		SetCursor(X+width-2,Y+height-1);
		cout<<"┛";
	}
}
//End GameFrame funtions

//TempClub funtions:
TempClub::TempClub(int Type,bool b,bool PLAYER=0)
{
	player=PLAYER;
	type=Type%19+1;
	switch(type)
	{
		case 1:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type1[n][m];width=2;break;
		case 2:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type2[n][m];width=3;break;
		case 3:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type3[n][m];width=2;break;
		case 4:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type4[n][m];width=1;break;
		case 5:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type5[n][m];width=4;break;
		case 6:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type6[n][m];width=2;break;
		case 7:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type7[n][m];width=3;break;
		case 8:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type8[n][m];width=2;break;
		case 9:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type9[n][m];width=3;break;
		case 10:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type10[n][m];width=3;break;
		case 11:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type11[n][m];width=2;break;
		case 12:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type12[n][m];width=3;break;
		case 13:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type13[n][m];width=2;break;
		case 14:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type14[n][m];width=3;break;
		case 15:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type15[n][m];width=2;break;
		case 16:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type16[n][m];width=3;break;
		case 17:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type17[n][m];width=2;break;
		case 18:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type18[n][m];width=3;break;
		case 19:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type19[n][m];width=2;break;
	}
	if(b==0)
	{
		X=(FrameWidth-4)/4-2;Y=0;
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+1);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][0]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+2);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][1]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+3);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][2]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+4);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][3]==1)?"█":"  ");
	}
	if(b==1)
	{
		X=(FrameWidth-4)/4-2+50;Y=0;
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+1);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][0]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+2);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][1]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+3);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][2]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+4);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][3]==1)?"█":"  ");
	}
}
void TempClub::fresh(int Type)
{
	type=Type;
	if(player==0)
	{
		X=(FrameWidth-4)/4-2;
		Y=((type==4)?0:-1);
		switch(type)
		{
			case 1:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type1[n][m];width=2;break;
			case 2:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type2[n][m];width=3;break;
			case 3:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type3[n][m];width=2;break;
			case 4:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type4[n][m];width=1;break;
			case 5:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type5[n][m];width=4;break;
			case 6:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type6[n][m];width=2;break;
			case 7:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type7[n][m];width=3;break;
			case 8:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type8[n][m];width=2;break;
			case 9:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type9[n][m];width=3;break;
			case 10:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type10[n][m];width=3;break;
			case 11:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type11[n][m];width=2;break;
			case 12:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type12[n][m];width=3;break;
			case 13:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type13[n][m];width=2;break;
			case 14:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type14[n][m];width=3;break;
			case 15:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type15[n][m];width=2;break;
			case 16:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type16[n][m];width=3;break;
			case 17:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type17[n][m];width=2;break;
			case 18:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type18[n][m];width=3;break;
			case 19:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type19[n][m];width=2;break;
		}
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+1);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][0]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+2);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][1]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+3);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][2]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+4);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][3]==1)?"█":"  ");
	}
	else if(player==1)
	{
		X=(FrameWidth-4)/4-2+50;
		Y=((type==4)?0:-1);
		switch(type)
		{
			case 1:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type1[n][m];width=2;break;
			case 2:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type2[n][m];width=3;break;
			case 3:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type3[n][m];width=2;break;
			case 4:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type4[n][m];width=1;break;
			case 5:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type5[n][m];width=4;break;
			case 6:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type6[n][m];width=2;break;
			case 7:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type7[n][m];width=3;break;
			case 8:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type8[n][m];width=2;break;
			case 9:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type9[n][m];width=3;break;
			case 10:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type10[n][m];width=3;break;
			case 11:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type11[n][m];width=2;break;
			case 12:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type12[n][m];width=3;break;
			case 13:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type13[n][m];width=2;break;
			case 14:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type14[n][m];width=3;break;
			case 15:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type15[n][m];width=2;break;
			case 16:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type16[n][m];width=3;break;
			case 17:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type17[n][m];width=2;break;
			case 18:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type18[n][m];width=3;break;
			case 19:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type19[n][m];width=2;break;
		}
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+1);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][0]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+2);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][1]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+3);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][2]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+4);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][3]==1)?"█":"  ");
	}
}
void TempClub::refresh(int a,bool gameMode_=0)
{
	if(player==0)
	{
		for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)playground[X+n][Y+m]=(ClubType[n][m] || playground[X+n][Y+m]);
		type=a;
		X=(FrameWidth-4)/4-2;
		Y=((type==4)?0:-1);
		switch(type)
		{
			case 1:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type1[n][m];width=2;break;
			case 2:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type2[n][m];width=3;break;
			case 3:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type3[n][m];width=2;break;
			case 4:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type4[n][m];width=1;break;
			case 5:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type5[n][m];width=4;break;
			case 6:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type6[n][m];width=2;break;
			case 7:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type7[n][m];width=3;break;
			case 8:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type8[n][m];width=2;break;
			case 9:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type9[n][m];width=3;break;
			case 10:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type10[n][m];width=3;break;
			case 11:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type11[n][m];width=2;break;
			case 12:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type12[n][m];width=3;break;
			case 13:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type13[n][m];width=2;break;
			case 14:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type14[n][m];width=3;break;
			case 15:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type15[n][m];width=2;break;
			case 16:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type16[n][m];width=3;break;
			case 17:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type17[n][m];width=2;break;
			case 18:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type18[n][m];width=3;break;
			case 19:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type19[n][m];width=2;break;
		}
		bool flag=1;
		for(int m=3;m>=0;--m)
			for(int n=0;n<=3;++n)
			if( (ClubType[n][m]==1)&&(playground[X+n][Y+1+m]==1) )flag=0;
		if(flag==0&&gameMode_==0){PrintGameOver();winner=1;goto skip;}
		else if(flag==0&&gameMode_==1){winner=1;ShowWinner();goto skip;}
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+1);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][0]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+2);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][1]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+3);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][2]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame0X,FrameY+4);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][3]==1)?"█":"  ");
	}
	else if(player==1)
	{
		for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)playground[X+n][Y+m]=(ClubType[n][m] || playground[X+n][Y+m]);
		type=a;
		X=(FrameWidth-4)/4-2+50;
		Y=((type==4)?0:-1);
		switch(type)
		{
			case 1:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type1[n][m];width=2;break;
			case 2:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type2[n][m];width=3;break;
			case 3:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type3[n][m];width=2;break;
			case 4:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type4[n][m];width=1;break;
			case 5:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type5[n][m];width=4;break;
			case 6:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type6[n][m];width=2;break;
			case 7:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type7[n][m];width=3;break;
			case 8:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type8[n][m];width=2;break;
			case 9:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type9[n][m];width=3;break;
			case 10:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type10[n][m];width=3;break;
			case 11:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type11[n][m];width=2;break;
			case 12:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type12[n][m];width=3;break;
			case 13:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type13[n][m];width=2;break;
			case 14:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type14[n][m];width=3;break;
			case 15:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type15[n][m];width=2;break;
			case 16:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type16[n][m];width=3;break;
			case 17:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type17[n][m];width=2;break;
			case 18:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type18[n][m];width=3;break;
			case 19:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=type19[n][m];width=2;break;
		}
		bool flag=1;
		for(int m=3;m>=0;--m)
			for(int n=0;n<=3;++n)
			if( (ClubType[n][m]==1)&&(playground[X+n][Y+1+m]==1) )flag=0;
		if(flag==0){winner=0;ShowWinner();goto skip;}
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+1);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][0]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+2);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][1]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+3);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][2]==1)?"█":"  ");
		SetCursor((FrameWidth-4)/2-3+Frame1X,FrameY+4);
		for(int n=0;n<=3;++n)cout<<((ClubType[n][3]==1)?"█":"  ");
	}
skip:;
}
void TempClub::MoveLeft()
{
	if(player==0)
	{
		if(X!=0&&X!=50)
		{
			int flag=1;
			for(int m=0;m<=3;++m)
			for(int n=0;n<=3;++n)
				if(ClubType[m][n]==1&&playground[X-1+m][Y+n]==1){flag=0;break;break;}
			if(flag==1)
			{
				if(Y!=-1&&Y<=FrameWidth/2-6)
				if( ((X+3)!=(FrameWidth-4)/2) && ((X+2)!=(FrameWidth-4)/2) )
				for(int n=0;n<=3;++n)
				{
					SetCursor((X+3)*2+Frame0X+2,FrameY+1+Y+n);
					cout<<((playground[X+3][Y+n]==1)?"█":"  ");
				}
				X-=1;
				for(int n=0;n<=3;++n)
				{
					SetCursor((X)*2+Frame0X+2,FrameY+1+Y+n);
					for(int m=0;m<=3;++m)	
					{
						if((X+m)==(FrameWidth-4)/2)break;
						cout<<((playground[X+m][Y+n]==1||ClubType[m][n]==1)?"█":"  ");
					}
				}
			}
		}
	}
	else if(player==1)
	{
		if(X!=0&&X!=50)
		{
			int flag=1;
			for(int m=0;m<=3;++m)
			for(int n=0;n<=3;++n)
				if(ClubType[m][n]==1&&playground[X-1+m][Y+n]==1){flag=0;break;break;}
			if(flag==1)
			{
				if(Y!=-1&&Y<=FrameWidth/2-6)
				if( ((X-50+3)!=(FrameWidth-4)/2) && ((X-50+2)!=(FrameWidth-4)/2) )
				for(int n=0;n<=3;++n)
				{
					SetCursor((X-50+3)*2+Frame1X+2,FrameY+1+Y+n);
					cout<<((playground[X+3][Y+n]==1)?"█":"  ");
				}
				X-=1;
				for(int n=0;n<=3;++n)
				{
					SetCursor((X-50)*2+Frame1X+2,FrameY+1+Y+n);
					for(int m=0;m<=3;++m)	
					{
						if((X+m-50)==(FrameWidth-4)/2)break;
						cout<<((playground[X+m][Y+n]==1||ClubType[m][n]==1)?"█":"  ");
					}
				}
			}
		}
	}
	
}
void TempClub::MoveRight()
{
	if(player==0)
	{
		if( (X!=(FrameWidth-4)/2-width) && (X!=50+(FrameWidth-4)/2-width))
		{
			int flag=1;
			for(int m=0;m<=3;++m)
			for(int n=0;n<=3;++n)
				if(ClubType[3-m][n]==1&&playground[X+4-m][n+Y]==1){flag=0;break;break;}
			if(flag==1)
			{
				for(int n=0;n<=3;++n)
				{
					SetCursor((X)*2+Frame0X+2,FrameY+1+Y+n);
					cout<<((playground[X][Y+n]==1)?"█":"  ");
				}
				X+=1;
				for(int n=0;n<=3;++n)
				{
					SetCursor((X)*2+Frame0X+2,FrameY+1+Y+n);
					for(int m=0;m<=3;++m)	
					{
						if((X+m)==(FrameWidth-4)/2)break;
						cout<<(((playground[X+m][Y+n]==1)||(ClubType[m][n]==1))?"█":"  ");
					}
				}
			}
		}
	}
	else if(player==1)
	{
		if( (X!=(FrameWidth-4)/2-width) && (X!=50+(FrameWidth-4)/2-width))
		{
			int flag=1;
			for(int m=0;m<=3;++m)
			for(int n=0;n<=3;++n)
				if(ClubType[3-m][n]==1&&playground[X+4-m][n+Y]==1){flag=0;break;break;}
			if(flag==1)
			{
				for(int n=0;n<=3;++n)
				{
					SetCursor((X-50)*2+Frame1X+2,FrameY+1+Y+n);
					cout<<((playground[X][Y+n]==1)?"█":"  ");
				}
				X+=1;
				for(int n=0;n<=3;++n)
				{
					SetCursor((X-50)*2+Frame1X+2,FrameY+1+Y+n);
					for(int m=0;m<=3;++m)	
					{
						if((X+m-50)==(FrameWidth-4)/2)break;
						cout<<(((playground[X+m][Y+n]==1)||(ClubType[m][n]==1))?"█":"  ");
					}
				}
			}
		}
	}
}
void TempClub::Rotation()
{
	bool TempType[4][4];
	switch(type)
	{
	case 1:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type1[n][m];break;
	case 2:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type3[n][m];break;
	case 3:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type2[n][m];break;
	case 4:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type5[n][m];break;
	case 5:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type4[n][m];break;
	case 6:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type7[n][m];break;
	case 7:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type8[n][m];break;
	case 8:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type9[n][m];break;
	case 9:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type6[n][m];break;
	case 10:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type11[n][m];break;
	case 11:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type12[n][m];break;
	case 12:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type13[n][m];break;
	case 13:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type10[n][m];break;
	case 14:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type15[n][m];break;
	case 15:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type14[n][m];break;
	case 16:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type17[n][m];break;
	case 17:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type18[n][m];break;
	case 18:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type19[n][m];break;
	case 19:for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)TempType[n][m]=type16[n][m];break;
	}
	bool flag=1;
	for(int n=0;n<=3;++n)
		for(int m=0;m<=3;++m)
			if( TempType[n][m]==1&&playground[X+n][Y+m]==1)flag=0;
	if(player==0)
	{
		if( type==4 && (X+3)>((FrameWidth-4)/2-1)) flag=0;
		if( (TempType[2][0]==1||TempType[2][1]==1||TempType[2][2]==1||TempType[2][3]==1) && (X+2)>((FrameWidth-4)/2-1) )flag=0;
		if(flag==1)
		{
			for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=TempType[n][m];
			switch(type)
			{
				case 1:type=1;width=2;break;
				case 2:type=3;width=2;break;
				case 3:type=2;width=3;break;
				case 4:type=5;width=4;break;
				case 5:type=4;width=1;break;
				case 6:type=7;width=3;break;
				case 7:type=8;width=2;break;
				case 8:type=9;width=3;break;
				case 9:type=6;width=2;break;
				case 10:type=11;width=2;break;
				case 11:type=12;width=3;break;
				case 12:type=13;width=2;break;
				case 13:type=10;width=3;break;
				case 14:type=15;width=2;break;
				case 15:type=14;width=3;break;
				case 16:type=17;width=2;break;
				case 17:type=18;width=3;break;
				case 18:type=19;width=2;break;
				case 19:type=16;width=3;break;
			}
			for(int n=0;n<=3;++n)
			{
				SetCursor((X)*2+Frame0X+2,FrameY+1+Y+n);
				for(int m=0;m<=3;++m)	
				{
					if((X+m)==(FrameWidth-4)/2)break;
					cout<<(((playground[X+m][Y+n]==1)||(ClubType[m][n]==1))?"█":"  ");
				}
			}
		}
	}
	else if(player==1)
	{
		if( type==4 && (X+3-50)>((FrameWidth-4)/2-1)) flag=0;
		if( (TempType[2][0]==1||TempType[2][1]==1||TempType[2][2]==1||TempType[2][3]==1) && (X+2-50)>((FrameWidth-4)/2-1) )flag=0;
		if(flag==1)
		{
			for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=TempType[n][m];
			switch(type)
			{
				case 1:type=1;width=2;break;
				case 2:type=3;width=2;break;
				case 3:type=2;width=3;break;
				case 4:type=5;width=4;break;
				case 5:type=4;width=1;break;
				case 6:type=7;width=3;break;
				case 7:type=8;width=2;break;
				case 8:type=9;width=3;break;
				case 9:type=6;width=2;break;
				case 10:type=11;width=2;break;
				case 11:type=12;width=3;break;
				case 12:type=13;width=2;break;
				case 13:type=10;width=3;break;
				case 14:type=15;width=2;break;
				case 15:type=14;width=3;break;
				case 16:type=17;width=2;break;
				case 17:type=18;width=3;break;
				case 18:type=19;width=2;break;
				case 19:type=16;width=3;break;
			}
			for(int n=0;n<=3;++n)
			{
				SetCursor((X-50)*2+Frame1X+2,FrameY+1+Y+n);
				for(int m=0;m<=3;++m)	
				{
					if((X-50+m)==(FrameWidth-4)/2)break;
					cout<<(((playground[X+m][Y+n]==1)||(ClubType[m][n]==1))?"█":"  ");
				}
			}
		}
	}
	else if(flag==0)
	{
		flag=1;X-=1;
		for(int n=0;n<=3;++n)
			for(int m=0;m<=3;++m)
				if( TempType[n][m]==1&&playground[X+n][Y+m]==1)flag=0;
		if( type==4 && (X+3)>((FrameWidth-4)/2-4)) flag=0;
		if( (TempType[2][0]==1||TempType[2][1]==1||TempType[2][2]==1||TempType[2][3]==1) && (X+2)>((FrameWidth-4)/2-1) )flag=0;
		if(flag==1)
		{
			for(int n=0;n<=3;++n)for(int m=0;m<=3;++m)ClubType[n][m]=TempType[n][m];
			switch(type)
			{
				case 1:type=1;width=2;break;
				case 2:type=3;width=2;break;
				case 3:type=2;width=3;break;
				case 4:type=5;width=4;break;
				case 5:type=4;width=1;break;
				case 6:type=7;width=3;break;
				case 7:type=8;width=2;break;
				case 8:type=9;width=3;break;
				case 9:type=6;width=2;break;
				case 10:type=11;width=2;break;
				case 11:type=12;width=3;break;
				case 12:type=13;width=2;break;
				case 13:type=10;width=3;break;
				case 14:type=15;width=2;break;
				case 15:type=14;width=3;break;
				case 16:type=17;width=2;break;
				case 17:type=18;width=3;break;
				case 18:type=19;width=2;break;
				case 19:type=16;width=3;break;
			}
			for(int n=0;n<=3;++n)
			{
				SetCursor((X)*2+Frame0X+2,FrameY+1+Y+n);
				for(int m=0;m<=3;++m)	
				{
					if((X+m)==(FrameWidth-4)/2)break;
					cout<<(((playground[X+m][Y+n]==1)||(ClubType[m][n]==1))?"█":"  ");
				}
			}
		}
		else X+=1;
	}
}
void TempClub::MoveDown()
{
	if(player==0)
	{
		bool flag=1;
		for(int m=3;m>=0;--m)
		for(int n=0;n<=3;++n)
			if( (ClubType[n][m]==1&&playground[X+n][Y+1+m]==1) || ((Y+3)==(FrameHeight-3)) )flag=0;
		if(flag==1)
		{
			if(Y!=-1)
			{
				SetCursor(X*2+Frame0X+2,FrameY+Y+1);
				for(int n=0;n<=3;++n)
				{
					if((X+n)==(FrameWidth-4)/2)break;
					cout<<((playground[X+n][Y]==1)?"█":"  ");
				}
			}
			Y+=1;
			for(int n=0;n<=3;++n)
			{
				SetCursor((X)*2+Frame0X+2,FrameY+1+Y+n);
				for(int m=0;m<=3;++m)	
				{
					if((X+m)==(FrameWidth-4)/2)break;
					cout<<(((playground[X+m][Y+n]==1)||(ClubType[m][n]==1))?"█":"  ");
				}
			}
			if(Y==0){SetCursor(X*2+Frame0X+2,Y+FrameY);cout<<"━━━━";}
		}
	}
	else if(player==1)
	{
		bool flag=1;
		for(int m=3;m>=0;--m)
		for(int n=0;n<=3;++n)
			if( (ClubType[n][m]==1&&playground[X+n][Y+1+m]==1) || ((Y+3)==(FrameHeight-3)) )flag=0;
		if(flag==1)
		{
			if(Y!=-1)
			{
				SetCursor((X-50)*2+Frame1X+2,FrameY+Y+1);
				for(int n=0;n<=3;++n)
				{
					if((X+n-50)==(FrameWidth-4)/2)break;
					cout<<((playground[X+n][Y]==1)?"█":"  ");
				}
			}
			Y+=1;
			for(int n=0;n<=3;++n)
			{
				SetCursor((X-50)*2+Frame1X+2,FrameY+1+Y+n);
				for(int m=0;m<=3;++m)	
				{
					if((X-50+m)==(FrameWidth-4)/2)break;
					cout<<(((playground[X+m][Y+n]==1)||(ClubType[m][n]==1))?"█":"  ");
				}
			}
			if(Y==0){SetCursor(X*2-100+Frame1X+2,Y+FrameY);cout<<"━━━━";}
		}
	}
}
bool TempClub::isMoveable()
{
	bool flag=1;
	for(int m=3;m>=0;--m)
	for(int n=0;n<=3;++n)
		if( (ClubType[n][m]==1&&playground[X+n][Y+1+m]==1) || ((Y+3)==(FrameHeight-3)) )flag=0;
	return flag;
}
//End TempClub funtions

//CenterLine funtions:
		CenterLine::CenterLine(short int width)									{X=(width%2==0?(width/2-1):(width/2));}
void	CenterLine::print()
{
	for(int m=0;m<=HeightOfWindow-1;m+=1)
	{
		SetCursor(X,m);
		cout<<"┃";
	}
}
//End CenterLine funtions



