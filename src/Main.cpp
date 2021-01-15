#include "MemorySnap.h"
#include "MathLib.h"
#include<iostream>
#include "Debug.h"
#include "BGI/include/graphics.h"
#include "MemoryBuffer.h"

int main()
{
	InitMemSnap();

	MemRecordStart();
	{		
		x_vertex2 v1;
		v1.x = 2;
		v1.y = 4;

		x_vertex2 v2;
		v2.x = 1;
		v2.y = 5;

		x_vertex2 vertexData[] = 
		{
			v1, v2
		};

		x_vertexBuffer vb;
		GenVertexBuffer(&vb, 2, vertexData);

		for (int i = 0; i < 2; i++)
		{
			std::cout << vb.vertexBufferPtr[i].x << " " << vb.vertexBufferPtr[i].y << std::endl;
		}

		DeleteVertexBuffer(vb);
	}
	MemRecordStop();
	DisplayMemStatus();

	_CrtDumpMemoryLeaks();
	system("pause");
	return -1;
}