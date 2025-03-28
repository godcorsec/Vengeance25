#include "vengeance_core.h"
#include "vengeance_callbacks.h"

#include <glad/glad.h>
#include <stdexcept>
#include "vengeance_error_handling.hpp"
#include "../Shaders/vengeance_shader.h"

float positions[] = {
	-0.5f, -0.5f,
	0.5f, -0.5f,
	0.5f,  0.5f,
	-0.5, 0.5f,
};

unsigned int indices[] = {
	0, 1, 2,
	2, 3, 0
};


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

	unsigned int buffer{};

	VengeanceCatchGLError(glGenBuffers(1, &buffer));
	VengeanceCatchGLError(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	VengeanceCatchGLError(glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW));
	VengeanceCatchGLError(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

	unsigned int ibo{};
	VengeanceCatchGLError(glGenBuffers(1, &ibo));
	VengeanceCatchGLError(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	VengeanceCatchGLError(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));

	VengeanceShader shader("Resources/Shaders/Basic.shader");
	unsigned int comped_shader = shader.CompileShader();

	VengeanceCatchGLError(glUseProgram(comped_shader));
	VengeanceCatchGLError(glEnableVertexAttribArray(0));

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(m_WindowProperties.m_MainWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		VengeanceCatchGLError(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		glfwSwapBuffers(m_WindowProperties.m_MainWindow);
		glfwPollEvents();

	}
}