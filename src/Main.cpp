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
		m1.SetRow(0, Vector2(1, 5));
		m1.SetRow(1, Vector2(3, 1));
		//m1.ToUpperTriangularMatrix();
		m1.print();
		printf("\n");
		Matrix2x2 m2 = m1.GetLowerTriangularMatrix();
		m2.print();

		float d = m1.GetDeterminant();
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return -1;
}