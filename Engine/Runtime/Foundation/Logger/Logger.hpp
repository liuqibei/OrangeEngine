#pragma once

#if defined(DEBUG) || defined(_DEBUG)
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#endif

#include <spdlog/spdlog.h>

namespace Orange {

bool SetupLogger();

}

#define LOGT SPDLOG_TRACE
#define LOGD SPDLOG_DEBUG
#define LOGI SPDLOG_INFO
#define LOGW SPDLOG_WARN
#define LOGE SPDLOG_ERROR
#define LOGC SPDLOG_CRITICAL