#pragma once
#include "../Shader.h"

class GeometryShader : public Shader
{
public:
	GeometryShader() : Shader() {};

	void loadGeometryShader(const std::string& path);
};
