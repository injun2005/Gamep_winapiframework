#pragma once
#include "Scene.h"
class ClearScene :
    public Scene
{
public:
    ClearScene();
    ~ClearScene();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

