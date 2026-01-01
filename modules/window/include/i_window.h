#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace orange {

struct WindowOption {
    uint32_t width_;
    uint32_t height_;
    std::string title_;
};

class IWindow {
public:
    virtual ~IWindow() = default;

    static std::shared_ptr<IWindow> Create(const WindowOption& option);

    static void PollEvents();

    virtual void Show()  = 0;
    virtual void Hide()  = 0;
    virtual void Close() = 0;
};

} // namespace orange