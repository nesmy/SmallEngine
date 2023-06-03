#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Small {
    class SMALL_API Log
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
#define SE_CORE_TRACE(...)      ::Small::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)       ::Small::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...)       ::Small::Log::GetCoreLogger()-warn(__VA_ARGS__)
#define SE_CORE_ERROR(...)      ::Small::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_FATAL(...)      ::Small::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SE_TRACE(...)      ::Small::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_INFO(...)       ::Small::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_WARN(...)       ::Small::Log::GetClientLogger()-warn(__VA_ARGS__)
#define SE_ERROR(...)      ::Small::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_FATAL(...)      ::Small::Log::GetClientLogger()->fatal(__VA_ARGS__)
