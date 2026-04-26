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
	void SetMultiplayerSpeed(float speed) { _multiplayerSpeed += speed; }
	float GetMultiplayerSpeed() const { return _multiplayerSpeed; }	


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

