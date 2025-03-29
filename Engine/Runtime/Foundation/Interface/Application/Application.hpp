#pragma once

#include "Timestamp.hpp"

namespace Orange {

class Event;

class Application {
public:
    static Application& GetInstance();

    Application();
    ~Application();

    void Initialize();
    void Shutdown();
    void Tick(Timestamp timestamp);
    void ProcessEvent(Event* event);

private:
    struct Private;
    Private* d;
};

} // namespace Orange