#include "InputManager.h"
#include "../TimeManager/TimeManager.h"

void InputManager::ListenKeys(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	InputManager* instance = InputManager::GetInstance();


    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
        case GLFW_KEY_M:
            instance->_currentKey = KeyPressed::M;
            break;
        case GLFW_KEY_N:
            instance->_currentKey = KeyPressed::N;
            break;
        case GLFW_KEY_SPACE:
            instance->_currentKey = KeyPressed::SPACE;
            break;
        case GLFW_KEY_1:
            instance->_currentKey = KeyPressed::ONE;
            break;
        case GLFW_KEY_2:
            instance->_currentKey = KeyPressed::TWO;
            break;
        case GLFW_KEY_3:
            instance->_currentKey = KeyPressed::THREE;
            break;
        case GLFW_KEY_4:
            instance->_currentKey = KeyPressed::FOUR;
            break;
        case GLFW_KEY_ESCAPE:
            instance->_currentKey = KeyPressed::ESCAPE;
            break;
        default:
            instance->_currentKey = KeyPressed::NONE;
            break;
        }
    }
}

