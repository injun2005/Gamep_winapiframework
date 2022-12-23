#include "pch.h"
#include "GoalObj.h"
#include"Collider.h"
GoalObj::GoalObj()
{
}

GoalObj::~GoalObj()
{
}

void GoalObj::Update()
{
}

void GoalObj::EnterCollision(Collider* _pOther)
{
    Object* pOtherObj = _pOther->GetObj();
    if (pOtherObj->GetName() == L"Player")
    {
        ChangeScene(SCENE_TYPE::CLEAR);
    }
}

void GoalObj::ExitCollision(Collider* _pOther)
{
}

void GoalObj::StayCollision(Collider* _pOther)
{
}

void GoalObj::SetCollider()
{
    CreateCollider();
    Vec2 pos = GetPos();
    Vec2 scale = GetScale();

    GetCollider()->SetScale(Vec2(scale.x, scale.y));
}

void GoalObj::Render(HDC _dc)
{
    Vec2 pos = GetPos();
    Vec2 scale = GetScale();
    Rectangle(_dc,
        (int)(pos.x - scale.x)  // left
        , (int)(pos.y - scale.y / 2.f)  // top
        , (int)(pos.x + scale.x)  // right
        , (int)(pos.y + scale.y / 2.f)); // bottom
    Component_Render(_dc);
}
