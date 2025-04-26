#include "Rhi.h"

#include "VkCall.h"

namespace Orange::Render::Vulkan {

bool Rhi::Initialize()
{
    LOGI("Initialize rhi");

    VkApplicationInfo appInfo = {
        .sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pNext              = nullptr,
        .pApplicationName   = "Orange Engine",
        .applicationVersion = VK_MAKE_VERSION(0, 0, 1),
        .pEngineName        = "Orange Engine",
        .engineVersion      = VK_MAKE_VERSION(0, 0, 1),
        .apiVersion         = VK_API_VERSION_1_3,
    };

    std::vector<const char*> layers = {};

    std::vector<const char*> extensions = {};

    VkInstanceCreateInfo createInfo = {
        .sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pNext                   = nullptr,
        .flags                   = 0,
        .pApplicationInfo        = &appInfo,
        .enabledLayerCount       = static_cast<uint32_t>(layers.size()),
        .ppEnabledLayerNames     = layers.data(),
        .enabledExtensionCount   = static_cast<uint32_t>(extensions.size()),
        .ppEnabledExtensionNames = extensions.data(),
    };

    VK_CALL(vkCreateInstance(&createInfo, GetAllocationCallbacks(), &_vkInstance));

    return _vkInstance != VK_NULL_HANDLE;
}

void Rhi::Shutdown()
{
    LOGI("Shutdown rhi");

    if (_vkInstance) {
        vkDestroyInstance(_vkInstance, GetAllocationCallbacks());
        _vkInstance = nullptr;
    }
}

std::vector<IPhysicalDevice> Rhi::EnumPhysicalDevice()
{
    return {};
}

const VkAllocationCallbacks* Rhi::GetAllocationCallbacks() const
{
    return nullptr;
}

}; // namespace Orange::Render::Vulkan