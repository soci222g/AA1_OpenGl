#pragma once
#include "ShaderType/FragmentShader.h"
#include "ShaderType/GeometryShader.h"
#include "ShaderType/VertexShader.h"


class ShaderProgram {
private:
	VertexShader _vertexShader;
	GeometryShader _geometryShader;
	FragmentShader _fragmentShader;

	GLuint Program;

public:
	ShaderProgram() = default;
	~ShaderProgram() = default;


	void loadProgram();
	void UseProgram() const { glUseProgram(Program); }
	void UnuseProgram() const { glUseProgram(0); }

	GLuint GetProgram()  { return Program; }
	VertexShader GetVertexShader() { return _vertexShader; }
	GeometryShader GetGeometryShader()  { return _geometryShader; }
	FragmentShader GetFragmentShader()  { return _fragmentShader; }

};