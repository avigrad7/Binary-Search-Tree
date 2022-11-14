#pragma once
#include <iostream>
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
public:
	Timer();
	~Timer();
};

