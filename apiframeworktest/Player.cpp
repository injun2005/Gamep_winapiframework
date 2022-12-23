#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
Player::Player() : isJump(false), jumpTIme(0)
{
	// collider ����
	CreateCollider();
	GetCollider()->SetScale(Vec2(10.f, 10.f));
	GetCollider()->SetOffsetPos(Vec2(10.f, -30.f));
	// image ���ε�
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");
	// animator ���� �� animation ���
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", pImg, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);
	jumpPower = 3.3f;     
	// animation offset ���� �ø���. 
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
	if (vPos.y >= Core::GetInst()->GetResolution().y) {
		ChangeScene(SCENE_TYPE::Dead);
	}
	float gravity = GetGravity();
	if (!GetisGround()) {
		SetGravity(gravity + 1 * fDT);
		vPos.y += gravity;
	}
	if (isJump) {
		float jumpHeight =  ((jumpTIme * jumpTIme)- (jumpPower * jumpTIme)) / 4.f;
		jumpTIme += 0.01f;
		if (jumpTIme > jumpPower) {
			jumpTIme = 0;
			isJump = false;
		}
		vPos.y += jumpHeight;

	}
	if (KEY_HOLD(KEY::LEFT))
	{
		vPos.x -= 300.f * fDT;
	}
	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos.x += 300.f * fDT;
	}
	if (KEY_HOLD(KEY::SPACE))
	{
		if (GetisGround()) {
			Jump();
		}
	}

	SetPos(vPos);
	GetAnimator()->Update();


}

void Player::Jump()
{
	if (isJump) return;
	isJump = true;
	
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

	//����Ÿ ���� ���� transparent: ������
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

}

void Player::StayCollision(Collider* _pOther)
{

}

void Player::ExitCollision(Collider* _pOther)
{

}


