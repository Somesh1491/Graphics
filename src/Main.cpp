#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>

int main()
{
	InitMemSnap();

	MemRecordStart();
	{
		x_matrix m1;
		GetRandomMatrix(3, 4, m1);

		x_matrix m2;
		CopyMatrix(m1, m2);

		m1.vector[1].vectorPtr[2] = 12345;

		print(m1);
		printf("\n");
		print(m2);
		printf("\n");

		DeleteMatrix(m1);
		DeleteMatrix(m2);
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}