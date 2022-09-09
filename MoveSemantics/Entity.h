#pragma once
#include "String.h"

// Construction by COPY
class Entity0
{
public:
	Entity0(const String name);

	void PrintName();

private:
	String name;
};


// Construction by REFERENCE
class Entity1
{
public:
	Entity1(const String& name);

	void PrintName();

private:
	String name;
};


// Construction by MOVE
class Entity2
{
public:
	Entity2(const String& name);

	Entity2(String&& name);

	void PrintName();

private:
	String name;
};