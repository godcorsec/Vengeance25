#include <iostream>
#include <glad/glad.h>
#include "vengeance_callbacks.h"

void VengeanceCallbacks::Framebuffer_Size_Callback(GLFWwindow* targetWindow, int width, int height)
{
	glViewport(0, 0, width, height);
	printf("{#} New glViewport(0, 0, %i, %i)\n", width, height);
}

