#pragma once
#include "Object.h"
class GoalObj :
    public Object
{
public:
    GoalObj();
    ~GoalObj();

private:
    CLONE(GoalObj);
public:
    void Update() override;
    void EnterCollision(Collider* _pOther) override;
    void ExitCollision(Collider* _pOther) override;
    void StayCollision(Collider* _pOther) override;
    void SetCollider() override;
    void Render(HDC _dc) override;
};

