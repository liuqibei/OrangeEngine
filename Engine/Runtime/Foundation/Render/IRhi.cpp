#include "Render/IRhi.h"

#include "Vulkan/Rhi.h"

namespace Orange::Render {

IRhi& IRhi::GetInstance()
{
    static Vulkan::Rhi instance;
    return instance;
}

} // namespace Orange::Render