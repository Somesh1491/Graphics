#pragma once

#include "x_math.h"

class Vector;
class Vector2;
class Vector3;
class Vector4;
class Matrix;
class Matrix2x2;
class Matrix3x3;
class Matrix4x4;

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
	float getX() const;
	float getY() const;
	float getZ() const;
	friend Vector3 operator*(const float& scaler, const Vector3& vector);
	friend Vector3 operator*(const Vector3& vector, const float& scaler);
	friend Vector3 operator*(const Matrix3x3& matrix, const Vector3& vector);
	friend Vector3 operator*(const Vector3& vector, const Matrix3x3& matrix);

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
	float getX() const;
	float getY() const;
	float getZ() const;
	float getW() const;
	friend Vector4 operator*(const float& scaler, const Vector4& vector);
	friend Vector4 operator*(const Vector4& vector, const float& scaler);
	friend Vector4 operator*(const Matrix4x4& matrix, const Vector4& vector);
	friend Vector4 operator*(const Vector4& vector, const Matrix4x4& matrix);

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

class Matrix3x3 : public Matrix
{
public:
	Matrix3x3();
	Matrix3x3(const Matrix3x3& matrix);
	~Matrix3x3();

	void SetRow(const int& row, const Vector3& vector);
	void SetColumn(const int& column, const Vector3& vector);
	Matrix3x3 GetUpperTriangularMatrix();
	Matrix3x3 GetLowerTriangularMatrix();
	Matrix3x3 GetInverseMatrix();
	Matrix3x3 operator*(const Matrix3x3& matrix);
	friend Vector3 operator*(const Matrix3x3& matrix, const Vector3& vector);
	friend Vector3 operator*(const Vector3& vector, const Matrix3x3& matrix);
};

class Matrix4x4 : public Matrix
{
public:
	Matrix4x4();
	Matrix4x4(const Matrix4x4& matrix);
	~Matrix4x4();

	void SetRow(const int& row, const Vector4& vector);
	void SetColumn(const int& column, const Vector4& vector);
	Matrix4x4 GetUpperTriangularMatrix();
	Matrix4x4 GetLowerTriangularMatrix();
	Matrix4x4 GetInverseMatrix();
	Matrix4x4 operator*(const Matrix4x4& matrix);
	friend Vector4 operator*(const Matrix4x4& matrix, const Vector4& vector);
	friend Vector4 operator*(const Vector4& vector, const Matrix4x4& matrix);
};
