#pragma once

#include "x_math.h"

class Vector;
class Vector2;
class Vector3;
class Vector4;
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
	friend Vector2 operator*(const float& scaler, const Vector2& vector);
	friend Vector2 operator*(const Vector2& vector, const float& scaler);

private:
	float x, y;
};

class Matrix
{
private:
	x_matrix x_matrix;
};
