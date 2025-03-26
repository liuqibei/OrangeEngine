#pragma once

#include "../IWindow.hpp"

namespace Orange {

class SDLWindow final : public IWindow {
    friend class WindowManager;

public:
    uint64_t GetId() const override;

    void SetTitle(const std::string& title) override;
    std::string GetTitle() const override;

    void SetSize(SizeI size) override;
    SizeI GetSize() const override;

    void Show() override;
    void Hide() override;
    void Minimize() override;
    void Maximize() override;
    void Restore() override;
    void Close() override;

private:
    SDLWindow();
    ~SDLWindow();

    struct Private;
    Private* d;
};

} // namespace Orange