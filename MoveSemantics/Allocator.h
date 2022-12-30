#pragma once



class Allocator
{
private:
	int allocationsStart;
	int const* allocations;

public:
	Allocator(int const* allocations);
	~Allocator();

	void Print();

};

