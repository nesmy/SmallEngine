#pragma once

//#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Launcher {
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

//Core log macros
#define SE_CORE_TRACE(...)      ::Launcher::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)       ::Launcher::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...)       ::Launcher::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...)      ::Launcher::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_FATAL(...)      ::Launcher::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SE_TRACE(...)      ::Launcher::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_INFO(...)       ::Launcher::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_WARN(...)       ::Launcher::Log::GetClientLogger()-warn(__VA_ARGS__)
#define SE_ERROR(...)      ::Launcher::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_FATAL(...)      ::Launcher::Log::GetClientLogger()->fatal(__VA_ARGS__)