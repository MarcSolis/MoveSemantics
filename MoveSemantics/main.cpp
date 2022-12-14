// Written by Marc Solis (2022)
#include <iostream>
#include "Entity.h"


#define BENCHMARKING 1

#if BENCHMARKING == 1
	#include "Timer.h"
	#include "Allocator.h"

	static int allocations;

	#define TIMING(x) Timer timer(x)
	#define ALLOCATIONS Allocator allocator(&allocations)

	void* operator new(size_t size) {
		allocations++;
		return malloc(size);	
	}

	
#else
	#define TIMING(x)
	#define ALLOCATIONS
#endif


#pragma region Entity0
// Bad. Creation + copy + copy = 3 heap allocations
void ContructionMethod0()
{
	String name("Arnau");
	Entity0 entity(name);
	entity.PrintName();
}

// Suboptimal. Creation + copy = 2 heap allocations
void ContructionMethod1()
{
	Entity0 entity("Ares");
	entity.PrintName();
}
#pragma endregion

#pragma region Entity1
// Suboptimal. Creation + copy = 2 heap allocations
void ContructionMethod2()
{
	String name("Ignasi");
	Entity1 entity(name);
	entity.PrintName();
}

// Suboptimal. Creation + copy = 2 heap allocations
void ContructionMethod3()
{
	Entity1 entity("Marc");
	entity.PrintName();
}
#pragma endregion

#pragma region Entity2
// Suboptimal. Creation + copy = 2 heap allocations
void ContructionMethod4()
{
	String name("Nil");
	Entity2 entity(name);
	entity.PrintName();
}

// Optimal. Creation + moved = 1 heap allocations
void ContructionMethod5()
{
	String name("David");
	Entity2 entity(std::move(name));
	entity.PrintName();
}

// Optimal. Creation + moved = 1 heap allocations
void ContructionMethod6()
{
	Entity2 entity("Toni");
	entity.PrintName();
}
#pragma endregion

#pragma region String
// Suboptimal. Creation + copy = 2 heap allocations
void AssignationMethod0()
{
	// Construction
	String base;
	String other = "Hello";

	printf("base: ");
	base.Print();
	printf("other: ");
	other.Print();


	// Assignation
	base = other;	// Copy operator

	printf("base: ");
	base.Print();
	printf("other: ");
	other.Print();
}

// Optimal. Creation + moved = 1 heap allocations
void AssignationMethod1()
{
	// Construction
	String base;
	String other = "Hello";

	printf("base: ");
	base.Print();
	printf("other: ");
	other.Print();


	// Assignation
	base = std::move(other);	// Move operator

	printf("base: ");
	base.Print();
	printf("other: ");
	other.Print();
}
#pragma endregion


int main()
{
	{
		ALLOCATIONS;
		TIMING(true);
		ContructionMethod0();
	}
	printf("\n-----------------------\n\n");
	{
		ALLOCATIONS;
		TIMING(true);
		ContructionMethod6();
	}

	std::cin.get();
}