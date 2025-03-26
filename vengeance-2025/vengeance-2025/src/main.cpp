#include <iostream>

#include "Common/vengeance_math.h"

int main()
{
	std::cout << "Hello from Vengeance." << std::endl;

	VengeanceVec2f vec1 = { 0.1f, 0.1f };
	VengeanceVec2f vec2 = { 0.2f, 0.4f };
	VengeanceVec2f result = vec1 + vec2;

	printf("VengeanceVec2f result: (%f, %f)\n", result.x, result.y);
	

	return 0;
}