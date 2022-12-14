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
    void Update() override;
    void EnterCollision(Collider* _pOther) override;
    void ExitCollision(Collider* _pOther) override;
    void StayCollision(Collider* _pOther) override;
    void SetCollider() override;
    void Render(HDC _dc) override;
};

