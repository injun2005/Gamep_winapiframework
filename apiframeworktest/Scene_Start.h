#pragma once
#include "Scene.h"
class Scene_Start :
    public Scene
{
private:
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;

public:
    Scene_Start();
    virtual ~Scene_Start();
};

