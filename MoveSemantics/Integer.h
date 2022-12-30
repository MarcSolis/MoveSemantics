#pragma once
#include <iostream>

class Integer
{
public:
	Integer() = default;
	Integer(int number);
	Integer(const Integer& number);
	Integer(Integer&& number) noexcept;
	~Integer();

	void Print();


	// Copy operator
	Integer& operator=(const Integer& other) noexcept;
	// Move operator
	Integer& operator=(Integer&& other) noexcept;

private:
	int num;
};

