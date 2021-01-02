#include "Math.h"

/*.........................FUNCTION DECLARATIONS.............................*/
void DotProductMultiplication(const Matrix& matrix1, const Matrix& matrix2, Matrix& resultMatrix);

Matrix CreateMatrix(int row, int column)
{
	Matrix matrix;
	matrix.matrixPtr = (float**)malloc(sizeof(float*) * row);

	for (int i = 0; i < row; i++)
	{
		matrix.matrixPtr[i] = (float*)calloc(column, sizeof(float));
	}

	matrix.row = row;
	matrix.column = column;

	return matrix;
}

Matrix CreateMatrixIdentity(int dimension)
{
	Matrix matrix;
	matrix.matrixPtr = (float**)malloc(sizeof(float*) * dimension);

	for (int i = 0; i < dimension; i++)
	{
		matrix.matrixPtr[i] = (float*)calloc(dimension, sizeof(float));
		matrix.matrixPtr[i][i] = 1;
	}

	matrix.row = dimension;
	matrix.column = dimension;

	return matrix;
}

void SetRow(int row, Matrix& matrix, VectorN& rowVector)
{
	/*................Precondition for Setting Row............................*/
	assert(matrix.column == rowVector.size);

	for (int i = 0; i < rowVector.size; i++)
	{
		matrix.matrixPtr[row][i] = rowVector.vectorPtr[i];
	}
}

void SetColumn(int column, Matrix& matrix, VectorN& columnVector)
{
	/*................Precondition for Setting Column............................*/
	assert(matrix.row == columnVector.size);

	for (int i = 0; i < columnVector.size; i++)
	{
		matrix.matrixPtr[i][column] = columnVector.vectorPtr[i];
	}
}

void DeleteMatrix(Matrix& matrix)

{

	free(matrix.matrixPtr);
}

Matrix operator * (const Matrix& matrix1, const Matrix& matrix2)
{
	//check precondition of matrix multiplication
	assert(matrix1.column == matrix2.row);

	Matrix resultMatrix = CreateMatrix(matrix1.row, matrix2.column);
	resultMatrix.row = matrix1.row;
	resultMatrix.column = matrix2.column;

	DotProductMultiplication(matrix1, matrix2, resultMatrix);

	return resultMatrix;
}

/*..........................Simple DOT Product Matrix Multiplication*/
void DotProductMultiplication(const Matrix& matrix1, const Matrix& matrix2, Matrix& resultMatrix)
{
	//Multiplication Logic
	for (int i = 0; i < matrix1.row; i++)
	{
		for (int j = 0; j < matrix2.column; j++)
		{
			for (int k = 0; k < matrix1.column; k++)
			{
				resultMatrix.matrixPtr[i][j] += matrix1.matrixPtr[i][k] * matrix2.matrixPtr[k][j];
			}
		}
	}
}

VectorN CreateVector(int size)
{
	VectorN vector;
	vector.vectorPtr = (float*)calloc(size, sizeof(float));
	vector.size = size;

	return vector;
}

void DeleteVector(VectorN & vector)
{
	free(vector.vectorPtr);
}

float operator*(const VectorN& vector1, const VectorN& vector2)
{
	//check precondition of vector dot product 
	assert(vector1.size == vector2.size);

	float sum = 0;
	for (int i = 0; i < vector1.size; i++)
	{
		sum += (vector1.vectorPtr[i] * vector2.vectorPtr[i]);
	}

	return sum;
}

VectorN operator*(const float& scaler, const VectorN& vector)
{
	VectorN resultVector = CreateVector(vector.size);	
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] *= scaler;

	return resultVector;
}

VectorN operator*(const VectorN& vector, const float& scaler)
{
	VectorN resultVector = CreateVector(vector.size);
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] *= scaler;

	return resultVector;
}

void print(Matrix& matrix)
{
	for (int i = 0; i < matrix.row; i++)
	{
		printf("[ ");
		for (int j = 0; j < matrix.column; j++)
		{
			printf("%.2f ", matrix.matrixPtr[i][j]);
		}
		printf(" ]\n");
	}
}

void print(VectorN& vector)
{
	printf("[ ");
	for (int i = 0; i < vector.size; i++)
	{
		printf("%.2f ", vector.vectorPtr[i]);
	}
	printf(" ]\n");
}


