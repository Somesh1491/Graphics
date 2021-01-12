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
		v1.SetVector(2, 3);

		Vector2 v2(1, 5);
		v1.print();
		v2.print();

		Vector2 v3 = v1 * 4.0f;
		v3.print();
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return -1;
}