#include "pch.h"
#include <iostream>
#include "to_baobao.h"

void sound()
{
	for (int i = 100; i <= 1000; i += 100)
		Beep(i, 100);
}	


void sound_fail()
{
	for (int i = 1000; i > 0; i -= 100)
		Beep(i, 100);
}
