#include "WindowManager.hpp"

#include <memory>
#include <unordered_map>

#include "Logger/Logger.hpp"
#include "Window/IWindow.hpp"

namespace Orange {

// Forward declaration of the CreateWindow function
extern IWindow* CreateWindow();

struct WindowManager::Private {
    std::unordered_map<uint64_t, std::unique_ptr<IWindow>> windows;
};

WindowManager& WindowManager::GetInstance()
{
    static WindowManager instance;
    return instance;
}

bool WindowManager::Initialize()
{
    return true;
}

void WindowManager::Shutdown()
{
    d->windows.clear();
}

IWindow* WindowManager::Create()
{
    auto window = CreateWindow();
    d->windows.emplace(window->GetId(), window);

    LOGI("create window success! id: {}", window->GetId());

    return window;
}

void WindowManager::Destroy(uint64_t id)
{
    auto it = d->windows.find(id);
    if (it != d->windows.end()) {
        d->windows.erase(it);
    } else {
        LOGI("destroy window failed! id: {}", id);
    }
}

IWindow* WindowManager::GetWindow(uint64_t id) const
{
    auto it = d->windows.find(id);
    if (it != d->windows.end()) {
        return it->second.get();
    }

    LOGE("find window: {} failed!", id);

    return nullptr;
}

WindowManager::WindowManager()
{
    d = new Private();
}

WindowManager::~WindowManager()
{
    delete d;
}

} // namespace Orange