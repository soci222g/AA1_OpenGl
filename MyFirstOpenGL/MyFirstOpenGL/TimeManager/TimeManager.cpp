#include "TimeManager.h"
#include "../InputManager/InputManager.h"

void TimeManager::Update()
{
	_currentTime = glfwGetTime();
	_deltaTime = _currentTime - _lastFrameTime;
	_deltaTime *= _multiplayerSpeed;
	_deltaTime *= _pause;
	_lastFrameTime = _currentTime;
}

void TimeManager::InputHandle()
{
	if (IM->getCurrentKey() == KeyPressed::SPACE) {
		if (_pause == 1) {
			IM->SetPaused(true);
			_pause = 0;
		}
		else if (_pause == 0) {
			IM->SetPaused(false);
			_pause = 1;
		}
	}

	if (IM->getCurrentKey() == KeyPressed::M) {
		SetMultiplayerSpeed(0.1f);
	}
	if (IM->getCurrentKey() == KeyPressed::N) {
		SetMultiplayerSpeed(-0.1f);
	}
}
