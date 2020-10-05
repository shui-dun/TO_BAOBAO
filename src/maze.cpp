#include "pch.h"
#include <iostream>
#include "to_baobao.h"

void show(char map[WIDTH][LENGTH+1])
{
	system("color 0F");
	position(0, 0);
	for (int i = 1; i <= 10; i++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			for (int y = 0; y < LENGTH; y++)
			{
				int dice = random(10);
				if (dice <= i)
					switch (map[x][y])
					{
					case 'A':printf("*"); break;
					case 'B':printf(" "); break;
					case 'C':printf(" "); break;
					case 'H':
					case 'Z':
					case 'S':printf("+"); break;
					}
				else printf(" ");
			}
		}
		Sleep(10);
	}
	Sleep(1200);
	system("color F0");
}

void print(char map[WIDTH][LENGTH+1])
{
	position(0, 0);
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < LENGTH; y++)
		{
			switch (map[x][y])
			{
			case 'A':
				TURN_WHITE;
				printf(" "); break;
			case 'B':
				TURN_RED;
				printf(" "); break;
			case 'C':
				TURN_BLUE;
				printf(" "); break;
			case 'Z':
				TURN_DARKRED;
				printf(" "); break;
			case 'S':
			case 'H':
				TURN_GREEN;
				printf(" "); break;
			}
		}
	}
}

void move(char map[WIDTH][LENGTH+1], int *a, int *b)
{
	int destroy = 0;
	int speed = 3;
	int original_a = *a;
	int original_b = *b;
	for (;;)
	{
		switch_lever(a, b, original_a, original_b, map, speed, destroy);
		position(*b, *a);
		TURN_BLUE;
		printf(" ");
		position(*b, *a);
		if (map[*a][*b] == 'S')
		{
			if (speed != 10)
			{
				sound();
				TURN_WHITE;
				position(0, 0);
				printf("加");
				Sleep(300);
				printf("速");
				Sleep(300);
				printf("果");
				Sleep(300);
				printf("實");
				Sleep(1000);
				position(0, 0);
				printf("        ");
				position(*b, *a);
			}
				speed = 10;
		}
		if (map[*a][*b] == 'H')
		{
			map[*a][*b] = 'B';
			sound();
			TURN_WHITE;
			position(0, 0);
			printf("貫");
			Sleep(300);
			printf("穿");
			Sleep(300);
			printf("果");
			Sleep(300);
			printf("實");
			Sleep(1000);
			position(0, 0);
			printf("        ");
			position(*b, *a);
			destroy++;
		}
		if (check(map, a, b, speed, destroy, original_b))
			return;
	}
}

