#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "GL/glew.h"
#include "Transform.h"
#include "Camera.h"

class Shader
{
public:
	Shader(const std::string& filename);
	void Update( const Transform& transform, const Camera& camera);
	void Bind();
	~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint m_uniforms[NUM_UNIFORMS];

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};

