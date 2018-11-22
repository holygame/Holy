#pragma once

#include <memory> // shared_ptr
#include "Core.h"
#include "spdlog\spdlog.h"

namespace Holy {

	class HOLY_API Log
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
//core macros
#define HL_CORE_TRACE(...)		::Holy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HL_CORE_INFO(...)		::Holy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HL_CORE_WARN(...)		::Holy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HL_CORE_ERROR(...)		::Holy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HL_CORE_FATAL(...)		::Holy::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client macros
#define HL_TRACE(...)			::Holy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HL_INFO(...)			::Holy::Log::GetClientLogger()->info(__VA_ARGS__)
#define HL_WARN(...)			::Holy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HL_ERROR(...)			::Holy::Log::GetClientLogger()->error(__VA_ARGS__)
#define HL_FATAL(...)			::Holy::Log::GetClientLogger()->fatal(__VA_ARGS__)


// to stip macros out of dist code , just #define HL_CORE_TRACE to be nothing