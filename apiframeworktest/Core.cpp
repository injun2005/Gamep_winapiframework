#include "Core.h"
#include "pch.h"
#include "Object.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "EventMgr.h"
#include "SoundMgr.h"
Core::Core()
	: m_hDC(0)
	, m_ptResolution{}
	, m_hBit(0)
	, m_memDC(0)
	, m_arrBrush{}
	, m_arrPen{}
{
}

Core::~Core()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}
}

int Core::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
	m_hDC = GetDC(m_hWnd);
	
	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	SelectObject(m_memDC, m_hBit);

	// ���� ����� �� �� �귯�� ����
	CreateBrushPen();

	// ===== Manager Init =====
	SoundMgr::GetInst()->Init();
	PathMgr::GetInst()->Init();
	TimeMgr::GetInst()->Init();
	KeyMgr::GetInst()->Init();
	SceneMgr::GetInst()->Init();
	
	return S_OK;
}

void Core::Progress()
{
	Update();
	Render();
}

void Core::Update()
{
	// ==== Manager Update====
	TimeMgr::GetInst()->Update();
	KeyMgr::GetInst()->Update();

	// ==== Scene Update ====
	SceneMgr::GetInst()->Update();

	// ==== �浹 üũ ====
	CollisionMgr::GetInst()->Update();
}


void Core::Render()
{
	// ==== Rendering ====
	PatBlt(m_memDC, 0, 0, m_ptResolution.x, m_ptResolution.y, WHITENESS); 

	SceneMgr::GetInst()->Render(m_memDC);

	// ������۸����� �׸���
		BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
			,m_memDC, 0, 0, SRCCOPY);
		TimeMgr::GetInst()->Render();
	// === �̺�Ʈ ���� ó�� === //
		EventMgr::GetInst()->Update();

}

void Core::CreateBrushPen()
{
	// HOLLOW
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	//RED GREEN BLUE PEN
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}
