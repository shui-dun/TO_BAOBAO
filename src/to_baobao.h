#pragma once

#define LENGTH 120
#define WIDTH 30
#define random(x) (rand()%x+1)
#define ranbetween(x,y)  (rand()%(y-x+1)+x)
#define TURN_DARKRED  SetConsoleTextAttribute(hOut,BACKGROUND_RED)
#define TURN_GREEN    SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY)
#define TURN_RED      SetConsoleTextAttribute(hOut,BACKGROUND_RED|BACKGROUND_INTENSITY)
#define TURN_BLUE     SetConsoleTextAttribute(hOut,BACKGROUND_BLUE|BACKGROUND_INTENSITY)
#define TURN_WHITE    SetConsoleTextAttribute(hOut,BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY)

#include <Windows.h>
#include <time.h>
#include "conio.h"
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "resource.h"

using namespace std;

void cover(bool*);
void position(int x, int y);
void enter_animation();
void maze_enter();
void show(char map[WIDTH][LENGTH+1]);
void print(char map[WIDTH][LENGTH+1]);
void move(char map[WIDTH][LENGTH+1], int *a, int *b);
void switch_lever(int *a, int *b, int original_a, int original_b, char map[WIDTH][LENGTH + 1], int speed, int destroy);
void fail(int *a, int *b, int original_a, int original_b);
bool check(char map[WIDTH][LENGTH + 1], int *a, int *b, int speed, int destroy, int original_b);

void end_animation(bool music2);
void sound();
void sound_fail();

enum keyboard
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
};

extern HANDLE hOut;
extern char map1[WIDTH][LENGTH + 1];
extern char map2[WIDTH][LENGTH + 1];
extern char map3[WIDTH][LENGTH + 1];