#include "Timer.h"

Timer::Timer(const uint16_t& durationInSeconds) :
	m_duration{ seconds(durationInSeconds) },
	m_isActive{ false }
{}

seconds Timer::GetElapsedTime() const
{
	auto currentTime{ high_resolution_clock::now() };
	return duration_cast<seconds>(currentTime - m_startTime);
}

bool Timer::ReachedThreshold() const
{
	return GetElapsedTime() >= m_duration;
}

void Timer::Start()
{
	m_startTime = high_resolution_clock::now();
	m_isActive = true;
}

void Timer::Stop()
{
	m_isActive = false;
}

bool Timer::IsActive() const
{
	return m_isActive;
}
