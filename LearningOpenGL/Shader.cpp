#include "Shader.h"

static std::string LoadShader(const std::string& filename) {

	std::ifstream file;
	file.open(filename.c_str());

	std::string output;
	std::string line;

	if (file.is_open()) {
		while (file.good()) {
			std::getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		std::cerr << "Unable to load shader: " << filename << std::endl;
	}

	return output;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE) {
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

static GLuint CreateShader(const std::string& text, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);
	if (shader == 0)
		std::cerr << "ERROR: Shader creation failed!" << std::endl;

	const GLchar * shaderSourceStrings[1];
	GLint shaderSourceStringlengths[1];

	shaderSourceStrings[0] = text.c_str();
	shaderSourceStringlengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringlengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "ERROR: Shader Compilation failed: ");

	return shader;
}

Shader::Shader(const std::string& filename)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(filename + ".vs"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(filename + ".fs"), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_program, m_shaders[i]);
	
	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "texCoord");
	glBindAttribLocation(m_program, 2, "normal");
	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "ERROR: Program Failed to link! :");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "ERROR: Program is invalid! :");
	
	m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");

}

void Shader::Update(const Transform & transform, const Camera& camera)
{

	glm::mat4 Model = camera.GetViewProjetion()* transform.GetModel();
	glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &Model[0][0]);

}




void Shader::Bind()
{
	glUseProgram(m_program);
}

Shader::~Shader()
{
	for (int i = 0; i < NUM_SHADERS; i++) {
		glAttachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	glDeleteProgram(m_program);
}
