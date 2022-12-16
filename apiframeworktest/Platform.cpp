#include "pch.h"
#include "Platform.h"
#include "Collider.h"
Platform::Platform()
{


}

Platform::~Platform()
{
}

void Platform::Update()
{

}

void Platform::EnterCollision(Collider* _pOther)
{
    Object* pOtherObj = _pOther->GetObj();
    if (pOtherObj->GetName() == L"Player")
    {
        pOtherObj->SetGround(true);

        Vec2 vObjPos = _pOther->GetFinalPos();
        Vec2 vObjScale = _pOther->GetScale();

        Vec2 vPos = GetCollider()->GetFinalPos();
        Vec2 vScale = GetCollider()->GetScale();


        float fLen = abs(vObjPos.y - vPos.y);
        float fValue = (vObjScale.y / 2.f + vScale.y / 2.f) - fLen;

        vObjPos = pOtherObj->GetPos();
        vObjPos.y -= fValue;
        pOtherObj->SetPos(vObjPos);
    }
}

void Platform::ExitCollision(Collider* _pOther)
{
    Object* pOtherObj = _pOther->GetObj();
    if (pOtherObj->GetName() == L"Player")
    {
        pOtherObj->SetGround(false);
        pOtherObj->SetGravity(0);
    }
}

void Platform::StayCollision(Collider* _pOther)
{
    Object* pOtherObj = _pOther->GetObj();
    if (pOtherObj->GetName() == L"Player")
    {
        pOtherObj->SetGround(true);

        Vec2 vObjPos = _pOther->GetFinalPos();
        Vec2 vObjScale = _pOther->GetScale();

        Vec2 vPos = GetCollider()->GetFinalPos();
        Vec2 vScale = GetCollider()->GetScale();


        float fLen = abs(vObjPos.y - vPos.y);
        float fValue = (vObjScale.y / 2.f + vScale.y / 2.f) - fLen;

        vObjPos = pOtherObj->GetPos();
        vObjPos.y -= fValue;
        pOtherObj->SetPos(vObjPos);
    }
}
