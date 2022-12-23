    #pragma once
#include "Scene.h"
class DeadScene :
    public Scene
{
public:
    DeadScene();
    ~DeadScene();

public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

