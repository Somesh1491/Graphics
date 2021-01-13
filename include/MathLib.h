#pragma once

#include "x_math.h"

class Vector;
class Vector2;
class Vector3;
class Vector4;
class Matrix2x2;
class Matrix;

class Vector
{
public:
	Vector(int size);
	Vector(const Vector& vector);
	virtual ~Vector();
	void Randomize();
	Vector& operator=(const Vector& vector);
	float operator*(const Vector& vector);

	void print();
protected:
	x_vectorN x_vector;
};

class Vector2 : public Vector
{
public:
	Vector2();
	Vector2(const float& x, const float& y);
	Vector2(const Vector2& vector);
	~Vector2();

	void SetVector(const float& x, const float& y);
	Vector2 operator+(const Vector2& vector);
	Vector2 operator-(const Vector2& vector);
	float getX() const;
	float getY() const;
	friend Vector2 operator*(const float& scaler, const Vector2& vector);
	friend Vector2 operator*(const Vector2& vector, const float& scaler);
	friend Vector2 operator*(const Matrix2x2& matrix, const Vector2& vector);
	friend Vector2 operator*(const Vector2& vector, const Matrix2x2& matrix);

private:
	float x, y;
};

class Vector3 : public Vector
{
public:
	Vector3();
	Vector3(const float& x, const float& y, const float& z);
	Vector3(const Vector3& vector);
	~Vector3();

	void SetVector(const float& x, const float& y, const float& z);
	Vector3 operator+(const Vector3& vector);
	Vector3 operator-(const Vector3& vector);
	friend Vector3 operator*(const float& scaler, const Vector3& vector);
	friend Vector3 operator*(const Vector3& vector, const float& scaler);

private:
	float x, y, z;
};

class Vector4 : public Vector
{
public:
	Vector4();
	Vector4(const float& x, const float& y, const float& z, const float& w);
	Vector4(const Vector4& vector);
	~Vector4();

	void SetVector(const float& x, const float& y, const float& z, const float& w);
	Vector4 operator+(const Vector4& vector);
	Vector4 operator-(const Vector4& vector);
	friend Vector4 operator*(const float& scaler, const Vector4& vector);
	friend Vector4 operator*(const Vector4& vector, const float& scaler);

private:
	float x, y, z, w;
};

class Matrix
{
public:
	Matrix(int row, int column);
	Matrix(const Matrix& matrix);
	~Matrix();
	void ToIdentity();
	void Randomize();
	void ToUpperTriangularMatrix();
	void ToLowerTriangularMatrix();
	float GetDeterminant();
	bool isInvertible();
	Matrix& operator=(const Matrix& vector);
	void print();
protected:
	x_matrix x_matrix;
};

class Matrix2x2 : public Matrix
{
public:
	Matrix2x2();
	Matrix2x2(const Matrix2x2& matrix);
	~Matrix2x2();

	void SetRow(const int& row, const Vector2& vector);
	void SetColumn(const int& column, const Vector2& vector);
	Matrix2x2 GetUpperTriangularMatrix();
	Matrix2x2 GetLowerTriangularMatrix();
	Matrix2x2 GetInverseMatrix();
	Matrix2x2 operator*(const Matrix2x2& matrix);
	friend Vector2 operator*(const Matrix2x2& matrix, const Vector2& vector);
	friend Vector2 operator*(const Vector2& vector, const Matrix2x2& matrix);
};
