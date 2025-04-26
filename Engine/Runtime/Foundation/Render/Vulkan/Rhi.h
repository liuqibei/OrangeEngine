#pragma once

#include <vulkan/vulkan.h>

#include "Render/IRhi.h"

namespace Orange::Render::Vulkan {

class Rhi final : public IRhi {
public:
    bool Initialize() override;
    void Shutdown() override;

    std::vector<IPhysicalDevice> EnumPhysicalDevice() override;

    const VkAllocationCallbacks* GetAllocationCallbacks() const;

private:
    VkInstance _vkInstance;
};

}; // namespace Orange::Render::Vulkan