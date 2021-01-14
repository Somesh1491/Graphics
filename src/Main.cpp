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
		Vector2 v1;
		Vector3 v2;
		Vector4 v3;
		Log(v1);
		Log(v2);
		Log(v3);

		printf("\n");

		Matrix2x2 m1;
		Matrix3x3 m2;
		Matrix4x4 m3;
		Log(m1);
		Log(m2);
		Log(m3);

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