#pragma once
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;
	const bool maxResolution;

public:
	Timer(const bool maxResolution = false);

	void Stop();

	~Timer();
};

