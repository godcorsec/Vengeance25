#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <glad/glad.h>
#include "../Common/vengeance_structs.h"


struct VengeanceShader
{
	VengeanceShader(const char* shaderFile) : m_shaderFilePath(shaderFile)
	{
		std::ifstream stream(shaderFile);
		std::stringstream ss[2];
		VengeanceShaderType shaderType = VengeanceShaderType::NONE;

		if (!stream.is_open())
		{
			printf("{!} Failed to open file: '%s'\n", shaderFile);
		}

		std::string line;

		while (std::getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
				{
					shaderType = VengeanceShaderType::VERTEX;
				}
				else if (line.find("fragment") != std::string::npos)
				{
					shaderType = VengeanceShaderType::FRAGMENT;
				}
			}
			else
			{
				ss[(int)shaderType] << line << "\n";
			}
		}

		m_VertexSourceCode = ss[0].str();
		m_FragmentSourceCode = ss[1].str();
	}
	int CompileShader();

private:
	const char* m_shaderFilePath;
	std::string m_VertexSourceCode;
	std::string m_FragmentSourceCode;

	unsigned int CreateShader(unsigned int shaderType, std::string& shaderSource);
};