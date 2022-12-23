#pragma once
#include "Object.h"
#include "Image.h"
#include "GaugeBar.h"
#include "ResMgr.h"

class Background :
    public Object
{
public:
    Background();
    ~Background();

    Image* pImg;

    virtual void Update() override;
    virtual void	Render(HDC _dc);

    CLONE(Background);
};

