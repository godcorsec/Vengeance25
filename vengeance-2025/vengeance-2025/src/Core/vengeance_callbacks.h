#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace VengeanceCallbacks
{
	void Framebuffer_Size_Callback(GLFWwindow* targetWindow, int width, int height);
}