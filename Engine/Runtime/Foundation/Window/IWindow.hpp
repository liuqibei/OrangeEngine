#pragma once

#include <cstdint>
#include <string>

#include "Base/Math/Size.hpp"

namespace Orange {

class IWindow {
public:
    virtual ~IWindow() = default;

    virtual uint64_t GetId() const = 0;

    virtual void SetTitle(const std::string& title) = 0;
    virtual std::string GetTitle() const            = 0;

    virtual void SetSize(SizeI size) = 0;
    virtual SizeI GetSize() const    = 0;

    virtual void Show()     = 0;
    virtual void Hide()     = 0;
    virtual void Minimize() = 0;
    virtual void Maximize() = 0;
    virtual void Restore()  = 0;
    virtual void Close()    = 0;
};

} // namespace Orange