#include "pch.h"
#include "heart.h"
#include "ResMgr.h"

heart::heart()
{
	pImg = ResMgr::GetInst()->ImgLoad(L"Heart", L"Image\\heart.bmp");
}

heart::~heart()
{
}

void heart::Render(HDC _dc)
{
	BitBlt(_dc
		, 1
		, 1
		, pImg->GetWidth(), pImg->GetHeight()
		, pImg->GetDC()
		, 0, 0, SRCCOPY);

	TransparentBlt(_dc
			, 1
			, 1
			, pImg->GetWidth(), pImg->GetHeight()
		    , pImg->GetDC()
		    ,0,0, pImg->GetWidth(), pImg->GetHeight()
		    , RGB(255,255,255));
}

void heart::Update()
{
}
