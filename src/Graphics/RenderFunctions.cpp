#include "Graphics/RenderFunctions.h"

extern x_vertexBuffer* activeVertexBuffer;
extern x_frameBuffer* activeFrameBuffer;

void Line(int x1, int y1, int x2, int y2);
void Mid_Point_Line_Algorithm(int x1, int y1, int x2, int y2, int octant);

void Draw(x_Geometry geometry)
{
	switch (geometry)
	{	
	case X_LINE:
		for (int i = 0; i < activeVertexBuffer->vertexCount; i+=2)
		{
			x_vertex2* vertex2 = activeVertexBuffer->vertexBufferPtr;
			Line(round(vertex2[i].x), round(vertex2[i].y), round(vertex2[i + 1].x), round(vertex2[i + 1].y));
		}
		break;
	default:
		break;
	}

	/*........................Draw FrameBuffer's Pixel Data onto screen...........................*/
	for (int i = 0; i < activeFrameBuffer->height; i++)
	{
		for (int j = 0; j < activeFrameBuffer->width; j++)
		{
			if(activeFrameBuffer->pixelPtr[i][j].pixelFlag == true)
				putpixel(j, i, WHITE);
		}
	}
}

/*..........................LINE PRIMITIVE..........................*/
void Line(int x1, int y1, int x2, int y2)
{
	int dy = y2 - y1;
	int dx = x2 - x1;

	float slope = (float)dy / dx;

	if (slope >= 0) // 1st 2nd 5th 6th octant
	{
		if (abs(dx) > abs(dy))  //slope is b/w zero and one (1st 5th octant)
		{
			if (x2 > x1) //point is in 1st octant
			{
				Mid_Point_Line_Algorithm(x1, y1, x2, y2, 1);
			}

			else  //point is in 5th octant
			{
				Mid_Point_Line_Algorithm(-x1, -y1, -x2, -y2, 5);
			}
		}

		else         //slope is grater than one (2nd and 6th octant)
		{
			if (y2 > y1) //point is 2nd octant
			{
				Mid_Point_Line_Algorithm(y1, x1, y2, x2, 2);
			}

			else
			{
				Mid_Point_Line_Algorithm(-y1, -x1, -y2, -x2, 6);
			}
		}
	}

	else //3rd 4th 7th 8th octant
	{
		if (abs(dx) > abs(dy))  //point is in 4th and 8th octant 
		{
			if (x2 > x1)  //point is in 8th octant
			{
				Mid_Point_Line_Algorithm(x1, -y1, x2, -y2, 8);
			}

			else      //point is in 4th octant
			{
				Mid_Point_Line_Algorithm(-x1, y1, -x2, y2, 4);
			}
		}

		else   //point is in 3rd and 7th octant 
		{
			if (y2 > y1)   //3rd octatant
			{
				Mid_Point_Line_Algorithm(y1, -x1, y2, -x2, 3);
			}

			else //7th octant
			{
				Mid_Point_Line_Algorithm(-y1, x1, -y2, x2, 7);
			}
		}
	}
}

void Mid_Point_Line_Algorithm(int x1, int y1, int x2, int y2, int octant)
{
	int x = x1; int y = y1;
	int dy = y2 - y1;
	int dx = x2 - x1;

	int d = 2 * dy - dx;
	int delta_E = 2 * dy;
	int delta_NE = 2 * (dy - dx);

	switch (octant)
	{
	case 1:
		activeFrameBuffer->pixelPtr[y][x].pixelFlag = true;
		break;
	case 2:
		activeFrameBuffer->pixelPtr[x][y].pixelFlag = true;
		break;
	case 3:
		activeFrameBuffer->pixelPtr[x][-y].pixelFlag = true;
		break;
	case 4:
		activeFrameBuffer->pixelPtr[y][-x].pixelFlag = true;
		break;
	case 5:
		activeFrameBuffer->pixelPtr[-y][-x].pixelFlag = true;
		break;
	case 6:
		activeFrameBuffer->pixelPtr[-x][-y].pixelFlag = true;
		break;
	case 7:
		activeFrameBuffer->pixelPtr[-x][y].pixelFlag = true;
		break;
	case 8:
		activeFrameBuffer->pixelPtr[-y][x].pixelFlag = true;
		break;
	default:
		break;
	}

	while (x < x2)
	{
		if (d <= 0) // Choose East Pixel
			d += delta_E;

		else        // Choose North East Pixel
		{
			d += delta_NE;
			y++;
		}

		x++;

		switch (octant)
		{
		case 1:
			activeFrameBuffer->pixelPtr[y][x].pixelFlag = true;
			break;
		case 2:
			activeFrameBuffer->pixelPtr[x][y].pixelFlag = true;
			break;
		case 3:
			activeFrameBuffer->pixelPtr[x][-y].pixelFlag = true;
			break;
		case 4:
			activeFrameBuffer->pixelPtr[y][-x].pixelFlag = true;
			break;
		case 5:
			activeFrameBuffer->pixelPtr[-y][-x].pixelFlag = true;
			break;
		case 6:
			activeFrameBuffer->pixelPtr[-x][-y].pixelFlag = true;
			break;
		case 7:
			activeFrameBuffer->pixelPtr[-x][y].pixelFlag = true;
			break;
		case 8:
			activeFrameBuffer->pixelPtr[-y][x].pixelFlag = true;
			break;
		default:
			break;
		}
	}
}

