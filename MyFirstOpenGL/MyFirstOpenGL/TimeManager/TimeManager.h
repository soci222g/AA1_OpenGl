#pragma once
#include <GLFW/glfw3.h>

#define TIME TimeManager::Instance()


class TimeManager
{
public:
	static TimeManager& Instance()
	{
		static TimeManager instance;
		return instance;
	}


	void Update()
	{
		_currentTime = glfwGetTime();
		_deltaTime = _currentTime - _lastFrameTime;
		_deltaTime *= _multiplayerSpeed;	
		_lastFrameTime = _currentTime;
	}

	float GetDeltaTime() const { return _deltaTime; }	

private:
	TimeManager() : _deltaTime(0.f), _currentTime(0.f)
	{
		_lastFrameTime = glfwGetTime();
		_multiplayerSpeed = 1.f;
	}
	~TimeManager() = default;

	TimeManager(const TimeManager& t) = delete;
	TimeManager& operator =(const TimeManager& t) = delete;


	float _multiplayerSpeed;


	float _lastFrameTime;
	float _deltaTime;
	float _currentTime;

};

