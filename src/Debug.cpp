#include "Debug.h"

template<typename T>
void LogObject(T& object)
{
}

template<>
void LogObject<Vector2>(Vector2& vector)
{
	vector.print();
}

template<>
void LogObject<Vector3>(Vector3& vector)
{
	vector.print();
}

template<>
void LogObject<Vector4>(Vector4& vector)
{
	vector.print();
}

template<>
void LogObject<Matrix2x2>(Matrix2x2& vector)
{
	vector.print();
}

template<>
void LogObject<Matrix3x3>(Matrix3x3& vector)
{
	vector.print();
}

template<>
void LogObject<Matrix4x4>(Matrix4x4& vector)
{
	vector.print();
}

template<typename T>
void Log(T& object)
{
	LogObject(object);
}

template void Log<Vector2>(Vector2& object);
template void Log<Vector3>(Vector3& object);
template void Log<Vector4>(Vector4& object);
template void Log<Matrix2x2>(Matrix2x2& object);
template void Log<Matrix3x3>(Matrix3x3& object);
template void Log<Matrix4x4>(Matrix4x4& object);