#pragma once
#include "String.h"
#include "Integer.h"

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

// Construction by MOVE
class Entity3
{
public:
	Entity3(const Integer& name);

	Entity3(Integer&& name);

	void PrintName();

private:
	Integer number;
};