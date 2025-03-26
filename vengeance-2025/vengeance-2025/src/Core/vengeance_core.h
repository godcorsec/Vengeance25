#pragma once

#include <GLFW/glfw3.h>

class CVengeanceEngine
{
	void Run();

private:

	void Initialize();

	GLFWwindow* m_MainWindow;
};