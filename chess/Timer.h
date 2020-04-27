#pragma once
#include <chrono>
#include <iostream>
#include <future>
using namespace std;

class Timer{
private:
	chrono::time_point<std::chrono::steady_clock> m_StartTime;;
public:
	void Start();
	float GetDuration();
};

