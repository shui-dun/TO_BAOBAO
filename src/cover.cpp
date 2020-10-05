#include "pch.h"
#include <iostream>
#include "to_baobao.h"

void position(int x, int y)
{
	HANDLE hout1;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout1, coord);
}


void cover(bool *music2)
{
	system("color F0");
	position(60, 11);
	printf("T H E  M A Z E");
	position(60, 15);
	printf("1 : B E G I N");
	position(60, 17);
	printf("2 : L E A V E");

	position(20, 24);
	time_t num = time(0);
	struct tm *p = localtime(&num);
	printf("%d ", 1900 + p->tm_year);
	printf("%d ", 1 + p->tm_mon);
	printf("%d", p->tm_mday);

	TURN_BLUE;
	position(0, 0);
	for (int i = 0; i < LENGTH * 3; i++)
		printf(" ");
	putchar('\n');
	for (int i = 0; i < WIDTH - 7; i++)
		if (i % 2 == 0)
			printf("                 \n");             //blue frame
		else
			printf("                   \n");
	for (int i = 0; i < 4 * LENGTH; i++)
		printf(" ");
	position(68, 19);

	for (;;)
	{
		char choice = _getch();
		sound();
		if (choice == '2')
			exit(0);
		else if (choice == '1' || choice == ENTER)
			return;
		else if (choice == 'L')
			*music2 = true;
	}
}








