#pragma once
#include "Core.h"

namespace Rapture 
{
	class RAPT_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	Application* CreateApplication();

}

