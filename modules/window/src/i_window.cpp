#include "i_window.h"

#ifdef ORANGE_ENGINE_MODULE_WINDOW_BACKEND_GLFW
#include "glfw_window.h"
#else
#error "No window backend defined"
#endif // ORANGE_ENGINE_MODULE_WINDOW_BACKEND_GLFW

namespace orange {

std::shared_ptr<IWindow> IWindow::Create(const WindowOption& option)
{
#ifdef ORANGE_ENGINE_MODULE_WINDOW_BACKEND_GLFW
    return std::make_shared<GLFWWindow>(option);
#else
#error "No window backend defined"
#endif // ORANGE_ENGINE_MODULE_WINDOW_BACKEND_GLFW
}

void IWindow::PollEvents()
{
#ifdef ORANGE_ENGINE_MODULE_WINDOW_BACKEND_GLFW
    GLFWWindow::PollEvents();
#else
#error "No window backend defined"
#endif // ORANGE_ENGINE_MODULE_WINDOW_BACKEND_GLFW}
}

} // namespace orange