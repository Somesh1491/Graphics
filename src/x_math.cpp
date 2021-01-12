#include "x_math.h"

int randomSeedsFlag = 0;
/*.........................FUNCTION DECLARATIONS.............................*/
void DotProductMultiplication(const x_matrix& matrix1, const x_matrix& matrix2, x_matrix& resultMatrix);

void CreateMatrix(int row, int column, x_matrix& matrix)
{
	matrix.vector = (x_vectorN*)malloc(sizeof(x_vectorN) * row);

	for (int i = 0; i < row; i++)
	{
		CreateVector(column, matrix.vector[i]);
	}

	matrix.row = row;
	matrix.column = column;
}

void CreateMatrixIdentity(int dimension, x_matrix& matrix)
{
	matrix.vector = (x_vectorN*)malloc(sizeof(x_vectorN) * dimension);

	for (int i = 0; i < dimension; i++)
	{
		CreateVector(dimension, matrix.vector[i]);
		matrix.vector[i].vectorPtr[i] = 1;
	}

	matrix.row = dimension;
	matrix.column = dimension;
}

void MakeMatrixIdentity(x_matrix & matrix)
{
	assert(matrix.row == matrix.column);

	for (int i = 0; i < matrix.row; i++)
		matrix.vector[i].vectorPtr[i] = 1;
}

void GetRandomMatrix(int row, int column, x_matrix& matrix)
{
	srand(time(0));	

	CreateMatrix(row, column, matrix);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix.vector[i].vectorPtr[j] = (rand() % 15) + 1;
}

void Randomize(x_matrix & matrix)
{
}

//Right now we assume that all matrix has non-zero pivot later we update the logic
void GetUpperTriangularMatrix(x_matrix & matrix, x_matrix & resultMatrix)
{
	//Must be square matrix
	assert(matrix.row == matrix.column);

	CopyMatrix(matrix, resultMatrix);
	//Upper Row
	for (int i = 0; i < resultMatrix.row - 1; i++)
	{
		bool canFindNonZeroPivot = false;
		//if ith row pivot is zero.
		if (resultMatrix.vector[i].vectorPtr[i] == 0)
		{
			//check entire ith column to find non zero entry
			for (int row = i + 1; row < resultMatrix.row; row++)
			{
				if (resultMatrix.vector[row].vectorPtr[i] != 0)
				{
					canFindNonZeroPivot = true;
					//swap rows
					for (int l = 0; l < resultMatrix.column; l++)
					{						
						float temp = resultMatrix.vector[i].vectorPtr[l];
						resultMatrix.vector[i].vectorPtr[l] = resultMatrix.vector[row].vectorPtr[l];
						resultMatrix.vector[row].vectorPtr[l] = temp;
					}
				}
			}
		}

		if (!canFindNonZeroPivot)
			break;
		//Lower Row
		for (int j = i + 1; j < resultMatrix.row; j++)
		{
			float multiplier = (resultMatrix.vector[j].vectorPtr[i]) / (resultMatrix.vector[i].vectorPtr[i]);
			for (int k = 0; k < resultMatrix.column; k++)
			{
				resultMatrix.vector[j].vectorPtr[k] = (resultMatrix.vector[j].vectorPtr[k]) - (multiplier * resultMatrix.vector[i].vectorPtr[k]);
			}
		}
	}
}

