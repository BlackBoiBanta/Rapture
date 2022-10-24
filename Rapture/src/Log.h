#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Rapture
{
	class RAPT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros
#define RAPT_CORE_WARN(...)	 Rapture::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RAPT_CORE_INFO(...)	 Rapture::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RAPT_CORE_ERROR(...) Rapture::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RAPT_CORE_TRACE(...) Rapture::Log::GetCoreLogger()->trace(__VA_ARGS__)   // prints out everything
#define RAPT_CORE_FATAL(...) Rapture::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros

#define RAPT_WARN(...)  Rapture::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RAPT_INFO(...)  Rapture::Log::GetClientLogger()->info(__VA_ARGS__)
#define RAPT_ERROR(...)	Rapture::Log::GetClientLogger()->error(__VA_ARGS__)
#define RAPT_TRACE(...)	Rapture::Log::GetClientLogger()->trace(__VA_ARGS__)   // prints out everything
#define RAPT_FATAL(...)	Rapture::Log::GetClientLogger()->fatal(__VA_ARGS__)
