#include "MathLib.h"

/*.........................FUNCTION DECLARATIONS.............................*/
void DotProductMultiplication(const Matrix& matrix1, const Matrix& matrix2, Matrix& resultMatrix);

Matrix CreateMatrix(int row, int column)
{
	
	Matrix matrix;
	matrix.vector = (VectorN*)malloc(sizeof(VectorN) * row);

	for (int i = 0; i < row; i++)
	{
		matrix.vector[i] = CreateVector(column);
	}

	matrix.row = row;
	matrix.column = column;

	return matrix;
}

Matrix CreateMatrixIdentity(int dimension)
{
	Matrix matrix;
	matrix.vector = (VectorN*)malloc(sizeof(VectorN) * dimension);

	for (int i = 0; i < dimension; i++)
	{
		matrix.vector[i] = CreateVector(dimension);
		matrix.vector[i].vectorPtr[i] = 1;
	}

	matrix.row = dimension;
	matrix.column = dimension;

	return matrix;
}

Matrix GetRandomMatrix(int row, int column)
{
	srand(time(0));
	Matrix matrix = CreateMatrix(row, column);
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix.vector[i].vectorPtr[j] = rand() % 15;

	return matrix;
}

void SetRow(int row, Matrix& matrix, const float* rowData)
{
	for (int i = 0; i < matrix.column; i++)
	{
		matrix.vector[row].vectorPtr[i] = rowData[i];
	}
}

void SetColumn(int column, Matrix& matrix, const float* columnData)
{
	for (int i = 0; i < matrix.row; i++)
	{
		matrix.vector[i].vectorPtr[column] = columnData[i];
	}
}

void DeleteMatrix(Matrix& matrix)
{
	for (int i = 0; i < matrix.row; i++)
		DeleteVector(matrix.vector[i]);

	free(matrix.vector);
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

VectorN operator * (const VectorN& vector, const Matrix& matrix)
{
	assert(vector.size == matrix.row);

	//MemRecordStart();
	VectorN resultVector = CreateVector(matrix.column);	
	/*....................Adding Rows to get Final reusultant Vector........*/
	/*for (int i = 0; i < matrix.row; i++)
	{
		VectorN tempMultiplicationResult = vector.vectorPtr[i] * matrix.vector[i];
		resultVector = resultVector + tempMultiplicationResult;
		
		//Delete Memory of Temp Result;
		DeleteVector(tempMultiplicationResult);
	}*/
	//MemRecordStop();
	//std::cout << "Inside" << std::endl;
	//DisplayMemStatus();
	return resultVector;
}

VectorN operator * (const Matrix& matrix, const VectorN& vector)
{
	assert(vector.size == matrix.column);

	VectorN resultVector = CreateVector(matrix.row);

	VectorN* matrixToVectors = (VectorN*)malloc(sizeof(VectorN) * matrix.column);

	/*..................Converting Matrix Columns into Vectors...............*/
	for (int i = 0; i < matrix.column; i++)
	{
		matrixToVectors[i] = CreateVector(matrix.row);
		int k = 0;		
		for (int j = 0; j < matrixToVectors[i].size; j++)
		{
			matrixToVectors[i].vectorPtr[j] = matrix.vector[k].vectorPtr[i];
			k++;
		}
	}

	/*....................Adding Column to get Final reusultant Vector........*/
	for (int i = 0; i < matrix.column; i++)
	{
		resultVector = resultVector + (vector.vectorPtr[i] * matrixToVectors[i]);

		//Deleting Vector's Memory
		DeleteVector(matrixToVectors[i]);
	}
	
	//Deleting Pointer to Vector's Array
	free(matrixToVectors);

	return resultVector;
}

/*..........................Simple DOT Product Matrix Multiplication.............................*/
void DotProductMultiplication(const Matrix& matrix1, const Matrix& matrix2, Matrix& resultMatrix)
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

VectorN CreateVector(int size)
{
	VectorN vector;
	vector.vectorPtr = (float*)calloc(size, sizeof(float));
	vector.size = size;

	return vector;
}

VectorN GetRandomVector(int size)
{
	srand(time(0));
	VectorN vector = CreateVector(size);
	for (int i = 0; i < vector.size; i++)
		vector.vectorPtr[i] = rand() % 10;

	return vector;
}

void DeleteVector(VectorN& vector)
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
		resultVector.vectorPtr[i] = vector.vectorPtr[i] * scaler;

	return resultVector;
}

VectorN operator*(const VectorN& vector, const float& scaler)
{
	VectorN resultVector = CreateVector(vector.size);
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector.vectorPtr[i] * scaler;

	return resultVector;
}

VectorN operator+(const VectorN& vector1, const VectorN& vector2)
{
	//check precondition of vector dot product 
	assert(vector1.size == vector2.size);

	VectorN resultVector = CreateVector(vector1.size);
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector1.vectorPtr[i] + vector2.vectorPtr[i];

	return resultVector;
}

VectorN operator-(const VectorN& vector1, const VectorN& vector2)
{
	//check precondition of vector dot product 
	assert(vector1.size == vector2.size);

	VectorN resultVector = CreateVector(vector1.size);
	for (int i = 0; i < resultVector.size; i++)
		resultVector.vectorPtr[i] = vector1.vectorPtr[i] - vector2.vectorPtr[i];

	return resultVector;
}

void print(Matrix& matrix)
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

void print(VectorN& vector)
{
	printf("[ ");
	for (int i = 0; i < vector.size; i++)
	{
		printf("%.2f ", vector.vectorPtr[i]);
	}
	printf(" ]\n");
}
