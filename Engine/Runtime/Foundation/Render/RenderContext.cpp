#include "Render/RenderContext.h"

#include "Logger/Logger.hpp"

#include "Render/IRhi.h"

namespace Orange::Render {

struct RenderContext::Private {
    IRhi& rhi = IRhi::GetInstance();
};

RenderContext& RenderContext::GetInstance()
{
    static RenderContext instance;
    return instance;
}

bool RenderContext::Initialize()
{
    LOGI("initialize render system");

    return d->rhi.Initialize();
}

void RenderContext::Shutdown()
{
    LOGI("shutdown render system");

    d->rhi.Shutdown();
}

RenderContext::RenderContext()
{
    d = new Private();
}

RenderContext::~RenderContext()
{
    delete d;
}

} // namespace Orange::Render