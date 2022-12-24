#include "pch.h"
#include "GameClearObj.h"
#include "Image.h"
#include "ResMgr.h"
GameClearObj::GameClearObj()
{
	m_pImage = ResMgr::GetInst()->ImgLoad(L"GameClaerImg", L"Image\\GameClear.bmp");
}

GameClearObj::~GameClearObj()
{

}

void GameClearObj::Update()
{
}

void GameClearObj::Render(HDC _dc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();
	BitBlt(_dc
		, vPos.x
		, vPos.y
		, Width *3, Height*3
		, m_pImage->GetDC()
		, 0, 0, SRCCOPY);
}
