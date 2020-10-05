#include "pch.h"
#include <iostream>
#include "to_baobao.h"

void enter_animation()
{
	system("cls");
	system("color F0");
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < LENGTH; y++)
		{
			int dice = random(3);
			switch (dice)
			{
			case 1:
				TURN_WHITE;
				printf(" ");
				break;
			case 2:
				TURN_RED;
				printf(" ");
				break;
			case 3:
				TURN_BLUE;
				printf(" ");
				break;
			}
		}
	Sleep(2500);
	system("cls");
	system("color F0");
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < WIDTH; x++)
			for (int y = 0; y < LENGTH; y++)
			{
				if (y == 0 && x != 0)
					printf("\n");
				int dice = random(60);
				switch (dice)
				{
				case 1:
					TURN_RED;
					printf("     ");
					break;
				case 2:
					TURN_BLUE;
					printf("     ");
					break;
				default:
					TURN_WHITE;
					printf("     ");
					break;
				}
				Sleep(1);
			}
		Sleep(10);
	}
}