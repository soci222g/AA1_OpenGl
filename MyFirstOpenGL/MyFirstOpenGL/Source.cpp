#include "GameManager.h"
#include "TimeManager/TimeManager.h"


void main() {
	GameManager* gameManager = new GameManager();
	
	gameManager->Initialize();
	

	if (glewInit() == GLEW_OK) {
		gameManager->LoadGame();
		
		while (gameManager->IsRunning()) {
			TIME.Update();
			gameManager->Update(TIME.GetDeltaTime());
			gameManager->Render();
			TIME.InputHandle();
			IM->SetCurrentKey(KeyPressed::NONE);
		}
	}
	else {
		gameManager->Cleanup();
		delete gameManager;
		glfwTerminate();
	}

	glfwTerminate();

}




