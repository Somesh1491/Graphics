#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>
#include "Debug.h"

int main()
{
	InitMemSnap();

	MemRecordStart();
	{		

		Vector2 v1;
		v1.Randomize();	

		Vector2 v2;
		v2.Randomize();

		v1.print();
		v2.print();

		Vector2 v3;
		v3.Randomize();

		v3.print();

	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}