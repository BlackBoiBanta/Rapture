#pragma once

#ifdef RAPT_PLATFORM_WINDOWS
	#ifdef RAPT_BUILD_DLL
		#define RAPT_API __declspec(dllexport)
	#else 
		#define RAPT_API __declspec(dllimport)
	#endif
#else 
	#error Rapture only runs on Windows. Linux, Mac, etc are shyte anyways...
#endif