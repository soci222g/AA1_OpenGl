#include "InputManager.h"
#include "../TimeManager/TimeManager.h"

void InputManager::handleKeyInput(int key)
{
	if (key == GLFW_KEY_SPACE) {
		paused = !paused;
	}
	else if (key == GLFW_KEY_UP) {
		TIME.SetMultiplayerSpeed(0.1f);
	}
	else if (key == GLFW_KEY_DOWN) {
		TIME.SetMultiplayerSpeed(-0.1f);
		if (TIME.GetMultiplayerSpeed() < 0.1f) {
			TIME.SetMultiplayerSpeed(0.1f);
		}
	}
	else if (key == GLFW_KEY_ESCAPE) {
		glfwSetWindowShouldClose(glfwGetCurrentContext(), GL_TRUE);
	}
}
