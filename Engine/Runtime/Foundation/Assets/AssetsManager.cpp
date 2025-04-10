#include "Assets/AssetsManager.hpp"

namespace Orange {

AssetsManager& AssetsManager::GetInstance()
{
    static AssetsManager instance;
    return instance;
}

} // namespace Orange