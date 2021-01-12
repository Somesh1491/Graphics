#include "MathLib.h"

Vector::Vector(int size)
{
	CreateVector(size, x_vector);
}

Vector::Vector(const Vector & vector)
{
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
	memcpy(x_vector.vectorPtr, vector.x_vector.vectorPtr, sizeof(float) * vector.x_vector.size);

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

Vector2::Vector2() : Vector(2)
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
