#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>
#include "Debug.h"
#include "BGI/include/graphics.h"

int main()
{
	InitMemSnap();

	MemRecordStart();
	{		
		printf("Hello");
		initwindow(800, 600);

		line(200, 300, 400, 600);

		while (!kbhit())
		{
		}
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return -1;
}