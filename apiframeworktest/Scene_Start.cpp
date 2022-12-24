#include "pch.h"
#include "Scene_Start.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "GaugeBar.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "Platform.h"
#include "Toilet.h"
#include "GoalObj.h"
#include "Background.h"
#include "heart.h"

Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}
void Scene_Start::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\BackGroundMusic.wav");
	SoundMgr::GetInst()->Play(L"BGM");

	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	Vec2 vRHalf = Vec2(vResolution.x / 2, vResolution.y / 2);

	Object* background = new Background;
	background->SetPos(Vec2(0,0));
	background->SetScale(Vec2(1920, 1080));
	AddObject(background, GROUP_TYPE::BACKGROUD);


	Object* platform = new Platform;
	platform->SetPos(Vec2(0.f, vRHalf.y + 200));
	platform->SetScale(Vec2(100.f, 20.f));
	platform->SetCollider();
	AddObject(platform, GROUP_TYPE::PLATFORM);

	Object* platform2 = new Platform;
	platform2->SetPos(Vec2(300.f, vResolution.y / 2 + 200));
	platform2->SetScale(Vec2(50.f, 20.f));
	platform2->SetCollider();
	AddObject(platform2, GROUP_TYPE::PLATFORM);

	Object* platform3 = new Platform;
	platform3->SetPos(Vec2(500.f, vResolution.y / 2 + 200));
	platform3->SetScale(Vec2(50.f, 20.f));
	platform3->SetCollider();
	AddObject(platform3, GROUP_TYPE::PLATFORM);

	Object* platform4 = new Platform;
	platform4->SetPos(Vec2(800.f, vResolution.y / 2 + 200));
	platform4->SetScale(Vec2(100.f, 20.f));
	platform4->SetCollider();
	AddObject(platform4, GROUP_TYPE::PLATFORM);

	Object* platform5 = new Platform;
	platform5->SetPos(Vec2(1000.f, vResolution.y / 2 + 200));
	platform5->SetScale(Vec2(50.f, 20.f));
	platform5->SetCollider();
	AddObject(platform5, GROUP_TYPE::PLATFORM);


	Object* pObj = new Player;
	pObj->SetName(L"Player");
	pObj->SetPos(Vec2(20.f, vResolution.y / 2));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);
	GaugeBar* GBar = new GaugeBar;

	Object* pGBar = GBar;
	pGBar->SetPos(Vec2(1,1));
	pGBar->SetScale(Vec2(100.f, 100.f));
	AddObject(pGBar, GROUP_TYPE::GaugeBar);
	Toilet* toilet = new Toilet;
	toilet->SetGagueBar(GBar);

	/*Object* heartOBJ = new heart;
	heartOBJ->SetPos(Vec2(1, 1));
	heartOBJ->SetScale(Vec2(1, 1));
	AddObject(heartOBJ, GROUP_TYPE::Heart);*/

	Object* pToilet = toilet;
	pToilet->SetPos(Vec2(vResolution.x / 2 + 30,vResolution.y / 2 + 150));
	pToilet->SetScale(Vec2(30, 50));
	pToilet->SetCollider();
	AddObject(pToilet, GROUP_TYPE::TOILTET);

	Object* pGoal = new GoalObj;
	pGoal->SetPos(Vec2(vResolution.x - 100, vResolution.y / 2 + 150));
	pGoal->SetScale(Vec2(20, 50));
	pGoal->SetCollider();
	AddObject(pGoal, GROUP_TYPE::GOAL);

//	Object* pOtherPlayer = new Player(*(Player*)pObj);
	/*Object* pOtherPlayer = pObj->Clone();
	pOtherPlayer->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 100.f, Core::GetInst()->GetResolution().y / 2.f));
	AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/

	//m_vecObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj); 

	// Monster Object 추가
	//Monster* pMonsterObj = new Monster;
	//pMonsterObj->SetPos(Vec2(640.f, 50.f));
	//pMonsterObj->SetScale(Vec2(50.f, 50.f));
	//pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//AddObject(pMonsterObj, GROUP_TYPE::MONSTER);

	// 몬스터 배치
	//int iMonster = 16;
	//float fMoveDist = 25.f;
	//float fObjScale = 50.f;
	//float fTerm = (vResolution.x - ((fMoveDist + fObjScale /2.f) * 2)) / (float)(iMonster-1);
	//Monster* pMonsterObj = nullptr;
	//for (int i = 0; i < iMonster; i++)
	//{
	//	pMonsterObj = new Monster;
	//	pMonsterObj->SetName(L"Monster");
	//	pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i*fTerm, 50.f));
	//	pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
	//	pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//	pMonsterObj->SetMoveDistance(fMoveDist);
	//	AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	//}
	//pObj = new Object;

	//pObj->SetPos(Vec2(640.f, 384.f));
	//pObj->SetScale(Vec2(100.f, 100.f));

	//AddObject(pObj, GROUP_TYPE::DEFAULT);
	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::PLATFORM);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::TOILTET);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::GOAL);
}

void Scene_Start::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Start::Update()
{  
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::SCENE_01);
	}
}

