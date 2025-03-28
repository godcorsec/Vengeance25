#include "vengeance_shader.h"
#include "../Core/vengeance_error_handling.hpp"


unsigned int VengeanceShader::CreateShader(unsigned int shaderType, std::string& shaderSource)
{
	unsigned int id = glCreateShader(shaderType);
	const char* src = shaderSource.c_str();

	VengeanceCatchGLError(glShaderSource(id, 1, &src, nullptr));
	VengeanceCatchGLError(glCompileShader(id));

	int result{};

	VengeanceCatchGLError(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

	if (result == GL_FALSE)
	{
		int length{};

		VengeanceCatchGLError(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

		// Todo: unsafe, fix this!!!
		char* logMessage = (char*)alloca(length * sizeof(char));
		VengeanceCatchGLError(glGetShaderInfoLog(id, length, &length, logMessage));

		printf("{!} Failed to compile %s shader\n", (shaderType == GL_VERTEX_SHADER ? "vertex" : "fragment"));
		printf("%s\n", logMessage);

		VengeanceCatchGLError(glDeleteShader(id));
		return 0;
	}

	return id;
}

int VengeanceShader::CompileShader()
{
	unsigned int program = glCreateProgram();
	unsigned int vertShader = CreateShader(GL_VERTEX_SHADER, m_VertexSourceCode);
	unsigned int fragShader = CreateShader(GL_FRAGMENT_SHADER, m_FragmentSourceCode);

	VengeanceCatchGLError(glAttachShader(program, vertShader));
	VengeanceCatchGLError(glAttachShader(program, fragShader));

	VengeanceCatchGLError(glLinkProgram(program));

	VengeanceCatchGLError(glValidateProgram(program));
	VengeanceCatchGLError(glDeleteShader(vertShader));
	VengeanceCatchGLError(glDeleteShader(fragShader));

	return program;

}