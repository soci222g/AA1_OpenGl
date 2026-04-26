#include "Cuboid.h"

void Cuboid::SetupGeometry(GLuint VAO)
{
	// VAO


	// VBOs
	glGenBuffers(2, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	GLfloat w = width / 2.0f;
	GLfloat h = height / 2.0f;
	GLfloat d = depth / 2.0f;

	GLfloat vertices[] = {
		// front
		-w,  h, -d,
		 w,  h, -d,
		-w, -h, -d,
		 w, -h, -d,
		// right
		w,  h, -d,
		w,  h,  d,
		w, -h, -d,
		w, -h,  d,
		// top
		-w,  h, -d,
		-w,  h,  d,
		w,  h, -d,
		w,  h,  d,
		// bottom
		-w, -h, -d,
		-w, -h,  d,
		w, -h, -d
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


void Cuboid::Update(float dt)
{
	shaderProgram->UseProgram();
	// rotar sobre l'eix z
	rotation.z += angularVelocity * dt;
	if (rotation.z >= 360.f) {
		rotation.z -= 360.f;
	}

	// escalar de maxim a minim i tornar
	UpdateScale(dt);
	shaderProgram->UnuseProgram();
}

void Cuboid::UpdateScale(float dt)
{
	if (scalingDown) {
		scale.x -= scaleSpeed * dt;
		scale.y -= scaleSpeed * dt;
		scale.z -= scaleSpeed * dt;

		if (scale.x <= minScale) {
			scale.x = minScale;
			scale.y = minScale;
			scale.z = minScale;
			scalingDown = false;
		}
	}
	else {
		scale.x += scaleSpeed * dt;
		scale.y += scaleSpeed * dt;
		scale.z += scaleSpeed * dt;

		if (scale.x >= maxScale) {
			scale.x = maxScale;
			scale.y = maxScale;
			scale.z = maxScale;
			scalingDown = true;
		}
	}
}
