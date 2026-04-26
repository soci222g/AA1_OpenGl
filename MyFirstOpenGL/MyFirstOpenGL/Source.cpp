#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include "GameManager.h"
#include "TimeManager/TimeManager.h"



/*void main() {

	srand(time(NULL));


	//INICIALITZA GLFW per gestiona finestres
	glfwInit();



	//pillar drivers
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//vercio principal AKA OPenGl 4.4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); //configura si es escalabla la finestra



	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "WINDOW1", NULL, NULL);


	glfwSetFramebufferSizeCallback(window, ResizeWindow);

	//definim la finestra
	glfwMakeContextCurrent(window);


	//activem funcions experimentals per a totes les grafiques
	glewExperimental = GL_TRUE;

	//activem culling
	glEnable(GL_CULL_FACE);



	//indiquem el gl del culling
	glCullFace(GL_BACK);

	if (glewInit() == GLEW_OK) {


		std::cout << "ha funcionat" << std::endl;

		//compilem shader
		ShaderProgram myFirstProgram;

		myFirstProgram.vertexShader = loadVertexShader("MyFistVertexShader.glsl");
		myFirstProgram.geometryShader = loadGeometryShader("MyFirstGeometryShader.glsl");
		myFirstProgram.geometryShader = loadFragmentShader("MyFirstFragmentShader.glsl");

		//compila el programa un cop el shader esta compilat

		GLuint myfirstCompiledProgram;
		myfirstCompiledProgram = CreateProgram(myFirstProgram);


		//declarem struc game object
		GameObjects cube;




		//optenim referencia del element dins del shader

		GLint offsetReference = glGetUniformLocation(myfirstCompiledProgram, "offset");
		 


		//set el color del buffer  (el de darrera)
		glClearColor(0.f, 0.f, 0.f, 1.f);





		GLuint vaoPuntos, vboPuntos;

		GLuint vboPuntos2;
		//Generop el VAO i m'el Guardo a vaoPuntos
		glGenVertexArrays(1, &vaoPuntos);

		//activo el vao per trevalla en ell
		glBindVertexArray(vaoPuntos);


		//amb generas un vbo i m'el guardes.
		glGenBuffers(1, &vboPuntos);

		glGenBuffers(1, &vboPuntos2);

		//indico quin VBO es el actiu i que esta gaurdan arrays de dades
		glBindBuffer(GL_ARRAY_BUFFER, vboPuntos);

		glEnableVertexAttribArray(0);

		//dibuixa geometries de debug (per la entrega true o false)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



		//declarem un punt en el x i y
		GLfloat puntos[] = {
				-0.5f,0.5f,-0.5f,
				0.5f,0.5f, -0.5f,
				-0.5f,-0.5f, -0.5f,
				0.5f,-0.5f,-0.5f,
				0.5f,-0.5f,0.5f,
				0.5f,0.5f, -0.5f,
				0.5f,0.5f,0.5f,
				-0.5f,0.5f,-0.5f,
				-0.5f,0.5f,0.5f,
				-0.5f,-0.5f, -0.5f,
				-0.5f,-0.5f, 0.5f,
				0.5f,-0.5f,0.5f,
				-0.5f,0.5f,0.5f,
				0.5f,0.5f,0.5f


		};

		//posu el array en el VBO
		glBufferData(GL_ARRAY_BUFFER, sizeof(puntos), puntos, GL_STATIC_DRAW);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

		//nategem el buffer amb el vbo
		glBindBuffer(GL_ARRAY_BUFFER, 0);




		//bufer 2


		GLfloat puntosRandom[] = {
				static_cast<GLfloat>(rand()) / RAND_MAX * 0.5f,
				static_cast<GLfloat>(rand()) / RAND_MAX * 0.5f,
				static_cast<GLfloat>(rand()) / RAND_MAX * 0.5f,
				static_cast<GLfloat>(rand()) / RAND_MAX * 0.5f,

		};


		glBindBuffer(GL_ARRAY_BUFFER, vboPuntos2);


		glBufferData(GL_ARRAY_BUFFER, sizeof(puntosRandom), puntosRandom, GL_STATIC_DRAW);
		//el primer numero es el id del vbo que corespon
		glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 1 * sizeof(GLfloat), (GLvoid*)0);
		//actia el vbo amb el index coresponenet
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);


		//desactivem el vao 
		glBindVertexArray(0);





		//generem el model de la matriu MVP
		


		//indica a la cpi que utilitzi el programa 
		glUseProgram(myfirstCompiledProgram);


		glUniform2f(glGetUniformLocation(myfirstCompiledProgram, "WindowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);

		//qui si podem modifica la variable (nomes es pot amb us)
		glm::vec2 offset = glm::vec2(0.0f, 0.0f);



		unsigned int LastFremeTime = glfwGetTime();




		while (!glfwWindowShouldClose(window))
		{
			unsigned int currentTime = glfwGetTime();



			unsigned int DeltaTime = currentTime - LastFremeTime;


			LastFremeTime = glfwGetTime();



			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
				offset.y += 0.01 * DeltaTime;
			}
			else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
				offset.y -= 0.01 * DeltaTime;
			}

			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
				offset.x -= 0.01 * DeltaTime;
			}
			else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
				offset.x += 0.01 * DeltaTime;
			}

			
			glm::mat4 cubeModelMatrix = glm::mat4(1.0f);

			cube.position = cube.position + cube.forward * cube.velocity;
			cube.rotation = cube.rotation + cube.Up * cube.angularVelocity;


			//invertim direccio si surt dels limits

			if (cube.position.x >= 0.5f || cube.position.x <= -0.5f) {
				cube.forward = cube.forward * -1.f;

			}

		



			glm::mat4 cubeTranslacioMatrix = GenerateTranslationMatrix(cube.position);
			glm::mat4 rotationMatrix = GenerateRotationMatrix(glm::vec3(1.f,1.f,0.f), cube.rotation.y);


			cubeModelMatrix = cubeTranslacioMatrix * rotationMatrix * cubeModelMatrix;

			glUniformMatrix4fv(glGetUniformLocation(myfirstCompiledProgram, "transform"), 1, GL_FALSE, glm::value_ptr(cubeModelMatrix));
			


		

			//una ariable per cada tipo, (2, floats, vector)
			glUniform2fv(offsetReference, 1, &offset[0]);


			//fem un pull de events
			glfwPollEvents();



			//clear buffers
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);



			//cridem a la geometria del VAO ( el VBO esta dintre de aquest)
			glBindVertexArray(vaoPuntos);

			//definim quiona info estem pintan del vao (en aquest cas punts , des del element 0 fins el 1)
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 14);

			//desativem el VAO
			glBindVertexArray(0);

			//preven la dessincruintzacio de FPS amb Hz
			glFlush();

			//fas swap dels buffers
			glfwSwapBuffers(window);

		}


		//desactivem i alliverem recursos del programa
		glUseProgram(0); //casquem que el programa que estem utilitzan sigi inactiu per poder modifica
		glDeleteProgram(myfirstCompiledProgram);
	}
	else {
		std::cout << "ha muerto" << std::endl;
		glfwTerminate();
	}



	glfwTerminate();



}
*/

void main() {

	GameManager gameManager;
	gameManager.Initialize();
	gameManager.LoadGame();
	while (gameManager.IsRunning()) {
		TIME.Update();
		gameManager.Update(TIME.GetDeltaTime());
		gameManager.Render();
	}
	gameManager.Cleanup();



	return;



}




