#pragma once

#include "Scene/IScene.hpp"

namespace Orange {

class Scene : public IScene {
public:
    Scene();
    virtual ~Scene() override;

    virtual void SetWindow(IWindow* window) override;

    virtual IWindow* GetWindow() const override;

    virtual bool Load(const Uri& uri) override;

private:
    struct Private;
    Private* d;
};

} // namespace Orange