void switch_lever(int *a, int *b, int original_a, int original_b, char map[WIDTH][LENGTH + 1], int speed, int destroy)
{
	char lever = _getch();
	position(*b, *a);
	TURN_RED;
	printf(" ");
	switch (lever)
	{
	case UP:
	case 'w':
		for (int i = 0; i < speed; i++)
		{
			if (map[(*a) - 1][*b] == 'Z')
			{
				fail(a, b, original_a, original_b);
				break;
			}
			if (map[(*a) - 1][*b] != 'A')
				(*a)--;
			else break;
		}
		break;
	case LEFT:
	case 'a':
		for (int i = 0; i < speed + 1; i++)
		{
			if (map[*a][(*b) - 1] == 'Z')
			{
				fail(a, b, original_a, original_b);
				break;
			}
			if (map[*a][(*b) - 1] != 'A')
				(*b)--;
			else break;
		}
		break;
	case DOWN:
	case 's':
		for (int i = 0; i < speed; i++)
		{
			if (map[(*a) + 1][*b] == 'Z')
			{
				fail(a, b, original_a, original_b);
				break;
			}
			if (map[(*a) + 1][*b] != 'A')
				(*a)++;
			else break;
		}
		break;
	case RIGHT:
	case 'd':
		for (int i = 0; i < speed + 1; i++)
		{
			if (map[*a][(*b) + 1] == 'Z')
			{
				fail(a, b, original_a, original_b);
				break;
			}
			if (map[*a][(*b) + 1] != 'A')
				(*b)++;
			else break;
		}
		break;
	default:break;
	}
	if (destroy)
		switch (lever)
		{
		case 'W':
		{
			int i = 1;
			for (; map[(*a) - i][*b] != 'A';)
			{
				position(*b, (*a) - i);
				TURN_DARKRED;
				printf(" ");
				Sleep(100);
				position(*b, (*a) - i);
				TURN_RED;
				printf(" ");
				i++;
			}
			for (int count = 0; map[(*a) - i][*b] == 'A'&&count < destroy; count++)
			{
				map[(*a) - i][*b] = 'B';
				position(*b, (*a) - i);
				TURN_RED;
				printf(" ");
				Sleep(300);
				i++;
			}
			break;
		}
		case 'A':
		{
			int i = 1;
			for (; map[*a][(*b) - i] != 'A';)
			{
				position((*b) - i, *a);
				TURN_DARKRED;
				printf(" ");
				Sleep(100);
				position((*b) - i, *a);
				TURN_RED;
				printf(" ");
				i++;
			}
			for (int count = 0; map[*a][(*b) - i] == 'A'&&count < destroy; count++)
			{
				map[*a][(*b) - i] = 'B';
				position((*b) - i, *a);
				TURN_RED;
				printf(" ");
				Sleep(300);
				i++;
			}
			break;
		}
		case 'S':
		{
			int i = 1;
			for (; map[(*a) + i][*b] != 'A';)
			{
				position(*b, (*a) + i);
				TURN_DARKRED;
				printf(" ");
				Sleep(100);
				position(*b, (*a) + i);
				TURN_RED;
				printf(" ");
				i++;
			}
			for (int count = 0; map[(*a) + i][*b] == 'A'&&count < destroy; count++)
			{
				map[(*a) + i][*b] = 'B';
				position(*b, (*a) + i);
				TURN_RED;
				printf(" ");
				Sleep(300);
				i++;
			}
			break;
		}
		case 'D':
		{
			int i = 1;
			for (; map[*a][(*b) + i] != 'A';)
			{
				position((*b) + i, *a);
				TURN_DARKRED;
				printf(" ");
				Sleep(100);
				position((*b) + i, *a);
				TURN_RED;
				printf(" ");
				i++;
			}
			for (int count = 0; map[*a][(*b) + i] == 'A'&&count < destroy; count++)
			{
				map[*a][(*b) + i] = 'B';
				position((*b) + i, *a);
				TURN_RED;
				printf(" ");
				Sleep(300);
				i++;
			}
			break;
		}
		}
}

void fail(int *a, int *b, int original_a, int original_b)
{
	*a = original_a;
	*b = original_b;
	sound_fail();
	position(0, 0);
	TURN_WHITE;
	printf("荊");
	Sleep(300);
	printf("棘");
	Sleep(300);
	printf("陷");
	Sleep(300);
	printf("阱");
	Sleep(1000);
	position(0, 0);
	printf("        ");
}

bool check(char map[WIDTH][LENGTH + 1], int *a, int *b, int speed, int destroy,int original_b)
{
	if (*a >= 26 && *a < 28 && *b >= 116 && (speed == 10 || destroy == 2 || original_b == 24))
	{
		system("color F0");
		sound();
		position(0, 0);
		for (int i = 10; i >= 1; i--)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				for (int y = 0; y < LENGTH; y++)
				{
					int dice = random(10);
					if (dice <= i)
						switch (map[x][y])
						{
						case 'A':printf("*"); break;
						case 'B':printf(" "); break;
						case 'C':printf("O"); break;
						case 'H':
						case 'S':
						case 'Z':printf("+"); break;
						}
					else printf(" ");
				}
			}
			Sleep(10);
		}
		Sleep(1200);
		return true;
	}
	else return false;
}