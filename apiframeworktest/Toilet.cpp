#include "pch.h"
#include "Toilet.h"
#include "Collider.h"
#include"GaugeBar.h"
Toilet::Toilet() : gagueBar(nullptr)
{
}

Toilet::~Toilet()
{
	
}

void Toilet::Update()
{

}

void Toilet::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Player") {
		gagueBar->Release();
	}
}

void Toilet::ExitCollision(Collider* _pOther)
{

}

void Toilet::StayCollision(Collider* _pOther)
{
}

void Toilet::Render(HDC _dc)
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
