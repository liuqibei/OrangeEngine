#include "ApplicationWindow.hpp"

#include <SDL3/SDL.h>

#include "ApplicationWindowManager.hpp"
#include "Foundation/Logger/Logger.hpp"

namespace Orange {

struct ApplicationWindow::Private {
    SDL_Window* window;
};

ApplicationWindow::ApplicationWindow()
{
    d = new Private();

    // Create SDL window
    d->window = SDL_CreateWindow("Orange Engine", 800, 600, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);

    // Add window to window manager
    ApplicationWindowManager::GetInstance().AddWindow(this);
}

ApplicationWindow::~ApplicationWindow()
{
    // Remove window from window manager
    ApplicationWindowManager::GetInstance().RemoveWindow(this);

    delete d;
}

void ApplicationWindow::Show()
{
    SDL_ShowWindow(d->window);
}

void ApplicationWindow::Hide()
{
    SDL_HideWindow(d->window);
}

void ApplicationWindow::Minimize()
{
    SDL_MinimizeWindow(d->window);
}

void ApplicationWindow::Maximize()
{
    if (!SDL_MaximizeWindow(d->window)) {
        LOGE("Failed to maximize window: {}", SDL_GetError());
    }
}

void ApplicationWindow::Restore()
{
    SDL_RestoreWindow(d->window);
}

void ApplicationWindow::SetTitle(const std::string& title)
{
    SDL_SetWindowTitle(d->window, title.c_str());
}

std::string ApplicationWindow::GetTitle() const
{
    return std::string(SDL_GetWindowTitle(d->window));
}

void ApplicationWindow::SetSize(uint32_t width, uint32_t height)
{
    SDL_SetWindowSize(d->window, width, height);
}

void ApplicationWindow::GetSize(uint32_t& width, uint32_t& height) const
{
    SDL_GetWindowSize(d->window, (int*)&width, (int*)&height);
}
} // namespace Orange