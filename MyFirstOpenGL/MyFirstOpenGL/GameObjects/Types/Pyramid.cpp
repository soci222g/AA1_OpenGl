#include "Pyramid.h"

void Pyramid::SetupGeometry(GLuint VAO)
{


	// VBOs
	glGenBuffers(3, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	GLfloat vertices[] = {
		// Base
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.0f,  0.5f,  0.0f,
		 0.5f, -0.5f,  0.5f,
		 0.0f,  0.5f,  0.0f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,
		 0.0f,  0.5f,  0.0f
	};

	vertexCount = 8;

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);






	//shaders
	shaderProgram = new ShaderProgram();
	shaderProgram->GetVertexShader()->loadVertexShader("MyFistVertexShader.glsl");
	shaderProgram->GetGeometryShader()->loadGeometryShader("MyFirstGeometryShader.glsl");
	shaderProgram->GetFragmentShader()->loadFragmentShader("FragmentShaderTimer.glsl");
	shaderProgram->loadProgram();

	shaderProgram->UseProgram();

	glUniform1f(glGetUniformLocation(shaderProgram->GetProgram(), "Timer"), colorTimer);
	glUniform2f(glGetUniformLocation(shaderProgram->GetProgram(), "WindowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
	shaderProgram->UnuseProgram();
}

void Pyramid::Update(float dt)
{
	shaderProgram->UseProgram();

	if (movingUp) {
		position = position + Up * velocity * dt;
		
		if (position.y >= maxHeight) {
			movingUp = false;
		}
	}
	else {
		position = position - Up * velocity * dt;
		if (position.y <= minHeight) {
			movingUp = true;
		}
	}

	// rotar eixos x i y
	rotation = rotation + Up * angularVelocity* dt;
	rotation = rotation + forward * angularVelocity * dt;



	colorTimer += dt;
	if (colorTimer >= 6.0f) {
		colorTimer = 0.0f;
	}

	// cambia de color cada 2 segons
	shaderProgram->UnuseProgram();
}

void Pyramid::ShaderMatriux()
{
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	glm::mat4 translationMatrix = GenerateTranslationMatrix(position);
	glm::mat4 rotationMatrix = GenerateRotationMatrix(glm::vec3(1.f, 1.f, 0.f), rotation.y);
	glm::mat4 scaleMatrix = GenerateScaleMatrix(scale);



	modelMatrix = translationMatrix * rotationMatrix * scaleMatrix * modelMatrix;

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->GetProgram(), "transform"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
}


