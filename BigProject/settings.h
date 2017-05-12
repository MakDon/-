#ifndef SETTINGS_H
#define SETTINGS_H




#define KEYDOWN(VK_LEFT) ((GetAsyncKeyState(VK_LEFT) & 0x8000) ?1:0) 
#define KEYDOWN(VK_RIGHT) ((GetAsyncKeyState(VK_RIGHT) & 0x8000) ?1:0) 
#define KEYDOWN(VK_UP) ((GetAsyncKeyState(VK_UP) & 0x8000) ?1:0) 
#define KEYDOWN(VK_DOWN) ((GetAsyncKeyState(VK_DOWN) & 0x8000) ?1:0) 
#define KEYDOWN(VK_W) ((GetAsyncKeyState(VK_W) & 0x8000) ?1:0) 
#define KEYDOWN(VK_A) ((GetAsyncKeyState(VK_A) & 0x8000) ?1:0) 
#define KEYDOWN(VK_S) ((GetAsyncKeyState(VK_S) & 0x8000) ?1:0) 
#define KEYDOWN(VK_D) ((GetAsyncKeyState(VK_D) & 0x8000) ?1:0) 
#define KEYDOWN(VK_NUMPAD0) ((GetAsyncKeyState(VK_NUMPAD0) & 0x8000) ?1:0) 
#define KEYDOWN(VK_SPACE) ((GetAsyncKeyState(VK_SPACE) & 0x8000) ?1:0) 
#define KEYDOWN(VK_RETURN) ((GetAsyncKeyState(VK_RETURN) & 0x8000) ?1:0) 
#define KEYDOWN(VK_ESCAPE) ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) ?1:0) 
#define VK_A 0x41
#define VK_D 0x44
#define VK_S 0x53
#define VK_W 0x57



const static short int WidthOfWindow=103;//
const static short int HeightOfWindow=31;//

const static short int TitleX=32;
const static short int TitleY=9;

const static short int Frame0X=13;
const static short int Frame1X=64;
const static short int FrameY=1;
const static short int FrameWidth=34;
const static short int FrameHeight=28;

const static short int NextOfPlayer0X=2;
const static short int NextOfPlayer0Y=1;
const static short int NextOfPlayer1X=55;
const static short int NextOfPlayer1Y=1;

const static short int AttackOfPlayer0X=2;
const static short int AttackOfPlayer0Y=6;
const static short int AttackOfPlayer1X=55;
const static short int AttackOfPlayer1Y=6;

const static short int ScoreOfPlayer0X=2;
const static short int ScoreOfPlayer0Y=12;
const static short int ScoreOfPlayer1X=55;
const static short int ScoreOfPlayer1Y=12;

extern short int AttackOfPlayer0;
extern short int AttackOfPlayer1;
static short int ScoreOfPlayer0=0;
static short int ScoreOfPlayer1=0;
static int fps=500;//(every 500ms cls)
static int PlaygroundWidth=(FrameWidth-4)/2;
static int PlaygroundHeight=FrameHeight-2;
extern bool playground[100][50];
extern int continue_choosed;


#endif