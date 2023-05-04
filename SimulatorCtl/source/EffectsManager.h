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
	// �Ӽ�����Ч
	void PlayAccEffects(int nLevel);
	// ת����Ч
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
	QTimer* m_pTimerNormal = nullptr;		// �ζ���ʱ��
	QTimer* m_pTimerAcc = nullptr;			// �Ӽ�����Ч��ʱ��
	QTimer* m_pTimerSwing = nullptr;		// ת����Ч��ʱ��
	QTimer* m_pTimerResume = nullptr;		// �����ָ��Ӽ�����ЧЧ�� �� ת����ЧЧ��
	int m_nAccLevel = 0;
	int m_nAccAddTimes = 0;					// �����𵴴���
	int m_nEffectsTriggerTime = 50;
	int m_nEffectsDurationTime = 500;

	int m_nDeltaValue = 0;					// 150ms���ڣ�ʵ�ʽǶ�*10000��
	int m_nSwingAddTimes = 0;				// ת���𵴴���
	CSimulationPlatform* m_pPlatform = nullptr;
};
