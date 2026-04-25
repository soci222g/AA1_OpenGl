#include "InputManager.h"

void InputManager::handleKeyInput(int key)
{
	if (key == GLFW_KEY_SPACE) {
		paused = !paused;
	}
	else if (key == GLFW_KEY_UP) {
		speedMultiplier += 0.1f;
	}
	else if (key == GLFW_KEY_DOWN) {
		speedMultiplier -= 0.1f;
		if (speedMultiplier < 0.1f) {
			speedMultiplier = 0.1f;
		}
	}
	else if (key == GLFW_KEY_ESCAPE) {
		glfwSetWindowShouldClose(glfwGetCurrentContext(), GL_TRUE);
	}
}
