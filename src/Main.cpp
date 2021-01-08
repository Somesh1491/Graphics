#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>

int main()
{
	InitMemSnap();

	MemRecordStart();
	{
		
	}
	MemRecordStop();
	DisplayMemStatus();

	MemRecordStart();
	{
		
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}