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
	shaderProgram->GetFragmentShader()->loadFragmentShader("MyFirstFragmentShader.glsl");
	shaderProgram->loadProgram();

	shaderProgram->UseProgram();
	glUniform2f(glGetUniformLocation(shaderProgram->GetProgram(), "WindowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
	shaderProgram->UnuseProgram();
}

void Pyramid::Update(float dt)
{
	shaderProgram->UseProgram();

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

	// rotar eixos x i y
	rotation.x += angularVelocity * dt;
	rotation.y += angularVelocity * dt;

	if (rotation.x >= 360.f) {
		rotation.x -= 360.f;
	}
	if (rotation.y >= 360.f) {
		rotation.y -= 360.f;
	}

	// cambia de color cada 2 segons
	UpdateColor(dt);
	shaderProgram->UseProgram();
}

void Pyramid::UpdateColor(float dt)
{
	colorTimer += dt;

	if (colorTimer >= colorInterval) {
		colorTimer = 0.f;
		colorIndex = (colorIndex + 1) % 3;
	}
}
