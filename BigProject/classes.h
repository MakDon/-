#include<string>
#include<Windows.h>
using namespace std;
#ifndef CLASSES_H
#define CLASSES_H



void initialize();
void SetCursor(int,int);
void PrintTitle();
int  SelectMode();
void SingleMode();
void PrintGameOver();
bool isFull(bool);
void NextClubRefresh(int,bool=0);
void ScoreFresh(bool);
void AttackFresh(bool);
int deleteLine(bool);
void TimeMode();
void BattleMode();
void PrintRules();
void ShowWinner();
void ContinueOrNot();
void PrintBye();
void DrawPad(bool);
void PrintPlayer0();
void PrintPlayer1();

class GameFrame
{
public:
	GameFrame(short int ,short int,short int,short int );
	void SetPoint(short int,short int);
	void SetWidth(short int);
	void SetHeight(short int);
	void Print();
private:
	short int X;
	short int Y;
	short int width;
	short int height;
};

class CenterLine
{
public:
	CenterLine(short int);
	void print();
private:
	short int X;
};

class Title
{
public:
	Title(short int,short int );
	void print();
	void up();
	void SetPrintContinueOn();
	void SetPrintContinueOff();
private:
	short int X;
	short int Y;
	bool PrintContinue;
};

class SelectBox
{
public:
	SelectBox(int,int,string);
	~SelectBox();
	int GetX();
	int GetY();
	void Print0();
	void Print21();
	void Print20();
private:
	short int X;
	short int Y;
	short int length;
	string Selection;
};

class TempClub
{
public:
	TempClub(int,bool,bool);
	void refresh(int,bool);
	void fresh(int);
	bool isMoveable();
	void MoveLeft();
	void MoveRight();
	void Rotation();
	int type;
	short int X;
	short int Y;
	void MoveDown();
	int ClubType[4][4];
	int width;
	bool player;
};

#endif