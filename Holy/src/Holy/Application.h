#pragma once

#include "Core.h"

namespace Holy {

	class HOLY_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};
	// defined in client
	Application* CreateApplication();
}