#include "i_window.h"

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <iostream>

int main()
{
    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    auto window = orange::IWindow::Create({ 800, 600, "Test Window" });
    window->Show();

    while (true) {
        orange::IWindow::PollEvents();
    }

    return 0;
}