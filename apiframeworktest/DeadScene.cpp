#include "pch.h"
#include "DeadScene.h"
#include "GameOverObj.h"
DeadScene::DeadScene()
{
}

DeadScene::~DeadScene()
{
}

void DeadScene::Enter()
{
	Object* gameOverObj = new GameOverObj;
	gameOverObj->SetPos(Vec2(0, 0));
	gameOverObj->SetScale(Vec2(1920, 1080));
	AddObject(gameOverObj, GROUP_TYPE::BACKGROUD);
}

void DeadScene::Exit()
{

}

void DeadScene::Update()
{
}
