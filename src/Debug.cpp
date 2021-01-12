#include "Debug.h"

template<typename T>
void Log(T& object)
{
	std::cout << typeid(object).name();
	if(typeid(object).name() == typeid(Vector2).name())
	{
		
	}
}

template void Log<Vector2>(Vector2&);
