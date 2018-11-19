#include "Log.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Holy {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		//set the patern to color in the right way , have the time stamp , the name of the logger , then the message
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("HOLY");
		s_CoreLogger->set_level(spdlog::level::trace);
		
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}
}
