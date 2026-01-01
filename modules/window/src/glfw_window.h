#pragma once

#include <GLFW/glfw3.h>

#include "i_window.h"

namespace orange {

class GLFWWindow : public IWindow {
public:
    GLFWWindow(const WindowOption& option);
    ~GLFWWindow() override;

    static void PollEvents();

    void Show() override;
    void Hide() override;
    void Close() override;

private:
    ::GLFWwindow* glfwWindow_;
};

} // namespace orange