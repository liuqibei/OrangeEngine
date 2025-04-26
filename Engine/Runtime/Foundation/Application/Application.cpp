#include "Application/Application.hpp"

#include "Logger/Logger.hpp"
#include "Window/WindowManager.hpp"

#include "Render/RenderContext.h"

namespace Orange {

using namespace Orange::Render;

struct Application::Private {
    std::vector<std::string> args;
    IWindow* mainWindow = nullptr;
};

Application& Application::GetInstance()
{
    static Application instance;
    return instance;
}

Application::Application()
{
    d = new Private();
}

Application::~Application()
{
    delete d;
}

void Application::Initialize(const std::vector<std::string>& args)
{
    LOGI("Application initialized");

    d->args = args;

    // Initialize the window manager
    if (!WindowManager::GetInstance().Initialize()) {
        LOGE("Failed to initialize window manager");
        return;
    }

    // Create Main Window
    d->mainWindow = WindowManager::GetInstance().Create();

    // Initialize the render system
    if (!RenderContext::GetInstance().Initialize()) {
        LOGE("Failed to initialize render system");
        return;
    }
}

void Application::Shutdown()
{
    LOGI("Application shutdown");

    // Shutdown the render system
    RenderContext::GetInstance().Shutdown();

    // Shutdown the window manager
    WindowManager::GetInstance().Shutdown();
}

void Application::Tick(Timestamp timestamp)
{
    LOGT("Application tick, start: {}ms, delta: {}ms", timestamp.GetStart(), timestamp.GetDelta());
}

void Application::ProcessEvent(Event* event) {}

} // namespace Orange