#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "GL/glew.h"


class Shader
{
public:
	Shader(const std::string& filename);
	void Bind();
	~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};

