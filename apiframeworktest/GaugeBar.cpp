#include "pch.h"
#include "GaugeBar.h"
#include "ResMgr.h"

GaugeBar::GaugeBar() : BarLenght(100,20)
{
	pImg = ResMgr::GetInst()->ImgLoad(L"GaugeBar", L"Image\\cloud.bmp");

	BarLenght.x = pImg->GetWidth();
	BarLenght.y = pImg->GetHeight();
}

GaugeBar::~GaugeBar()
{

}

void GaugeBar::Render(HDC _dc)
{
		BitBlt(_dc
			,1
			,1
		    , BarLenght.x, BarLenght.y
		    , pImg->GetDC()
		    , 0,0, SRCCOPY);

	//Rectangle(_dc,1,1, BarLenght.x, BarLenght.y); 
}

void GaugeBar::Update()
{
	if(BarLenght.x < 0) ChangeScene(SCENE_TYPE::Dead);
	
	BarLenght.x -= 0.01f;
}

void GaugeBar::Release()
{
	BarLenght = Vec2(100, 20);
}
