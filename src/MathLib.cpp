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
