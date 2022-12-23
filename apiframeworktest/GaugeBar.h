#pragma once
#include "Object.h"
#include "Image.h"
class GaugeBar :
    public Object
{
private:
    Vec2 BarLenght;
public:

    Image* pImg;

    GaugeBar();
    ~GaugeBar();

public:
    virtual void Render(HDC _dc) override;
    virtual void Update() override;
    void Release();
    CLONE(GaugeBar);
};

