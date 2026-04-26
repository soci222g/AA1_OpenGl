#include "InputManager.h"
#include "../TimeManager/TimeManager.h"

void InputManager::handleKeyInput(int key, GLFWwindow* window)
{
	if (key == GLFW_KEY_SPACE) {
		if (isPressed(key, window)) {
			paused = !paused;
		}
	}
	if (key == GLFW_KEY_M){
		if (isPressed(key, window)) {
			TIME.SetMultiplayerSpeed(0.1f);
		}
	}
	if (key == GLFW_KEY_N){
		if (isPressed(key, window)) {
			TIME.SetMultiplayerSpeed(-0.1f);
			if (TIME.GetMultiplayerSpeed() < 0.1f) {
				TIME.SetMultiplayerSpeed(0.1f);
			}
		}
	}


	// if (isPressed(key, window)) {
	//	glfwSetWindowShouldClose(glfwGetCurrentContext(), GL_TRUE);
	//}
}
