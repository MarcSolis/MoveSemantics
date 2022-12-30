#include "Timer.h"
#include <iostream>

Timer::Timer(const bool maxResolution) : maxResolution(maxResolution)
{
	startTimePoint = std::chrono::high_resolution_clock::now();
}

void Timer::Stop()
{
	auto endTimePoint = std::chrono::high_resolution_clock::now();

	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

	auto duration = end - start;

	if (maxResolution) { 
		std::cout << duration << "\xE6" << std::endl;
	}
	else {
		duration *= 0.001;
		std::cout << duration << "ms" << std::endl;
	}
}

Timer::~Timer()
{
	Stop();
}
