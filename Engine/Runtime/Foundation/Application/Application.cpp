#include "Application.hpp"

#include "Foundation/Logger/Logger.hpp"

namespace Orange {

struct Application::Private {};

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

void Application::Initialize()
{
    LOGI("Application initialized");
}

void Application::Shutdown()
{
    LOGI("Application shutdown");
}

void Application::Tick(Timestamp timestamp)
{
    LOGT("Application tick, start: {}ms, delta: {}ms", timestamp.GetStart(), timestamp.GetDelta());
}

void Application::ProcessEvent(Event* event) {}

} // namespace Orange