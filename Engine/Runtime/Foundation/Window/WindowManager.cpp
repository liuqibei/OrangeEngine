#include "WindowManager.hpp"

#include <memory>
#include <unordered_map>

#include "Window/IWindow.hpp"
#include "Window/Window.hpp"

namespace Orange {

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
    return window;
}

void WindowManager::Destroy(uint64_t id)
{
    d->windows.erase(id);
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