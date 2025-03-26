#include "SDLWindow.hpp"

#include <SDL3/SDL.h>

namespace Orange {

struct SDLWindow::Private {
    SDL_Window* window;
};

uint64_t SDLWindow::GetId() const
{
    return reinterpret_cast<uint64_t>(d->window);
}

void SDLWindow::SetTitle(const std::string& title)
{
    SDL_SetWindowTitle(d->window, title.c_str());
}

std::string SDLWindow::GetTitle() const
{
    return SDL_GetWindowTitle(d->window);
}

void SDLWindow::SetSize(SizeI size)
{
    SDL_SetWindowSize(d->window, size.GetWidth(), size.GetHeight());
}

SizeI SDLWindow::GetSize() const
{
    int width, height;
    SDL_GetWindowSize(d->window, &width, &height);
    return { width, height };
}

void SDLWindow::Show()
{
    SDL_ShowWindow(d->window);
}

void SDLWindow::Hide()
{
    SDL_HideWindow(d->window);
}

void SDLWindow::Minimize()
{
    SDL_MinimizeWindow(d->window);
}

void SDLWindow::Maximize()
{
    SDL_MaximizeWindow(d->window);
}

void SDLWindow::Restore()
{
    SDL_RestoreWindow(d->window);
}

void SDLWindow::Close()
{
    SDL_DestroyWindow(d->window);
}

SDLWindow::SDLWindow()
{
    d = new Private();

    // Create SDL window
    d->window = SDL_CreateWindow("Orange Engine", 800, 600, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
}

SDLWindow::~SDLWindow()
{
    delete d;
}

} // namespace Orange