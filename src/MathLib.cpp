#include "MathLib.h"

Vector::Vector(int size)
{
	CreateVector(size, x_vector);
}

Vector::Vector(const Vector & vector)
{
	CreateVector(vector.x_vector.size, x_vector);
	CopyVector(vector.x_vector, x_vector);
}

Vector::~Vector()
{
	DeleteVector(x_vector);
}

void Vector::Randomize()
{
	::Randomize(x_vector);
}

Vector& Vector::operator=(const Vector & vector)
{
	CopyVector(vector.x_vector, x_vector);
	return *this;
}

float Vector::operator*(const Vector & vector)
{
	return ::DotProduct(x_vector, vector.x_vector);
}

void Vector::print()
{
	::print(x_vector);
}

Vector2::Vector2() : Vector(2), x(0), y(0)
{
}

Vector2::Vector2(const float & x, const float & y) : Vector(2), x(x), y(y)
{
	SetVector(x, y);
}

Vector2::Vector2(const Vector2 & vector) : Vector(vector)
{
	
}

Vector2::~Vector2()
{
	
}

void Vector2::SetVector(const float& x, const float& y)
{
	float data[] = { x, y };
	::SetVector(x_vector, data);
}

Vector2 Vector2::operator+(const Vector2 & vector)
{
	Vector2 resultVector;
	::AddVector(x_vector, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector2 Vector2::operator-(const Vector2 & vector)
{
	Vector2 resultVector;
	::SubVector(x_vector, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

float Vector2::getX() const
{
	return x;
}

float Vector2::getY() const
{
	return y;
}

/*.......................Friend Functions.................*/
Vector2 operator*(const float& scaler, const Vector2 & vector)
{
	Vector2 resultVector;
    ::MultiplyVector(scaler, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector2 operator*(const Vector2 & vector, const float & scaler)
{
	Vector2 resultVector;
	::MultiplyVector(scaler, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector2 operator*(const Matrix2x2 & matrix, const Vector2 & vector)
{
	Vector2 resultVector;
	::MultiplyMatrixWithVector(matrix.x_matrix, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector2 operator*(const Vector2 & vector, const Matrix2x2 & matrix)
{
	Vector2 resultVector;
	::MultiplyMatrixWithVector(vector.x_vector, matrix.x_matrix, resultVector.x_vector);

	return resultVector;
}

Vector3 operator*(const float & scaler, const Vector3 & vector)
{
	Vector3 resultVector;
	::MultiplyVector(scaler, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector3 operator*(const Vector3 & vector, const float & scaler)
{
	Vector3 resultVector;
	::MultiplyVector(scaler, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector4 operator*(const float & scaler, const Vector4 & vector)
{
	Vector4 resultVector;
	::MultiplyVector(scaler, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector4 operator*(const Vector4 & vector, const float & scaler)
{
	Vector4 resultVector;
	::MultiplyVector(scaler, vector.x_vector, resultVector.x_vector);

	return resultVector;
}
/*.......................Friend Functions.................*/

Vector3::Vector3() : Vector(3), x(0), y(0), z(0)
{
}

Vector3::Vector3(const float & x, const float & y, const float & z) : Vector(3), x(x), y(y), z(z)
{
	SetVector(x, y, z);
}

Vector3::Vector3(const Vector3 & vector) : Vector(vector)
{
}

Vector3::~Vector3()
{
}

void Vector3::SetVector(const float & x, const float & y, const float & z)
{
	float data[] = { x, y, z};
	::SetVector(x_vector, data);
}

Vector3 Vector3::operator+(const Vector3 & vector)
{
	Vector3 resultVector;
	::AddVector(x_vector, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector3 Vector3::operator-(const Vector3 & vector)
{
	Vector3 resultVector;
	::SubVector(x_vector, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector4::Vector4() : Vector(4), x(0), y(0), z(0), w(0)
{
}

Vector4::Vector4(const float& x, const float& y, const float& z, const float& w) : Vector(4), x(x), y(y), z(z), w(w)
{
	SetVector(x, y, z, w);
}

Vector4::Vector4(const Vector4 & vector) : Vector(vector)
{
}

Vector4::~Vector4()
{
}

void Vector4::SetVector(const float & x, const float & y, const float & z, const float & w)
{
	float data[] = { x, y, z, w };
	::SetVector(x_vector, data);
}

Vector4 Vector4::operator+(const Vector4 & vector)
{
	Vector4 resultVector;
	::AddVector(x_vector, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Vector4 Vector4::operator-(const Vector4 & vector)
{
	Vector4 resultVector;
	::SubVector(x_vector, vector.x_vector, resultVector.x_vector);

	return resultVector;
}

Matrix::Matrix(int row, int column)
{
	CreateMatrix(row, column, x_matrix);
}

Matrix::Matrix(const Matrix & matrix)
{
	CreateMatrix(matrix.x_matrix.row, matrix.x_matrix.column, x_matrix);
	CopyMatrix(matrix.x_matrix, x_matrix);
}

Matrix::~Matrix()
{
	DeleteMatrix(x_matrix);
}

void Matrix::ToIdentity()
{
	::MakeMatrixIdentity(x_matrix);
}

void Matrix::Randomize()
{
	::Randomize(x_matrix);
}

void Matrix::ToUpperTriangularMatrix()
{
	::GetUpperTriangularMatrix(x_matrix, x_matrix);
}

void Matrix::ToLowerTriangularMatrix()
{
	::GetLowerTriangularMatrix(x_matrix, x_matrix);
}

float Matrix::GetDeterminant()
{
	return ::GetDeterminant(x_matrix);
}

bool Matrix::isInvertible()
{
	return ::isInvertible(x_matrix);
}

Matrix & Matrix::operator=(const Matrix & matrix)
{
	CopyMatrix(matrix.x_matrix, x_matrix);
	return *this;
}

void Matrix::print()
{
	::print(x_matrix);
}

Matrix2x2::Matrix2x2() : Matrix(2, 2)
{
}

Matrix2x2::Matrix2x2(const Matrix2x2 & matrix) : Matrix(matrix)
{
}

Matrix2x2::~Matrix2x2()
{
}

void Matrix2x2::SetRow(const int & row, const Vector2 & vector)
{
	const float data[2] = {vector.getX(), vector.getY()};
	::SetRow(row, x_matrix, data);
}

void Matrix2x2::SetColumn(const int & column, const Vector2 & vector)
{
	const float data[2] = { vector.getX(), vector.getY() };
	::SetColumn(column, x_matrix, data);
}

Matrix2x2 Matrix2x2::GetUpperTriangularMatrix()
{
	Matrix2x2 resultMatrix;
	::GetUpperTriangularMatrix(x_matrix, resultMatrix.x_matrix);

	return resultMatrix;
}

Matrix2x2 Matrix2x2::GetLowerTriangularMatrix()
{
	Matrix2x2 resultMatrix;
	::GetLowerTriangularMatrix(x_matrix, resultMatrix.x_matrix);

	return resultMatrix;
}

Matrix2x2 Matrix2x2::GetInverseMatrix()
{
	Matrix2x2 resultMatrix;
	::GetInverseMatrix(x_matrix, resultMatrix.x_matrix);

	return resultMatrix;
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2 & matrix)
{
	Matrix2x2 resultMatrix;
	::MultiplyMatrix(x_matrix, matrix.x_matrix, resultMatrix.x_matrix);

	return resultMatrix;
}
