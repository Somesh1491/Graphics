#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>
#include "Debug.h"

int main()
{
	InitMemSnap();

	MemRecordStart();
	{		
		Vector4 v1;
		v1.SetVector(2, 3, 4, 2);

		Vector4 v2(1, 5, 3, 1);
		v1.print();
		v2.print();

		Vector4 v3(9, 5, 1, 5);
		v3.print();

		Vector4 v4 = 3 * v1 + v2 + v3;
		v4.print();
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return -1;
}