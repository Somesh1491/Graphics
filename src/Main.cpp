#include "MemorySnap.h"
#include "Maths/MathLib.h"
#include<iostream>
#include "Debug.h"
#include "Timer.h"
#include "BGI/include/graphics.h"
#include "Graphics/RenderFunctions.h"

void Sum()
{
	int i = 0;
}

int main()
{
	InitMemSnap();

	MemRecordStart();
	{	
		int window = initwindow(800, 600);

		x_vertex2 point1;
		point1.x = 100;
		point1.y = 200;

		x_vertex2 point2;
		point2.x = 300;
		point2.y = 100;

		x_vertex2 vertexData[] =
		{
			point1,
			point2
		};

		x_vertexBuffer* vb = GenVertexBuffer();
		VertexBufferData(vb, 2, vertexData);

		x_frameBuffer* fb = GenFrameBuffer();
		
		Draw(x_Geometry::X_LINE);
		DisplayBitMapFrameBuffer();

		DeleteVertexBuffer(vb);
		DeleteFrameBuffer(fb);
	}
	MemRecordStop();
	DisplayMemStatus();

	system("pause");
	return -1;
}