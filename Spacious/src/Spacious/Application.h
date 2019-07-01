#pragma once

#include "Core.h"

namespace Spacious {
	class SPACIOUS_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}

