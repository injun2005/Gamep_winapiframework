#pragma once
#include "Object.h"
class GaugeBar;
class Toilet :
    public Object
{
private:
    GaugeBar* gagueBar;
    CLONE(Toilet);
public:
    Toilet();
    ~Toilet();
public:
    void SetGagueBar(GaugeBar *_bar) {
        gagueBar = _bar;
    }
    void Update() override;
    void EnterCollision(Collider* _pOther) override;
    void ExitCollision(Collider* _pOther) override;
    void StayCollision(Collider* _pOther) override;
    void Render(HDC _dc) override;
    void SetCollider() override;
};

