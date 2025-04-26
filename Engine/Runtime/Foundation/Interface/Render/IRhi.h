#pragma once

#include <vector>

#include "IPhysicalDevice.h"

namespace Orange::Render {

class IRhi {
public:
    static IRhi& GetInstance();

    IRhi() = default;

    IRhi(const IRhi&)            = delete;
    IRhi& operator=(const IRhi&) = delete;
    IRhi(IRhi&&)                 = delete;
    IRhi& operator=(IRhi&&)      = delete;

    virtual bool Initialize() = 0;
    virtual void Shutdown()   = 0;

    virtual std::vector<IPhysicalDevice> EnumPhysicalDevice() = 0;
};

}; // namespace Orange::Render