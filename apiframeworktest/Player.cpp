#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
Player::Player()
{
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	// image 업로드
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");
	isGround = false;
	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", pImg, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);

	// animation offset 위로 올리기. 
	Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	for(size_t i=0;i<pAnim->GetMaxFrame();i++)
		pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}
Player::~Player()
{
	//if(nullptr !=m_pImage)
	//	delete m_pImage;
}
void Player::Update()
{
	Vec2 vPos = GetPos();
	if(KEY_HOLD(KEY::UP))
	{
		vPos.y -= 300.f * fDT;
	}
	if (KEY_HOLD(KEY::DOWN))
	{
		vPos.y += 300.f * fDT;
	}
	if (KEY_HOLD(KEY::LEFT))
	{
		vPos.x -= 300.f * fDT;
	}
	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos.x += 300.f * fDT;
	}

	if (!isGround) {
		vPos.y += 2 *fDT;
	}
	else {
		if (KEY_TAP(KEY::SPACE))
		{
			Jump();
		}
	}
	SetPos(vPos);
	GetAnimator()->Update();


}

void Player::Jump()
{
	
}


void Player::Render(HDC _dc)
{
	Component_Render(_dc);
	/*int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();*/
	//BitBlt(_dc
	//	,(int)(vPos.x - (float)(Width / 2))
	//	,(int)(vPos.y - (float)(Height / 2))
	//    , Width, Height
	//    , m_pImage->GetDC()
	//    , 0,0, SRCCOPY);

	//마젠타 색상 뺄때 transparent: 투명한
	//TransparentBlt(_dc
	//	, (int)(vPos.x - (float)(Width / 2))
	//	, (int)(vPos.y - (float)(Height / 2))
	//	,Width, Height
	//    , m_pImage->GetDC()
	//    ,0,0, Width, Height
	//    , RGB(255,0,255));

}

void Player::EnterCollision(Collider* _pOther)
{
	UINT id = _pOther->GetCheck();

	if (id == (UINT)GROUP_TYPE::PLATFORM) {
		SetGround(true);
	}
	Vec2 vObjPos = _pOther->GetFinalPos();
	Vec2 vObjScale = _pOther->GetScale();

	Vec2 vPos = GetCollider()->GetFinalPos();
	Vec2 vScale = GetCollider()->GetScale();


	float fLen = abs(vPos.y - vObjPos.y);
	float fValue = (vScale.y / 2.f + vObjScale.y / 2.f) - fLen;

	vPos = GetPos();
	vPos.y -= fValue;
	SetPos(vPos);
}

void Player::StayCollision(Collider* _pOther)
{

}

void Player::ExitCollision(Collider* _pOther)
{
	UINT id = _pOther->GetCheck();

	if (id == (UINT)GROUP_TYPE::PLATFORM) {
		SetGround(false);
	}

}

void Player::SetGround(bool value)
{
	isGround = value;
}

