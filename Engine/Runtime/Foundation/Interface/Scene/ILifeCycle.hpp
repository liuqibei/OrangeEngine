#pragma once

#include "Common/Timestamp.hpp"

namespace Orange {

class ILifeCycle {
public:
    virtual ~ILifeCycle() = default;

    virtual void OnCreate()                = 0;
    virtual void OnDestroy()               = 0;
    virtual void OnStart()                 = 0;
    virtual void OnStop()                  = 0;
    virtual void OnPause()                 = 0;
    virtual void OnResume()                = 0;
    virtual void OnUpdate(Timestamp stamp) = 0;
    virtual void OnRender()                = 0;
};

} // namespace Orange