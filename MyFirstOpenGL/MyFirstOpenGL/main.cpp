#include "GameManager.h"

int main()
{
	GameManager gameManager;
	gameManager.Initialize();
	gameManager.LoadGame();
	while (gameManager.IsRunning()) {
		unsigned int currentFrameTime = glfwGetTime();
		float deltaTime = currentFrameTime - gameManager.GetLastFrameTime();
		gameManager.SetLastFrameTime(currentFrameTime);

		gameManager.Update(deltaTime);
		gameManager.Render();
	}
	gameManager.Cleanup();
	return 0;
}