#include "WindowManager.hpp"

#include <SDL3/SDL.h>
#include <memory>
#include <unordered_map>

#include "SDL/SDLWindow.hpp"

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
    return SDL_Init(SDL_INIT_VIDEO) == 0;
}

void WindowManager::Shutdown()
{
    d->windows.clear();

    SDL_Quit();
}

IWindow* WindowManager::Create()
{
    auto window = new SDLWindow();
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