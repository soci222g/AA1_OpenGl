#include "GameManager.h"
#include "GameObjects/Types/Cube.h"
#include "GameObjects/Types/Cuboid.h"
#include "GameObjects/Types/Pyramid.h"
#include <gtc/type_ptr.hpp>


void ResizeWindow2(GLFWwindow* window, int iNewFrameBufferWidth, int iNewFrameBufferHeight)
{
	//definir nou tamany
	glViewport(0, 0, iNewFrameBufferWidth, iNewFrameBufferHeight);
}


void GameManager::Initialize()
{
	// INICIALITZA GLFW per gestiona finestres
	if (!glfwInit()) {
		std::cout << "Error al inicializar GLFW" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	//pillar drivers
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//versió principal AKA OPenGl 4.4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	//configura si es escalabla la finestra
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);


	CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "WINDOW1");
	// Create window

	//activem funcions experimentals per a totes les grafiques
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Error al inicializar GLEW" << std::endl;
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	//activem culling
	glEnable(GL_CULL_FACE);
	//indiquem el gl del culling
	glCullFace(GL_BACK);

	// color amb el que es fa el clear del buffer
	glClearColor(0.f, 0.f, 0.f, 1.f);

	// carrega i compila els shaders

	shaderProgram = new ShaderProgram();

	shaderProgram->GetVertexShader().loadVertexShader("MyFistVertexShader.glsl");
//	shaderProgram->GetGeometryShader().loadGeometryShader("MyFirstGeometryShader.glsl");
//	shaderProgram->GetFragmentShader().loadFragmentShader("MyFirstFragmentShader.glsl");
	shaderProgram->loadProgram();

	shaderProgram->UseProgram();
	glUniform2f(glGetUniformLocation(shaderProgram->GetProgram(), "WindowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
	shaderProgram->UnuseProgram();

	std::cout << "Inicializacion completada" << std::endl;
}

void GameManager::LoadGame()
{
	shaderProgram->UseProgram();

	// crear geometries i afegirles a la llista
	Cube* cube = new Cube(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f), glm::vec3(1.f));
	cube->SetupGeometry();
	gameObjects.push_back(cube);

	Cuboid* cuboid = new Cuboid(glm::vec3(-0.5f, 0.f, 0.f), glm::vec3(0.f), glm::vec3(1.f), 0.5f, 0.3f, 0.2f);
	cuboid->SetupGeometry();
	gameObjects.push_back(cuboid);

	Pyramid* pyramid = new Pyramid(glm::vec3(0.5f, 0.f, 0.f), glm::vec3(0.f), glm::vec3(1.f));
	pyramid->SetupGeometry();
	gameObjects.push_back(pyramid);

	shaderProgram->UnuseProgram();

}

void GameManager::Update(float dt)
{
	// poll events
	glfwPollEvents();

	// handle input
	inputManager.handleKeyInput(GLFW_KEY_SPACE);
	inputManager.handleKeyInput(GLFW_KEY_UP);
	inputManager.handleKeyInput(GLFW_KEY_DOWN);
	inputManager.handleKeyInput(GLFW_KEY_ESCAPE);

	// actualitzar objectes tenint en compte el speed multiplier
	float adjustedDt = dt;

	if (!inputManager.isPaused()) {
		for (auto& obj : gameObjects) {
			obj->Update(adjustedDt);
		}
	}


}

void GameManager::Render()
{
	// cleanejar el buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	shaderProgram->UseProgram();

	// calcular la matriu de cada objecte i renderitzarla
	for (auto& obj : gameObjects) {
		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = obj->GenerateTranslationMatrix(obj->GetPosition());
		modelMatrix = modelMatrix * obj->GenerateRotationMatrix(glm::vec3(1.f, 1.f, 0.f), obj->GetRotation().y);
		modelMatrix = modelMatrix * obj->GenerateRotationMatrix(glm::vec3(1.f, 0.f, 0.f), obj->GetRotation().x);
		modelMatrix = modelMatrix * obj->GenerateRotationMatrix(glm::vec3(0.f, 0.f, 1.f), obj->GetRotation().z);
		modelMatrix = modelMatrix * obj->GenerateScaleMatrix(obj->GetScale());

		glUniformMatrix4fv(glGetUniformLocation(shaderProgram->GetProgram(), "transform"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

		obj->Render();
	}

	glFlush();
	glfwSwapBuffers(window);
}

void GameManager::Cleanup()
{
	shaderProgram->UnuseProgram();
	glfwTerminate();
}

void GameManager::CreateWindow(int width, int height, const char* title)
{
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title, NULL, NULL);


	glfwSetFramebufferSizeCallback(window, ResizeWindow2);

	//definir la finestra
	glfwMakeContextCurrent(window);
}


