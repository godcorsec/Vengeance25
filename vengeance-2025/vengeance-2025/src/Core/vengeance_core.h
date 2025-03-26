#pragma once
#include "../Common/vengeance_structs.h"


class CVengeanceEngine
{
public:

	void Run();

private:

	void Initialize();

	VengeanceWindowProperties m_WindowProperties;
};