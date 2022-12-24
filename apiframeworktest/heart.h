#pragma once
#include "Object.h"
#include "Image.h"

class heart :
    public Object
{
public:
    heart();
    ~heart();

    Image* pImg;

public:
    virtual void Render(HDC _dc) override;
    virtual void Update() override;
    CLONE(heart);
};

