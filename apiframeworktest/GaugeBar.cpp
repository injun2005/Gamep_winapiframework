#include "pch.h"
#include "GaugeBar.h"

GaugeBar::GaugeBar() : BarLenght(100,20)
{
	
}

GaugeBar::~GaugeBar()
{

}

void GaugeBar::Render(HDC _dc)
{
	Rectangle(_dc,1,1, BarLenght.x, BarLenght.y); 
}

void GaugeBar::Update()
{
	if(BarLenght.x < 0) ChangeScene(SCENE_TYPE::Dead);

	BarLenght.x -= 0.01f;
}
