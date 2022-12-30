#include "Integer.h"


Integer::Integer(int number)
{
	printf("CREATED\n");
	num = number;
}

Integer::Integer(const Integer& number)
{
	printf("COPIED\n");
	num = number.num;
}

Integer::Integer(Integer&& number) noexcept
{
	printf("MOVED\n");
	num = number.num;
}

Integer::~Integer()
{
	printf("DELETED\n");
}

Integer& Integer::operator=(const Integer& other) noexcept
{
	printf("COPY operator\n");
	if (this == &other)
	{
		return *this;
	}
	
	num = other.num;
}

Integer& Integer::operator=(Integer&& other) noexcept
{
	printf("MOVE operator\n");
	if (this == &other)
	{
		return *this;
	}
	
	num = other.num;

	other.num = 0;
}


void Integer::Print()
{
	std::cout << num << std::endl;
}