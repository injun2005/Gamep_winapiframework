#include "pch.h"
#include "ClearScene.h"
#include"Object.h"
#include "GameClearObj.h"
#include "KeyMgr.h"
ClearScene::ClearScene()
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Enter()
{
	Object* gameClearObj = new GameClearObj;
	gameClearObj->SetPos(Vec2(0, 0));
	gameClearObj->SetScale(Vec2(1920, 1080));
	AddObject(gameClearObj, GROUP_TYPE::BACKGROUD);
}

void ClearScene::Exit()
{
}

void ClearScene::Update()
{
	Scene::Update();
}
