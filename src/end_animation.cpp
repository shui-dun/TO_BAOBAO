#include "pch.h"
#include <iostream>
#include "to_baobao.h"

void end_animation(bool music2)
{
	if(music2==true)
		PlaySound(TEXT("music2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	else
		PlaySound(TEXT("Flower_Dance.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	system("color F0");
	position(49, 14);
	printf("L O V E  F O R E V E R");
	for (; ; )
	{
		position(ranbetween(0, 35), ranbetween(0, 29));
		TURN_RED;
		printf("     ");
		position(ranbetween(79, 115), ranbetween(0, 29));
		TURN_RED;
		printf("     ");
		position(ranbetween(36, 78), ranbetween(0, 12));
		TURN_RED;
		printf("     ");
		position(ranbetween(36, 78), ranbetween(16, 29));
		TURN_RED;
		printf("     ");
		Sleep(100);
	}
}
