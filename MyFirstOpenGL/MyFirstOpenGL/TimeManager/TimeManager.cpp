#include "TimeManager.h"
#include "../InputManager/InputManager.h"

void TimeManager::InputHandle()
{
	if (IM->getCurrentKey() == KeyPressed::SPACE) {
		if(_pause == 1)
			_pause = 0;
		else if (_pause == 0)
			_pause = 1;
	}

	if (IM->getCurrentKey() == KeyPressed::M) {
		SetMultiplayerSpeed(0.1f);
	}
	if (IM->getCurrentKey() == KeyPressed::N) {
		SetMultiplayerSpeed(-0.1f);
	}
}
