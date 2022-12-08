#include "pch.h"
#include "SoundMgr.h"
#include "PathMgr.h"
SoundMgr::SoundMgr()
	:m_pSystem(nullptr)
{}
SoundMgr::~SoundMgr()
{
	Safe_Delete_Map(m_mapSod);
	// �� ���� �� �Ŀ��� �ݵ�� close, release�ؾ���.
	m_pSystem->close();
	m_pSystem->release();
}
void SoundMgr::Init()
{
	FMOD::System_Create(&m_pSystem);
	if (m_pSystem != nullptr)
		m_pSystem->init(10, FMOD_INIT_NORMAL, NULL);
}
void SoundMgr::LoadSound(const wstring& _strKey, bool _bLoop, const wstring& _strRelativePath)
{
	// ã���� ���� x
	if (FindSound(_strKey))
		return;
	wstring strFilePath = PathMgr::GetInst()->GetRsrcPath();
	strFilePath += _strRelativePath;

	// wstring to string
	string str;
	size_t size;
	str.resize(strFilePath.length());
	wcstombs_s(&size, &str[0], str.size() + 1, strFilePath.c_str(), strFilePath.size());

	// ���� ���� ���� ����
	FMOD_MODE eMode = FMOD_LOOP_NORMAL; // �ݺ� ���
	if (!_bLoop)
		eMode = FMOD_DEFAULT; // ���� 1���� ���

	PSOUNDINFO ptSound = new SOUNDINFO;
	ptSound->bLoop = _bLoop;
	m_pSystem->createSound(str.c_str(), eMode, NULL, &ptSound->pSound);
	m_mapSod.insert({ _strKey,ptSound });
}

void SoundMgr::Play(const wstring& _strKey)
{
	PSOUNDINFO ptSound = FindSound(_strKey);
	if (!ptSound)
		return;

	m_pSystem->update();
	SOUND_CHANNEL eChannel = SOUND_CHANNEL::SC_BGM;
	if (!ptSound->bLoop)
		eChannel = SOUND_CHANNEL::SC_EFFECT;
	m_pSystem->playSound(ptSound->pSound, NULL, false, &m_pChannel[(UINT)eChannel]);
}

void SoundMgr::Pause(SOUND_CHANNEL _eChannel, bool _p)
{
	m_pChannel[(UINT)_eChannel]->setPaused(_p);
}
void SoundMgr::Stop(SOUND_CHANNEL _eChannel)
{
	m_pChannel[(UINT)_eChannel]->stop();
}

void SoundMgr::Volume(SOUND_CHANNEL _eChannel, float _fVol)
{
	m_pChannel[(UINT)_eChannel]->setVolume(_fVol);
}

PSOUNDINFO SoundMgr::FindSound(const wstring& _strKey)
{
	map<wstring, PSOUNDINFO>::iterator iter = m_mapSod.find(_strKey);

	if (iter == m_mapSod.end())
		return nullptr;
	return iter->second;
}
