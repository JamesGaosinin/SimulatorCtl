#pragma once

#include <QObject>

class QTimer;
class CSimulationPlatform;

class CEffectsManager : public QObject
{
	Q_OBJECT

public:
	CEffectsManager(QObject *parent);
	~CEffectsManager();

	void Initalize();
	// 加减速特效
	void PlayAccEffects(int nLevel);
	// 转弯特效
	void PlaySwingEffects(int nDeltaValue);

signals:
	void StartAccTimer();
	void StartSwingTimer();

private slots:
	void Slot_EffectTrigger();
	void Slot_TimerAccTriggered();
	void Slot_TimerSwingTriggered();
	void Slot_TimerResumeTriggered();
	void Slot_StartAccTimer();
	void Slot_StartSwingTimer();

private:
	QTimer* m_pTimerNormal = nullptr;		// 晃动定时器
	QTimer* m_pTimerAcc = nullptr;			// 加减速特效定时器
	QTimer* m_pTimerSwing = nullptr;		// 转弯特效定时器
	QTimer* m_pTimerResume = nullptr;		// 缓慢恢复加减速特效效果 和 转弯特效效果
	int m_nAccLevel = 0;
	int m_nAccAddTimes = 0;					// 加速震荡次数
	int m_nEffectsTriggerTime = 50;
	int m_nEffectsDurationTime = 500;

	int m_nDeltaValue = 0;					// 150ms以内，实际角度*10000倍
	int m_nSwingAddTimes = 0;				// 转弯震荡次数
	CSimulationPlatform* m_pPlatform = nullptr;
};
