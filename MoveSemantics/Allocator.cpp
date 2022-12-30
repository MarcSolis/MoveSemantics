#include "Allocator.h"
#include <iostream>


Allocator::Allocator(int const* allocations) : allocations(allocations)
{
	allocationsStart = *allocations;
}

void Allocator::Print()
{
	const auto allocationsEnd = *allocations;

	std::cout << allocationsEnd - allocationsStart << " allocs" << std::endl;
}

Allocator::~Allocator()
{
	Print();
}
