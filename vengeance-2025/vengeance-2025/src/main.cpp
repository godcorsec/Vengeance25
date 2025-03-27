#include <iostream>

#include "Common/vengeance_math.h"
#include "Core/vengeance_core.h"

int main()
{
    printf("{#} Starting engine..\n");

    VengeanceShaderSources shaderSource = VengeanceParseShader("bru");

    std::cout << shaderSource.FragmentShaderSource << std::endl;

    return 0;
}
