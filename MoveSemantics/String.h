#pragma once
#include <iostream>


// Simplified string class for testing purposes
class String
{
public:
	String() = default;

	String(const char* string);

	String(const String& other);

	String(String&& other) noexcept;

	void Print();

	~String();

	// Copy operator
	String& operator=(const String& other) noexcept;

	// Move operator
	String& operator=(String&& other) noexcept;

private:
	char* data;
	uint32_t size;
};

