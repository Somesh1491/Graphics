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
	void Randomize();
	void print();
public:
	x_vectorN x_vector;
};

class Vector2 : public Vector
{
public:
	Vector2();
	Vector2(const float& x, const float& y);
	Vector2(const Vector2& vector);
	Vector2& operator=(const Vector2& vector);
	~Vector2();

	void SetVector(const float& x, const float& y);

private:
	float x, y;
};

class Matrix
{
private:
	x_matrix x_matrix;
};
