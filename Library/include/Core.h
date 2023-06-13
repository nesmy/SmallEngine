#pragma once

#ifdef SE_PLATFORM_WINDOWS
    #ifdef SE_BUILD_DLL
        #define SMALL_API __declspec(dllexport)
    #else
        #define SMALL_API __declspec(dllimport)
    #endif
#else
    #define SMALL_API /* Window*/
#endif

#ifdef SE_ENABLE_ASSERTS
    #define SE_ASSERT(x, ...) { if(!(x)) {SE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
    #define SE_CORE_ASSERT(x, ...) { if(!(x)) { SE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
    #define SE_ASSERT(x, ...)
    #define SE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) ( 1<< x)