#pragma once

#include <cstdint>
#include <string>

namespace Orange {

class ApplicationWindow {
    struct Private;

public:
    ApplicationWindow();
    ~ApplicationWindow();

    void Show();
    void Hide();
    void Minimize();
    void Maximize();
    void Restore();
    void SetTitle(const std::string& title);
    std::string GetTitle() const;
    void SetSize(uint32_t width, uint32_t height);
    void GetSize(uint32_t& width, uint32_t& height) const;

private:
    Private* d;
};

} // namespace Orange