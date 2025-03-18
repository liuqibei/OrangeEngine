#pragma once

#include "ApplicationTimestamp.hpp"

namespace Orange {

class Event;

class Application {
    struct Private;

public:
    static Application& GetInstance();

    Application();
    ~Application();

    void Initialize();
    void Shutdown();
    void Tick(ApplicationTimestamp timestamp);
    void ProcessEvent(Event* event);

private:
    Private* d;
};

} // namespace Orange