#pragma once

namespace Orange::Render {

class RenderContext {
public:
    static RenderContext& GetInstance();

    RenderContext(const RenderContext&)            = delete;
    RenderContext& operator=(const RenderContext&) = delete;
    RenderContext(RenderContext&&)                 = delete;
    RenderContext& operator=(RenderContext&&)      = delete;

    bool Initialize();
    void Shutdown();

private:
    RenderContext();
    ~RenderContext();

    struct Private;
    Private* d;
};

} // namespace Orange::Render