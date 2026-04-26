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

	vertexCount = 15;

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
	rotation = rotation + Right * angularVelocity * dt;

	UpdateScale(dt);

	// escalar de maxim a minim i tornar
	shaderProgram->UnuseProgram();
}

void Cuboid::ShaderMatriux()
{
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	glm::mat4 translationMatrix = GenerateTranslationMatrix(position);
	glm::mat4 rotationMatrix = GenerateRotationMatrix(glm::vec3(0.f, 0.f, 1.f), rotation.z);
	glm::mat4 scaleMatrix = GenerateScaleMatrix(scale);



	modelMatrix = translationMatrix * rotationMatrix * scaleMatrix * modelMatrix;

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->GetProgram(), "transform"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
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
