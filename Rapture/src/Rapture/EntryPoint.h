#pragma once

#ifdef RAPT_PLATFORM_WINDOWS
#include "Application.h"
#

int main()
{
	Rapture::Application* application = new Application();
	sandBox->Run();
	delete sandBox;

	return 0;
}

#endif