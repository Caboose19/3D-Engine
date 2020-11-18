#include "C:\Users\Zach\source\repos\3D Engine\Application\pch.h"
#include "Timer.h"


namespace nc
{
	void Timer::Reset()
	{
		m_timePoint = clock::now();
	}

	Timer::clock::rep Timer::ElpasedTicks()
	{
		clock_duration duration = (clock::now() - m_timePoint);

		return duration.count();
	}

	Timer::clock::rep Timer::TicksPerSecond()
	{
		return clock_duration::period::den;
	}
	double Timer::ElapsedSeconds()
	{
		clock::rep ticks = ElpasedTicks();
		return ticks / static_cast<double>(TicksPerSecond());
	}


	void FrameTimer::Tick()
	{
		m_dt = static_cast<double>(ElapsedSeconds());
		m_timePoint = clock::now();
	}
}