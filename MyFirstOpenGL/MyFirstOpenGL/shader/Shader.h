#pragma once
#include <GL/glew.h>
#include <string>
#include<fstream>
#include<iostream>
#include <vector>




class Shader
{
public:
	std::string LoadPath(const std::string& filePath);
	GLuint GetShader() const { return _shader; }
	void SetShader(GLuint shader) { _shader = shader; }


private:
	GLuint _shader;
};

