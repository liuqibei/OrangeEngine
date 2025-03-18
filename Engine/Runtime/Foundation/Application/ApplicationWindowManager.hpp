#pragma once

#include <functional>

namespace Orange {

class ApplicationWindow;

class ApplicationWindowManager {
    struct Private;

public:
    static ApplicationWindowManager& GetInstance();

    void AddWindow(ApplicationWindow* window);
    void RemoveWindow(ApplicationWindow* window);
    void ForeachWindow(std::function<void(ApplicationWindow*)> func);

private:
    ApplicationWindowManager();
    ~ApplicationWindowManager();

    Private* d;
};

} // namespace Orange