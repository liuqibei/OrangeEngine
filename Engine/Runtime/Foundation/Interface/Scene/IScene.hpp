#pragma once

#include "ILifeCycle.hpp"

#include "Common/Uri.hpp"

namespace Orange {

class IWindow;

class IScene : public ILifeCycle {
public:
    virtual ~IScene() = default;

    virtual void SetWindow(IWindow* window) = 0;
    virtual IWindow* GetWindow() const      = 0;

    virtual bool Load(const Uri& uri) = 0;
};

} // namespace Orange