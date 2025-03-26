#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "vengeance_math.h"

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


struct VengeanceWindowProperties
{
	GLFWwindow* m_MainWindow = nullptr;
	VengeanceDisplayMode m_WindowDisplayMode = VengeanceDisplayMode::WINDOWED;
	bool m_bVSyncEnabled = true;
	int m_iWindowHeight = 600;
	int m_iWindowWidth  = 800;
	int m_iAntiAliasingSteps = 8;
};