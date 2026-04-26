#pragma once
#include "../Shader.h"

class VertexShader : public Shader
{
public:

	VertexShader() : Shader() {};

	void loadVertexShader(const std::string& path);

};

