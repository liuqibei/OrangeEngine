#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
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