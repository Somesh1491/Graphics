#pragma once

#include<iostream>
#include<assert.h>
#include<time.h>

struct x_matrix;
struct x_vector;

struct x_matrix
{
	x_vector* vector;
	int row;
	int column;
};

void CreateMatrix(int row, int column, x_matrix& matrix);
void CreateMatrixIdentity(int dimension, x_matrix& matrix);
void GetRandomMatrix(int row, int column, x_matrix&matrix);
bool  isInvertible(x_matrix& matrix);
void GetInverseMatrix(x_matrix& matrix, x_matrix& inverseMatrix);
void SetRow(int row, x_matrix& matrix, const float* data);
void SetColumn(int column, x_matrix& matrix, const float* data);
void DeleteMatrix(x_matrix& matrix);
void MultiplyMatrix(const x_matrix& matrix1, const x_matrix& matrix2, x_matrix& resultMatrix);
/*..........................Return a Row Vector.............*/
void MultiplyMatrixWithVector(const x_vector& vector, const x_matrix& matrix, x_vector& resultVector);
/*..........................Return a Column Vector.............*/
void MultiplyMatrixWithVector(const x_matrix& matrix, const x_vector& vector, x_vector& resultVector);

struct x_vector
{
	float* vectorPtr;
	int size;
};

void CreateVector(int size, x_vector& resultVector);
void GetRandomVector(int size, x_vector& resultVector);
void DeleteVector(x_vector& vector);

/*......................DOT PRODUCT.....................*/
float DotProduct (const x_vector& vector1, const x_vector& vector2);

/*......................Scaler Multiplication*/
x_vector MultiplyVector (const float& scaler, const x_vector& vector, x_vector& resultVector);
x_vector MultiplyVector (const x_vector& vector, const float& scaler, x_vector& resultVector);

/*......................Addition And Substraction*........*/
void AddVector(const x_vector& vector1, const x_vector& vector2, x_vector& resultVector);
void SubVector(const x_vector& vector1, const x_vector& vector2, x_vector& resultVector);

/*...................... L O G S.......................*/
void print(const x_matrix& matrix);
void print(const x_vector& vector);