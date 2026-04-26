#include "Cube.h"




void Cube::SetupGeometry(GLuint VAO)
{


	// VBOs
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	GLfloat vertices[] = {
		// front
		-0.5f,  0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		// right
		0.5f,  0.5f, -0.5f,
		0.5f,  0.5f,  0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f,  0.5f,
		// top
		-0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f,  0.5f,
		0.5f,  0.5f, -0.5f,
		0.5f,  0.5f,  0.5f,
		// bottom
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		0.5f, -0.5f, -0.5f
	};

	vertexCount = 14;

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);





	//shaders
	shaderProgram = new ShaderProgram();
	shaderProgram->GetVertexShader()->loadVertexShader("MyFistVertexShader.glsl");
	shaderProgram->GetGeometryShader()->loadGeometryShader("MyFirstGeometryShader.glsl");
	shaderProgram->GetFragmentShader()->loadFragmentShader("MyFirstFragmentShader.glsl");
	shaderProgram->loadProgram();

	shaderProgram->UseProgram();
	glUniform2f(glGetUniformLocation(shaderProgram->GetProgram(), "WindowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
	shaderProgram->UnuseProgram();


}

void Cube::Update(float dt)
{
	//glm::mat4 matrix = glm::mat4(1.0f);

	//float positionY = position.y;
	//	
	//if (movingUp) {
	//	positionY += velocity * dt;
	//
	//}
	//else {
	//	positionY -= velocity * dt;
	//}
	////llamar al transform del shader i pasarle la matriu de transformacio




	// moure amunt i avall
	if (movingUp) {
		position.y += velocity * dt;
		if (position.y >= maxHeight) {
			movingUp = false;
		}
	}
	else {
		position.y -= velocity * dt;
		if (position.y <= minHeight) {
			movingUp = true;
		}
	}

	// rotar sobre l'eix y
	rotation.y += angularVelocity * dt;
	if (rotation.y >= 360.f) {
		rotation.y -= 360.f;
	}


}
