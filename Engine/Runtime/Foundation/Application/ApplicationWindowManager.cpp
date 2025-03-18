#include "ApplicationWindowManager.hpp"

#include <unordered_set>

#include "ApplicationWindow.hpp"

namespace Orange {

struct ApplicationWindowManager::Private {
    std::unordered_set<ApplicationWindow*> windows;
};

ApplicationWindowManager& ApplicationWindowManager::GetInstance()
{
    static ApplicationWindowManager instance;
    return instance;
}

void ApplicationWindowManager::AddWindow(ApplicationWindow* window)
{
    d->windows.insert(window);
}

void ApplicationWindowManager::RemoveWindow(ApplicationWindow* window)
{
    d->windows.erase(window);
}

void ApplicationWindowManager::ForeachWindow(std::function<void(ApplicationWindow*)> func)
{
    for (auto window : d->windows) {
        func(window);
    }
}

ApplicationWindowManager::ApplicationWindowManager()
{
    d = new Private();
}

ApplicationWindowManager::~ApplicationWindowManager()
{
    delete d;
}

} // namespace Orange