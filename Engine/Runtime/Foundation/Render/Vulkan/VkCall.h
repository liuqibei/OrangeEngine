#pragma once

#include <iostream>
#include <vulkan/vulkan.h>

#include "Logger/Logger.hpp"

#if defined(DEBUG) || defined(_DEBUG)
#define VK_CALL(x)                                                                                \
    do {                                                                                          \
        VkResult result = (x);                                                                    \
        if (result != VK_SUCCESS) {                                                               \
            LOGE("Vulkan error: {} failed with error code {}", #x, static_cast<int32_t>(result)); \
            __debugbreak();                                                                       \
        }                                                                                         \
    } while (0)
#else
#define VkCall(x) x
#endif