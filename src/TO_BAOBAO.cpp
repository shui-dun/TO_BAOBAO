#include "pch.h"
#include <iostream>
#include "to_baobao.h"

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	bool music2 = true;
	system("mode con cols=120 lines=30");
	srand((unsigned)time(0));
	int a, b;
	cover(&music2);
	enter_animation();
	maze_enter();
	
	a = 2;
	b = 2;
	show(map1);                 //maze love
	system("color F0");
	print(map1);
	move(map1, &a, &b);
	
	a = 27;
	b = 15;
	show(map2);            //maze for
	system("color F0");
	print(map2);
	move(map2, &a, &b);
	
	a = 27;
	b = 24;
	show(map3);               //maze ever
	system("color F0");
	print(map3);
	move(map3, &a, &b);
	
	end_animation(music2);
	system("pause>nul");
}

//查找代码行数：^b*[^:b#/]+.*$
