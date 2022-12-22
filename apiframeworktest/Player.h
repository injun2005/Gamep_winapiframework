#pragma once
#include "Object.h"

class Image;
class Player :
    public Object
{
private:
    Image* m_pImage;
    bool isJump;
    float jumpTIme;
    float jumpPower;
public:
    Player();
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~Player();
private:
    void Jump();

//    Player* Clone{ return new Player(*this); }
    CLONE(Player);
public:
    void Update()       override;
    void Render(HDC _dc) override;
    void EnterCollision(Collider* _pOther) override;
    void StayCollision(Collider* _pOther) override;
    void ExitCollision(Collider* _pOther) override;
};

