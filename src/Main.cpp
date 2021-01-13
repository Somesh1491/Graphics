#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>
#include "Debug.h"

int main()
{
	InitMemSnap();

	MemRecordStart();
	{		
		Matrix2x2 m1;
		m1.SetRow(0, Vector2(0, -1));
		m1.SetRow(1, Vector2(1, 0));

		m1.print();
		printf("\n");

		Matrix2x2 m2 = m1.GetInverseMatrix();
		m2.print();

	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return -1;
}