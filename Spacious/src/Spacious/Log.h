#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"


namespace Spacious {

	class SPACIOUS_API Log
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

//Core log macros
#define SP_CORE_TRACE(...) ::Spacious::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...)  ::Spacious::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_CORE_WARN(...)  ::Spacious::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...) ::Spacious::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_FATAL(...) ::Spacious::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SP_TRACE(...)      ::Spacious::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_INFO(...)       ::Spacious::Log::GetClientLogger()->info(__VA_ARGS__)
#define SP_WARN(...)       ::Spacious::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...)      ::Spacious::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_FATAL(...)      ::Spacious::Log::GetClientLogger()->fatal(__VA_ARGS__)