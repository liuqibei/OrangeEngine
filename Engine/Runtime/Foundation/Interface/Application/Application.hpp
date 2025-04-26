#pragma once

#include <string>
#include <vector>

#include "Common/Timestamp.hpp"

namespace Orange {

class Event;
class IScene;

class Application {
public:
    static Application& GetInstance();

    Application();
    ~Application();

    void Initialize(const std::vector<std::string>& args = {});
    void Shutdown();
    void Tick(Timestamp timestamp);
    void ProcessEvent(Event* event);

private:
    struct Private;
    Private* d;
};

} // namespace Orange