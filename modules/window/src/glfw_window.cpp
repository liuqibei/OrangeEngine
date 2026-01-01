#include "glfw_window.h"

#include <atomic>

namespace orange {

static std::atomic_bool glfwInitialized { false };

GLFWWindow::GLFWWindow(const WindowOption& option)
{
    if (!glfwInitialized.exchange(true)) {
        glfwInit();
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindow_ = glfwCreateWindow(option.width_, option.height_, option.title_.c_str(), nullptr, nullptr);
}

GLFWWindow::~GLFWWindow()
{
    Close();
}

void GLFWWindow::PollEvents()
{
    glfwPollEvents();
}

void GLFWWindow::Show()
{
    glfwShowWindow(glfwWindow_);
}

void GLFWWindow::Hide()
{
    glfwHideWindow(glfwWindow_);
}

void GLFWWindow::Close()
{
    if (glfwWindow_) {
        glfwDestroyWindow(glfwWindow_);
        glfwWindow_ = nullptr;
    }
}

} // namespace orange