//Right now we assume that all matrix has non-zero pivot later we update the logic
void GetLowerTriangularMatrix(x_matrix & matrix, x_matrix & resultMatrix)
{
	//Must be square matrix
	assert(matrix.row == matrix.column);

	CopyMatrix(matrix, resultMatrix);
	//Upper Row
	for (int i = resultMatrix.row - 1; i > 0; i--)
	{
		bool canFindNonZeroPivot = false;
		//if ith row pivot is zero.
		if (resultMatrix.vector[i].vectorPtr[i] == 0)
		{
			//check entire ith column to find non zero entry
			for (int row = i + 1; row < resultMatrix.row; row++)
			{
				if (resultMatrix.vector[row].vectorPtr[i] != 0)
				{
					canFindNonZeroPivot = true;
					//swap rows
					for (int l = 0; l < resultMatrix.column; l++)
					{
						float temp = resultMatrix.vector[i].vectorPtr[l];
						resultMatrix.vector[i].vectorPtr[l] = resultMatrix.vector[row].vectorPtr[l];
						resultMatrix.vector[row].vectorPtr[l] = temp;
					}
				}
			}
		}

		if (!canFindNonZeroPivot)
			break;

		//Lower Row
		for (int j = i - 1; j >= 0; j--)
		{
			float multiplier = (resultMatrix.vector[j].vectorPtr[i]) / (resultMatrix.vector[i].vectorPtr[i]);
			for (int k = 0; k < resultMatrix.column; k++)
			{
				resultMatrix.vector[j].vectorPtr[k] = (resultMatrix.vector[j].vectorPtr[k]) - (multiplier * resultMatrix.vector[i].vectorPtr[k]);
			}
		}
	}
}

float GetDeterminant(x_matrix & matrix)
{
	assert(matrix.row == matrix.column);

	float det = 1;
	x_matrix upperTriangularMatrix;
	GetUpperTriangularMatrix(matrix, upperTriangularMatrix);

	for (int i = 0; i < upperTriangularMatrix.row; i++)
		det *= upperTriangularMatrix.vector[i].vectorPtr[i];

	DeleteMatrix(upperTriangularMatrix);

	return det;
}

bool isInvertible(x_matrix& matrix)
{	
	return (GetDeterminant(matrix) != 0) ? true : false;
}

