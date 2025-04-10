#include "Scene.hpp"

#include "Window/IWindow.hpp"

namespace Orange {

struct Scene::Private {
    Uri uri;
    bool isLoaded   = false;
    IWindow* window = nullptr;
};

Scene::Scene()
{
    d = new Private();
}

Scene::~Scene()
{
    delete d;
}

void Scene::SetWindow(IWindow* window)
{
    d->window = window;
}

IWindow* Scene::GetWindow() const
{
    return d->window;
}

bool Scene::Load(const Uri& uri)
{
    if (uri.IsValid()) {
        d->uri      = uri;
        d->isLoaded = true;
        return true;
    }
    return false;
}

} // namespace Orange