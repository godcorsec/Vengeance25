#include "vengeance_core.h"
#include "vengeance_callbacks.h"

#include <glad/glad.h>
#include <stdexcept>


void CVengeanceEngine::Initialize()
{
	// Start by initializing OpenGL, loading functions pointers and whatever else
	glfwInit();
	
	// Todo: Add checking for the VengeanceDisplayMode, and create the window based on that.

	m_WindowProperties.m_MainWindow = glfwCreateWindow(m_WindowProperties.m_iWindowWidth, m_WindowProperties.m_iWindowHeight, "VengeanceR25-OGL", nullptr, nullptr);

	if (!m_WindowProperties.m_MainWindow)
	{
		throw std::runtime_error("{!} The glfwCreateWindow() call failed: m_MainWindow is invalid\n");
		glfwTerminate();
	}

	glfwMakeContextCurrent(m_WindowProperties.m_MainWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("{!} The gladLoadGLLoader() call failed\n");
		glfwTerminate();
	}

	// Initialize Vengeance's custom callbacks.
	glfwSetFramebufferSizeCallback(m_WindowProperties.m_MainWindow ,VengeanceCallbacks::Framebuffer_Size_Callback);
	

	printf("{#} OPENGL VERSION: %s\n", glGetString(GL_VERSION));
	printf("{#} RENDERER: %s\n", glGetString(GL_RENDERER));

}


void CVengeanceEngine::Run()
{
	Initialize();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(m_WindowProperties.m_MainWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);


		glfwPollEvents();

		glfwSwapBuffers(m_WindowProperties.m_MainWindow);
	}
}