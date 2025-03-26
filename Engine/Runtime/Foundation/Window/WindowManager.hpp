#pragma once

#include <cstdint>

namespace Orange {

class IWindow;

class WindowManager final {
public:
    static WindowManager& GetInstance();

    bool Initialize();
    void Shutdown();

    IWindow* Create();

    void Destroy(uint64_t id);

private:
    WindowManager();
    ~WindowManager();

    struct Private;
    Private* d;
};

} // namespace Orange