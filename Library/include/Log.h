#include "spdlog/spdlog.h"


#define SmallInfo_0(a)                      spdlog::info(a)
#define SmallInfo_1(a,b)                    spdlog::info(a,b)
#define SmallInfo_x(x, a, b, FUNC, ...)     FUNC
#define SmallInfo(...)                      SmallInfo_x(,##__VA_ARGS__, \
                                                        SmallInfo_1(__VA_ARGS__),\
                                                        SmallInfo_0(__VA_ARGS__))

#define SmallWarn_0(a)                      spdlog::warn(a)
#define SmallWarn_1(a,b)                    spdlog::warn(a,b)
#define SmallWarn_x(x, a, b, FUNC, ...)     FUNC
#define SmallWarn(...)                      SmallWarn_x(,##__VA_ARGS__, \
                                                        SmallWarn_1(__VA_ARGS__),\
                                                        SmallWarn_0(__VA_ARGS__))