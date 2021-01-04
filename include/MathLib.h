#pragma once

#include<iostream>
#include<assert.h>
#include "Timer.h"

struct Matrix;
struct VectorN;

struct Matrix
{
	float** matrixPtr;
	int row;
	int column;
};

Matrix CreateMatrix(int row, int column);
Matrix CreateMatrixIdentity(int dimension);
Matrix GetRandomMatrix(int row, int column);
void SetRow(int row, Matrix& matrix, VectorN& rowVector);
void SetColumn(int column, Matrix& matrix, VectorN& columnVector);
void DeleteMatrix(Matrix& matrix);
Matrix operator * (const Matrix& matrix1, const Matrix& matrix2);
/*..........................Return a Row Vector.............*/
VectorN operator * (const VectorN& vector, const Matrix& matrix);
/*..........................Return a Column Vector.............*/
VectorN operator * (const Matrix& matrix, const VectorN& vector);

struct VectorN
{
	float* vectorPtr;
	int size;
};

VectorN CreateVector(int size);
VectorN GetRandomVector(int size);
void DeleteVector(VectorN& vector);

/*......................DOT PRODUCT.....................*/
float operator * (const VectorN& vector1, const VectorN& vector2);

/*......................Scaler Multiplication*/
VectorN operator * (const float& scaler, const VectorN& vector);
VectorN operator * (const VectorN& vector, const float& scaler);

/*......................Addition And Substraction*........*/
VectorN operator+(const VectorN& vector1, const VectorN& vector2);
VectorN operator-(const VectorN& vector1, const VectorN& vector2);

/*...................... L O G S.......................*/
void print(Matrix& matrix);
void print(VectorN& vector);