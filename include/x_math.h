#pragma once

#include<iostream>
#include<assert.h>
#include<time.h>

struct x_matrix;
struct x_vectorN;

struct x_matrix
{
	x_vectorN* vector;
	int row;
	int column;
};

void CreateMatrix(int row, int column, x_matrix& matrix);
void CreateMatrixIdentity(int dimension, x_matrix& matrix);
void MakeMatrixIdentity(x_matrix& matrix);
void GetRandomMatrix(int row, int column, x_matrix&matrix);
void Randomize(x_matrix& matrix);
void GetUpperTriangularMatrix(x_matrix& matrix, x_matrix& resultMatrix);
void GetLowerTriangularMatrix(x_matrix& matrix, x_matrix& resultMatrix);
float GetDeterminant(x_matrix& matrix);
bool isInvertible(x_matrix& matrix);
void GetInverseMatrix(x_matrix& matrix, x_matrix& inverseMatrix);
void SetRow(int row, x_matrix& matrix, const float* data);
void SetColumn(int column, x_matrix& matrix, const float* data);
void CopyMatrix(x_matrix& matrix, x_matrix& resultMatrix);
void DeleteMatrix(x_matrix& matrix);
void MultiplyMatrix(const x_matrix& matrix1, const x_matrix& matrix2, x_matrix& resultMatrix);
/*..........................Return a Row Vector.............*/
void MultiplyMatrixWithVector(const x_vectorN& vector, const x_matrix& matrix, x_vectorN& resultVector);
/*..........................Return a Column Vector.............*/
void MultiplyMatrixWithVector(const x_matrix& matrix, const x_vectorN& vector, x_vectorN& resultVector);

struct x_vectorN
{
	float* vectorPtr;
	int size;
};

void CreateVector(int size, x_vectorN& resultVector);
void SetVector(x_vectorN vector, float* data);
void GetRandomVector(int size, x_vectorN& resultVector);
void Randomize(x_vectorN& vector);
void DeleteVector(x_vectorN& vector);

/*......................DOT PRODUCT.....................*/
float DotProduct (const x_vectorN& vector1, const x_vectorN& vector2);

/*......................Scaler Multiplication*/
x_vectorN MultiplyVector (const float& scaler, const x_vectorN& vector, x_vectorN& resultVector);

x_vectorN MultiplyVector(const float& scaler, x_vectorN& vector);
/*......................Addition And Substraction*........*/
void AddVector(const x_vectorN& vector1, const x_vectorN& vector2, x_vectorN& resultVector);
void SubVector(const x_vectorN& vector1, const x_vectorN& vector2, x_vectorN& resultVector);

void CopyVector(const x_vectorN& vector, x_vectorN& resultVector);
/*...................... L O G S.......................*/
void print(const x_matrix& matrix);
void print(const x_vectorN& vector);