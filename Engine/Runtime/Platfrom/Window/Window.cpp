#include "Window/Window.hpp"

#include "SDL/SDLWindow.hpp"

namespace Orange {

IWindow* CreateWindow()
{
    return new SDLWindow();
}

} // namespace Orange