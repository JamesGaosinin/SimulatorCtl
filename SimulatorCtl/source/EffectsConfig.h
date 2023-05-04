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

	float m_fShockRatio = 1.0f;			// 抖动缩放比率
	float m_fSwingShockRatio = 1.0f;	// 转弯抖动增加比率在普通抖动基础上
	float m_fRollRatio = 1.0f;			// 横滚缩放比率
	int m_nYawMultiple = 100;			// 航向夸大倍数
};
