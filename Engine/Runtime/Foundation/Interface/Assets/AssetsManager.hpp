#pragma once

#include "Buffer.hpp"

#include "Common/Uri.hpp"

namespace Orange {

class AssetsManager {
public:
    static AssetsManager& GetInstance();

    bool Initialize();
    void Shutdown();

    Buffer Get(const Uri& uri);
};

} // namespace Orange