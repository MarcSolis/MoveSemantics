#include "Entity.h"

#pragma region Entity0
Entity0::Entity0(const String name) : name(name)
{
}

void Entity0::PrintName()
{
	printf("name: ");
	name.Print();
}
#pragma endregion

#pragma region Entity1
Entity1::Entity1(const String& name) : name(name)
{
}

void Entity1::PrintName()
{
	printf("name: ");
	name.Print();
}
#pragma endregion

#pragma region Entity2
Entity2::Entity2(const String& name) : name(name)
{
}

Entity2::Entity2(String&& name) : name(std::move(name))
{
}

void Entity2::PrintName()
{
	printf("name: ");
	name.Print();
}
#pragma endregion


#pragma region Entity3
Entity3::Entity3(const Integer& number) : number(number)
{
}

Entity3::Entity3(Integer&& number) : number(std::move(number))
{
}

void Entity3::PrintName()
{
	printf("number: ");
	number.Print();
}
#pragma endregion