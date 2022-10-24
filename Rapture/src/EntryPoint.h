#pragma once

#ifdef RAPT_PLATFORM_WINDOWS

int main()
{
	Rapture::Log::Init();
	RAPT_CORE_WARN("Initialized core log...");

	int var = 69;
	RAPT_INFO("Yo Mr White. My var is -{0}", var);

	Rapture::Application* application = Rapture::CreateApplication();
	application->Run();
	delete application;

	return 0;
}

#endif