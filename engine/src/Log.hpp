#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace engine {

struct SpdlogInitializer {
    SpdlogInitializer() {
        spdlog::set_pattern("%^[%l] %v%$");
    }
} _spdlog_initializer;


#ifdef NDEBUG
    #define LOG_INFO(...)
    #define LOG_WARN(...)
    #define LOG_ERROR(...)
    #define LOG_CRIT(...)
#else
    #define LOG_INFO(...)					spdlog::info(__VA_ARGS__)
    #define LOG_WARN(...)                   spdlog::warn(__VA_ARGS__)
    #define LOG_ERROR(...)                  spdlog::error(__VA_ARGS__)
    #define LOG_CRIT(...)               spdlog::critical(__VA_ARGS__)
#endif



} 