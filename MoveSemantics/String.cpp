#include "String.h"

String::String(const char* string)
{
	printf("CREATED\n");
	size = strlen(string);
	data = new char[size];
	memcpy(data, string, size);
}

String::String(const String& other)
{
	printf("COPIED\n");
	size = other.size;
	data = new char[size];
	memcpy(data, other.data, size);
}

String::String(String&& other) noexcept
{
	printf("MOVED\n");
	size = other.size;
	data = other.data;
	
	other.size = 0;
	other.data = nullptr;
}

void String::Print()
{
	for (uint32_t i = 0; i < size; ++i)
	{
		printf("%c", data[i]);
	}
	printf("\n");
}


String::~String()
{
	printf("DELETED\n");
	delete[] data;
}

String& String::operator=(const String& other) noexcept
{
	printf("COPY operator\n");
	if (this == &other)
	{
		return *this;
	}

	delete[] data;

	size = other.size;
	data = new char[size];
	memcpy(data, other.data, size);
}

String& String::operator=(String&& other) noexcept
{
	printf("MOVE operator\n");
	if (this == &other)
	{
		return *this;
	}

	delete[] data;

	size = other.size;
	data = other.data;

	other.size = 0;
	other.data = nullptr;
}
