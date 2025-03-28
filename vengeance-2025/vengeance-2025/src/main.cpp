#include <iostream>

#include "Common/vengeance_math.h"
#include "Core/vengeance_core.h"
#include "Shaders/vengeance_shader.h"
#include "Core/vengeance_error_handling.hpp"



int main()
{
    printf("{#} Starting engine..\n");

	CVengeanceEngine engine;

	engine.Run();

    return 0;
}
