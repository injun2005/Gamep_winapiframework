#include "pch.h"
#include "Background.h"
#include "Image.h"
#include "ResMgr.h"

Background::Background()
{
	pImg = ResMgr::GetInst()->ImgLoad(L"Background", L"Image\\back_copy.bmp");

}

Background::~Background()
{
}

void Background::Update()
{
}

void Background::Render(HDC _dc)
{
	int Width = (int)pImg->GetWidth();
	int Height = (int)pImg->GetHeight();

	Vec2 vPos = GetPos();
		BitBlt(_dc
			,0
			,0
		    , Width, Height
		    , pImg->GetDC()
		    , 0,0, SRCCOPY);

}
