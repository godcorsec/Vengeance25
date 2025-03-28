#pragma once

#include <iostream>
#include <glad/glad.h>

// This was stolen from The Cherno youtube, so if I'm unsure How actually good this is, but I think it'll do for now- seems to work
#define ASSERT(x) if (!(x)) __debugbreak();
#define VengeanceCatchGLError(x) VengeanceClearGLErrors(); x; ASSERT(VengeanceLogGLCall(#x, __FILE__, __LINE__))


static void VengeanceClearGLErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool VengeanceLogGLCall(const char* functionName, const char* fileName, int fileLine)
{
	while (GLenum error = glGetError())
	{
		std::cout << "{!} [OpenGL Error] " << error
			<< "\nFunction: " << functionName
			<< "\nFile: " << fileName
			<< "\nLine: " << fileLine
			<< std::endl;
		return false;
	}
	
	return true;
}

