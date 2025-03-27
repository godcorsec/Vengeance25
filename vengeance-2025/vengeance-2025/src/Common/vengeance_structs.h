#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "vengeance_math.h"
#include <string>
#include <fstream>
#include <sstream>


/*
* 
*   Of course not *every* struct is located here, but common ones like `VengeanceWindowProperties` are.
* 
*/

enum class VengeanceDisplayMode
{
	WINDOWED,
	FULLSCREEN_BORDERLESS,
	FULLSCREEN
};

enum class VengeanceShaderType
{
	NONE = -1,
	VERTEX = 0,
	FRAGMENT = 1
};

struct VengeanceShaderSources
{
	std::string VertexShaderSource;
	std::string FragmentShaderSource;
};



struct VengeanceWindowProperties
{
	GLFWwindow* m_MainWindow = nullptr;
	VengeanceDisplayMode m_WindowDisplayMode = VengeanceDisplayMode::WINDOWED;
	bool m_bVSyncEnabled = true;
	int m_iWindowHeight = 600;
	int m_iWindowWidth  = 800;
	int m_iAntiAliasingSteps = 8;
};

static VengeanceShaderSources VengeanceParseShader(const std::string& filePath)
{
	std::ifstream stream(filePath);
	std::stringstream ss[2];
	VengeanceShaderType shaderType = VengeanceShaderType::NONE;

	if (!stream.is_open())
	{
		printf("{!} Failed to open file: '%s'\n", filePath.c_str());
	}

	std::string line;

	while (std::getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				// set mode to vertex
				shaderType = VengeanceShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				// set mode to fragment
				shaderType = VengeanceShaderType::FRAGMENT;
		}
		else
		{
			ss[(int)shaderType] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}