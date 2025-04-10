#include "Application/Application.hpp"

#include "Logger/Logger.hpp"
#include "Window/WindowManager.hpp"

namespace Orange {

struct Application::Private {
    std::vector<std::string> args;
    IScene* mainScene = nullptr;
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
}

void Application::Shutdown()
{
    LOGI("Application shutdown");

    // Shutdown the window manager
    WindowManager::GetInstance().Shutdown();
}

void Application::Tick(Timestamp timestamp)
{
    LOGT("Application tick, start: {}ms, delta: {}ms", timestamp.GetStart(), timestamp.GetDelta());
}

void Application::ProcessEvent(Event* event) {}

} // namespace Orange