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

	GLuint GetProgram() const { return Program; }
	void SetProgram(GLuint program) { Program = program; }	
	VertexShader GetVertexShader() const { return _vertexShader; }
	GeometryShader GetGeometryShader() const { return _geometryShader; }
	FragmentShader GetFragmentShader() const { return _fragmentShader; }

};