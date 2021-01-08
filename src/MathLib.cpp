#include "MathLib.h"

/*.........................FUNCTION DECLARATIONS.............................*/
void DotProductMultiplication(const x_matrix& matrix1, const x_matrix& matrix2, x_matrix& resultMatrix);

void CreateMatrix(int row, int column, x_matrix& matrix)
{
	matrix.vector = (x_vector*)malloc(sizeof(x_vector) * row);

	for (int i = 0; i < row; i++)
	{
		CreateVector(column, matrix.vector[i]);
	}

	matrix.row = row;
	matrix.column = column;
}

void CreateMatrixIdentity(int dimension, x_matrix& matrix)
{
	matrix.vector = (x_vector*)malloc(sizeof(x_vector) * dimension);

	for (int i = 0; i < dimension; i++)
	{
		CreateVector(dimension, matrix.vector[i]);
		matrix.vector[i].vectorPtr[i] = 1;
	}

	matrix.row = dimension;
	matrix.column = dimension;
}

void GetRandomMatrix(int row, int column, x_matrix& matrix)
{
	srand(time(0));
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix.vector[i].vectorPtr[j] = rand() % 15;
}

bool isInvertible(x_matrix& matrix)
{
	return false;
}

/*...........................Gauss Jordan Elimination Approach....................*/
void GetInverseMatrix(x_matrix& matrix, x_matrix& inverseMatrix)
{
	//Must be sqaure matrix
	assert(matrix.row == matrix.column);
    //Inverse must exist
	assert(isInvertible(matrix));
}

void SetRow(int row, x_matrix& matrix, const float* rowData)
{
	for (int i = 0; i < matrix.column; i++)
	{
		matrix.vector[row].vectorPtr[i] = rowData[i];
	}
}

void SetColumn(int column, x_matrix& matrix, const float* columnData)
{
	for (int i = 0; i < matrix.row; i++)
	{
		matrix.vector[i].vectorPtr[column] = columnData[i];
	}
}

void DeleteMatrix(x_matrix& matrix)
{
	for (int i = 0; i < matrix.row; i++)
		DeleteVector(matrix.vector[i]);

	free(matrix.vector);
}

void MultiplyMatrix(const x_matrix& matrix1, const x_matrix& matrix2, x_matrix& resultMatrix)
{
	//check precondition of matrix multiplication
	assert(matrix1.column == matrix2.row);

	resultMatrix.row = matrix1.row;
	resultMatrix.column = matrix2.column;

	DotProductMultiplication(matrix1, matrix2, resultMatrix);
}

void MultiplyMatrixWithVector(const x_vector& vector, const x_matrix& matrix, x_vector& resultVector)
{
	assert(vector.size == matrix.row);
	
	CreateVector(matrix.column, resultVector);

	for (int i = 0; i < resultVector.size; i++)
	{
		int k = 0;
		for (int j = 0; j < matrix.row; j++)
		{
			resultVector.vectorPtr[i] += vector.vectorPtr[k] * matrix.vector[j].vectorPtr[i];
			k++;
		}
	}
}

void MultiplyMatrixWithVector(const x_matrix& matrix, const x_vector& vector, x_vector& resultVector)
{
	assert(vector.size == matrix.column);

	CreateVector(matrix.row, resultVector);

	for (int i = 0; i < resultVector.size; i++)
	{
		int k = 0;
		for (int j = 0; j < matrix.column; j++)
		{
			resultVector.vectorPtr[i] += matrix.vector[i].vectorPtr[j] * vector.vectorPtr[k];
			k++;
		}
	}
}

/*..........................Simple DOT Product Matrix Multiplication.............................*/
void DotProductMultiplication(const x_matrix& matrix1, const x_matrix& matrix2, x_matrix& resultMatrix)
{
	//Multiplication Logic
	for (int i = 0; i < matrix1.row; i++)
	{
		for (int j = 0; j < matrix2.column; j++)
		{
			for (int k = 0; k < matrix1.column; k++)
			{
				resultMatrix.vector[i].vectorPtr[j] += matrix1.vector[i].vectorPtr[k] * matrix2.vector[k].vectorPtr[j];
			}
		}
	}
}

void CreateVector(int size, x_vector& resultVector)
{
	resultVector.vectorPtr = (float*)calloc(size, sizeof(float));
	resultVector.size = size;
}

void GetRandomVector(int size, x_vector& resultVector)
{
	srand(time(0));
	CreateVector(size, resultVector);
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = rand() % 10;
}

void DeleteVector(x_vector& vector)
{
	free(vector.vectorPtr);
}

float DotProduct(const x_vector& vector1, const x_vector& vector2)
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

x_vector MultiplyVector(const float& scaler, const x_vector& vector, x_vector& resultVector)
{
	CreateVector(vector.size, resultVector);	
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector.vectorPtr[i] * scaler;

	return resultVector;
}

x_vector MultiplyVector(const x_vector& vector, const float& scaler, x_vector& resultVector)
{
	CreateVector(vector.size, resultVector);
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector.vectorPtr[i] * scaler;

	return resultVector;
}

void AddVector(const x_vector& vector1, const x_vector& vector2, x_vector& resultVector)
{
	//check precondition of vector dot product 
	assert(vector1.size == vector2.size);

	CreateVector(vector1.size, resultVector);
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector1.vectorPtr[i] + vector2.vectorPtr[i];
}

void SubVector(const x_vector& vector1, const x_vector& vector2, x_vector& resultVector)
{
	//check precondition of vector dot product 
	assert(vector1.size == vector2.size);

	CreateVector(vector1.size, resultVector);
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector1.vectorPtr[i] - vector2.vectorPtr[i];
}

void print(const x_matrix& matrix)
{
	for (int i = 0; i < matrix.row; i++)
	{
		printf("[ ");
		for (int j = 0; j < matrix.column; j++)
		{
			printf("%.2f ", matrix.vector[i].vectorPtr[j]);
		}
		printf(" ]\n");
	}
}

void print(const x_vector& vector)
{
	printf("[ ");
	for (int i = 0; i < vector.size; i++)
	{
		printf("%.2f ", vector.vectorPtr[i]);
	}
	printf(" ]\n");
}
