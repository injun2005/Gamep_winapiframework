#pragma once
#include "Object.h"
class Image;
class GameClearObj :
    public Object
{
private:
    Image* m_pImage;
public:
    GameClearObj();
    ~GameClearObj();
    void Update() override;
private:
    CLONE(GameClearObj);
public:
    void Render(HDC _dc) override;
};

