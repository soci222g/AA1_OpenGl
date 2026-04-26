#include "InputManager.h"
#include "../TimeManager/TimeManager.h"

void InputManager::handleKeyInput(int key)
{
	if (isPressed(key)) {
		paused = !paused;
	}



	if (isPressed(key)) {
		TIME.SetMultiplayerSpeed(0.1f);
	}
	else if (isPressed(key)) {
		TIME.SetMultiplayerSpeed(-0.1f);
		if (TIME.GetMultiplayerSpeed() < 0.1f) {
			TIME.SetMultiplayerSpeed(0.1f);
		}
	}

	 if (isPressed(key)) {
		glfwSetWindowShouldClose(glfwGetCurrentContext(), GL_TRUE);
	}
}
