#include "MathLib.h"

void Vector::Randomize()
{
	::Randomize(x_vector);
}

void Vector::print()
{
	::print(x_vector);
}

Vector2::Vector2()
{
	CreateVector(2, x_vector);
}

Vector2::Vector2(const float& x, const float& y) : x(x), y(y)
{
	CreateVector(2, x_vector);
	SetVector(x, y);
}

Vector2::Vector2(const Vector2 & vector)
{
	std::cout << "Copy Constructor" << std::endl;
	CopyVector(vector.x_vector, x_vector);
}

Vector2& Vector2::operator=(const Vector2 & vector)
{
	std::cout << "Copy" << std::endl;
	memcpy(x_vector.vectorPtr, vector.x_vector.vectorPtr, sizeof(float) * vector.x_vector.size);

	return *this;
}

Vector2::~Vector2()
{
	DeleteVector(x_vector);
}

void Vector2::SetVector(const float& x, const float& y)
{
	float data[] = { x, y };
	::SetVector(x_vector, data);
}