/*...........................Gauss Jordan Elimination Approach....................*/
void GetInverseMatrix(x_matrix& matrix, x_matrix& inverseMatrix)
{
	//Must be sqaure matrix
	assert(matrix.row == matrix.column);
    //Inverse must exist
	assert(isInvertible(matrix));

	//make inverse matrix identity
	x_matrix tempMatrix;
	CopyMatrix(matrix, tempMatrix);
	CreateMatrixIdentity(matrix.row, inverseMatrix);

	//UpperTriangle Conversion
	for (int i = 0; i < tempMatrix.row - 1; i++)
	{
		bool canFindNonZeroPivot = false;
		//if ith row pivot is zero.
		if (tempMatrix.vector[i].vectorPtr[i] == 0)
		{
			//check entire ith column to find non zero entry
			for (int row = i + 1; row < tempMatrix.row; row++)
			{
				if (tempMatrix.vector[row].vectorPtr[i] != 0)
				{
					canFindNonZeroPivot = true;
					//swap rows
					for (int l = 0; l < tempMatrix.column; l++)
					{
						float temp = tempMatrix.vector[i].vectorPtr[l];
						tempMatrix.vector[i].vectorPtr[l] = tempMatrix.vector[row].vectorPtr[l];
						tempMatrix.vector[row].vectorPtr[l] = temp;
					}

					//swap inverse matrix row
					for (int l = 0; l < tempMatrix.column; l++)
					{
						float temp = inverseMatrix.vector[i].vectorPtr[l];
						inverseMatrix.vector[i].vectorPtr[l] = inverseMatrix.vector[row].vectorPtr[l];
						inverseMatrix.vector[row].vectorPtr[l] = temp;
					}
				}
			}
		}

		if (!canFindNonZeroPivot)
			break;

		for (int j = i + 1; j < tempMatrix.row; j++)
		{
			float multiplier = (tempMatrix.vector[j].vectorPtr[i]) / (tempMatrix.vector[i].vectorPtr[i]);
			for (int k = 0; k < tempMatrix.column; k++)
			{
				tempMatrix.vector[j].vectorPtr[k] = (tempMatrix.vector[j].vectorPtr[k]) - (multiplier * tempMatrix.vector[i].vectorPtr[k]);

				//Same operation applied in Inverse matrix
				inverseMatrix.vector[j].vectorPtr[k] = (inverseMatrix.vector[j].vectorPtr[k]) - (multiplier * inverseMatrix.vector[i].vectorPtr[k]);
			}
		}
	}

	//LowerTriangle Conversion
	for (int i = tempMatrix.row - 1; i > 0; i--)
	{
		//Lower Row
		for (int j = i - 1; j >= 0; j--)
		{
			float multiplier = (tempMatrix.vector[j].vectorPtr[i]) / (tempMatrix.vector[i].vectorPtr[i]);
			for (int k = 0; k < tempMatrix.column; k++)
			{
				tempMatrix.vector[j].vectorPtr[k] = (tempMatrix.vector[j].vectorPtr[k]) - (multiplier * tempMatrix.vector[i].vectorPtr[k]);
				
				//Same operation applied in Inverse matrix
				inverseMatrix.vector[j].vectorPtr[k] = (inverseMatrix.vector[j].vectorPtr[k]) - (multiplier * inverseMatrix.vector[i].vectorPtr[k]);
			}
		}
	}

	//divide by pivot to make temp matrix identity
	for (int i = 0; i < inverseMatrix.row; i++)
	{
		float multiplier = 1.0f / tempMatrix.vector[i].vectorPtr[i];
		MultiplyVector(multiplier, inverseMatrix.vector[i], inverseMatrix.vector[i]);
	}

	DeleteMatrix(tempMatrix);
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

void CopyMatrix(x_matrix& matrix, x_matrix& resultMatrix)
{
	CreateMatrix(matrix.row, matrix.column, resultMatrix);

	for (int i = 0; i < matrix.row; i++)
		memcpy(resultMatrix.vector[i].vectorPtr, matrix.vector[i].vectorPtr, sizeof(float) * matrix.vector[i].size);
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

void MultiplyMatrixWithVector(const x_vectorN& vector, const x_matrix& matrix, x_vectorN& resultVector)
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

void MultiplyMatrixWithVector(const x_matrix& matrix, const x_vectorN& vector, x_vectorN& resultVector)
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

void CreateVector(int size, x_vectorN& resultVector)
{
	resultVector.vectorPtr = (float*)calloc(size, sizeof(float));
	resultVector.size = size;
}

void SetVector(x_vectorN vector, float * data)
{
	for (int i = 0; i < vector.size; i++)
	{
		vector.vectorPtr[i] = data[i];
	}
}

void GetRandomVector(int size, x_vectorN& resultVector)
{
	srand(randomSeedsFlag++);
	
	CreateVector(size, resultVector);
	for (int i = 0; i < resultVector.size; i++)
	{
		resultVector.vectorPtr[i] = rand() % 10;
	}
}

void Randomize(x_vectorN & vector)
{
	srand(randomSeedsFlag++);

	for (int i = 0; i < vector.size; i++)
	{
		vector.vectorPtr[i] = rand() % 10;
	}
}

void DeleteVector(x_vectorN& vector)
{
	free(vector.vectorPtr);
}

float DotProduct(const x_vectorN& vector1, const x_vectorN& vector2)
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

x_vectorN MultiplyVector(const float& scaler, const x_vectorN& vector, x_vectorN& resultVector)
{	
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector.vectorPtr[i] * scaler;

	return resultVector;
}

void AddVector(const x_vectorN& vector1, const x_vectorN& vector2, x_vectorN& resultVector)
{
	//check precondition of vector dot product 
	assert(vector1.size == vector2.size);

	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector1.vectorPtr[i] + vector2.vectorPtr[i];
}

void SubVector(const x_vectorN& vector1, const x_vectorN& vector2, x_vectorN& resultVector)
{
	//check precondition of vector dot product 
	assert(vector1.size == vector2.size);

	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector1.vectorPtr[i] - vector2.vectorPtr[i];
}

void CopyVector(const x_vectorN & vector, x_vectorN & resultVector)
{
	CreateVector(vector.size, resultVector);
	memcpy(resultVector.vectorPtr, vector.vectorPtr, sizeof(float) * vector.size);
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

void print(const x_vectorN& vector)
{
	printf("[ ");
	for (int i = 0; i < vector.size; i++)
	{
		printf("%.2f ", vector.vectorPtr[i]);
	}
	printf(" ]\n");
}
