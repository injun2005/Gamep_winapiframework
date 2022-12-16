#pragma once
#include "Object.h"
class Platform :
    public Object
{
public:
    Platform();
    ~Platform();

private:
    CLONE(Platform);

public:
    virtual void Update() override;
    virtual void EnterCollision(Collider* _pOther) override;
    virtual void ExitCollision(Collider* _pOther) override;
    virtual void StayCollision(Collider* _pOther) override;

    
};

