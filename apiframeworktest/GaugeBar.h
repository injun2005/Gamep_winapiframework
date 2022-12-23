#pragma once
#include "Object.h"
class GaugeBar :
    public Object
{
private:
    Vec2 BarLenght;
public:
    GaugeBar();
    ~GaugeBar();

public:
    virtual void Render(HDC _dc) override;
    virtual void Update() override;
    void Release();
    CLONE(GaugeBar);
};

