#include "pch.h"
#include "GameOverObj.h"
#include "Image.h"
#include "ResMgr.h"
GameOverObj::GameOverObj()
{
	m_pImage = ResMgr::GetInst()->ImgLoad(L"GameOverImg", L"Image\\GameOver.bmp");

}

GameOverObj::~GameOverObj()
{
}

void GameOverObj::Update()
{

}

void GameOverObj::Render(HDC _dc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();
	BitBlt(_dc
		, vPos.x
		, vPos.y
		, Width * 3, Height * 3
		, m_pImage->GetDC()
		, 0, 0, SRCCOPY);
}
