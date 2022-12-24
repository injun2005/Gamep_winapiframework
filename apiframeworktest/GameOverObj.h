#pragma once
#include "Object.h"
class Image;
class GameOverObj :
    public Object
{
private:
    Image* m_pImage;
public:
    GameOverObj();
    ~GameOverObj();

private:
    CLONE(GameOverObj);
public:
    void Update() override;
    void Render(HDC _dc) override;
};

