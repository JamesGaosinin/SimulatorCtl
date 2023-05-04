#pragma once

class CEffectsConfig
{
public:
	CEffectsConfig();
	~CEffectsConfig();
	static CEffectsConfig* GetInstance();
	static void Release();
	float GetShockRatio();
	float GetSwingShockRatio();
	float GetRollRatio();
	int GetYawMultiple();

private:
	bool Init();

private:
	static CEffectsConfig* m_pInstance;

	float m_fShockRatio = 1.0f;			// �������ű���
	float m_fSwingShockRatio = 1.0f;	// ת�䶶�����ӱ�������ͨ����������
	float m_fRollRatio = 1.0f;			// ������ű���
	int m_nYawMultiple = 100;			// ��������
};
