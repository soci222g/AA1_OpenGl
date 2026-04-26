#pragma once
#include "../Shader.h"


class FragmentShader : public Shader
{
public:
	FragmentShader() : Shader() {};
	void loadFragmentShader(const std::string& path);

};