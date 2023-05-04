#include "EffectsManager.h"
#include <QTimer>
#include "SimulationPlatform.h"
#include "EffectsConfig.h"

CEffectsManager::CEffectsManager(QObject *parent)
	: QObject(parent)
{
	m_pPlatform = dynamic_cast<CSimulationPlatform*>(parent);
	if (nullptr == m_pPlatform)
	{
		int a = 0;
	}
	qsrand(0);
}

CEffectsManager::~CEffectsManager()
{
}

void CEffectsManager::Initalize()
{
	if (nullptr == m_pTimerNormal)
	{
		m_pTimerNormal = new QTimer(this);
		m_pTimerNormal->setInterval(m_nEffectsTriggerTime);
		m_pTimerNormal->setSingleShot(false);
		connect(m_pTimerNormal, &QTimer::timeout, this, &CEffectsManager::Slot_EffectTrigger);
		m_pTimerNormal->start();
	}

	if (nullptr == m_pTimerAcc)
	{
		m_pTimerAcc = new QTimer(this);
		m_pTimerAcc->setInterval(m_nEffectsTriggerTime);
		m_pTimerAcc->setSingleShot(false);
		connect(m_pTimerAcc, &QTimer::timeout, this, &CEffectsManager::Slot_TimerAccTriggered);
		connect(this, &CEffectsManager::StartAccTimer, this, &CEffectsManager::Slot_StartAccTimer, Qt::QueuedConnection);
	}
	if (nullptr == m_pTimerSwing)
	{
		m_pTimerSwing = new QTimer(this);
		m_pTimerSwing->setInterval(500);
		m_pTimerSwing->setSingleShot(false);
		connect(m_pTimerAcc, &QTimer::timeout, this, &CEffectsManager::Slot_TimerSwingTriggered);
		connect(this, &CEffectsManager::StartSwingTimer, this, &CEffectsManager::Slot_StartSwingTimer, Qt::QueuedConnection);
	}
	if (nullptr == m_pTimerResume)
	{
		m_pTimerResume = new QTimer(this);
		m_pTimerResume->setInterval(m_nEffectsTriggerTime);
		m_pTimerResume->setSingleShot(false);
		connect(m_pTimerResume, &QTimer::timeout, this, &CEffectsManager::Slot_TimerResumeTriggered);
		m_pTimerResume->start();
	}
}

void CEffectsManager::Slot_EffectTrigger()
{
	if (nullptr == m_pPlatform)
	{
		return;
	}
	float fSpeed = m_pPlatform->GetSpeed();
	int nChange = qrand() % 2;

	//平时
	float fTemp = 0.0f;
	if (fSpeed > 25.0f)
	{
		fTemp = nChange == 0 ? -2.0f : 2.0f;
	}
	else if (fSpeed < 25.0f && fSpeed > 10.01f)
	{
		fTemp = nChange == 0 ? -5.0f : 5.0f;
	}
	else if (fSpeed < 10.01f && fSpeed > 1.01f)
	{
		fTemp = nChange == 0 ? -8.0f : 8.0f;
	}

	float fShockRatio = CEffectsConfig::GetInstance()->GetShockRatio();
	// 转弯
	float fYaw = m_pPlatform->GetYaw() / CEffectsConfig::GetInstance()->GetYawMultiple();
	if (fYaw > 0.01 || fYaw < -0.01)
	{
		fShockRatio += CEffectsConfig::GetInstance()->GetSwingShockRatio();
	}

	fTemp *= fShockRatio;
	m_pPlatform->SetOffsetX(fTemp); // 左右
	m_pPlatform->SetOffsetZ(fTemp);	// 上下
}

void CEffectsManager::PlayAccEffects(int nDelta)
{
	if (nullptr == m_pTimerAcc)
	{
		return;
	}
	// 传入为加速 - 减速的值
	if (nDelta > 30 && nDelta > m_nAccLevel)
	{
		m_nAccLevel = nDelta;// 综合结果，可以用于判断是加速还是减速
		m_nAccAddTimes = 0;
		emit StartAccTimer();
	}
	else if (nDelta < -30 && nDelta < m_nAccLevel)
	{
		m_nAccLevel = nDelta;// 综合结果，可以用于判断是加速还是减速
		m_nAccAddTimes = 0;
		emit StartAccTimer();
	}
}

void CEffectsManager::Slot_TimerAccTriggered()
{
	if (nullptr == m_pPlatform)
	{
		return;
	}
	m_nAccAddTimes++;
	if (m_nAccAddTimes > (m_nEffectsDurationTime / m_nEffectsTriggerTime))
	{
		m_pTimerAcc->stop();
		m_nAccAddTimes = 0;
	}

	float fOffsetY = 0;
	float fDelta = 100;
	if (m_nAccLevel > 0)
	{
		m_pPlatform->SetOffsetY(fOffsetY + fDelta);
	}
	else if (m_nAccLevel < 0)
	{
		m_pPlatform->SetOffsetY(fOffsetY - fDelta);
	}
}

void CEffectsManager::Slot_StartAccTimer()
{
	if (!m_pTimerAcc->isActive())
	{
		m_pTimerAcc->start();
	}
}

void CEffectsManager::Slot_TimerResumeTriggered()
{
	if (nullptr == m_pPlatform)
	{
		return;
	}
	float fOffsetY = m_pPlatform->GetOffsetY();
	if (fOffsetY > -20 && fOffsetY < 20)
	{
		return;
	}
	else if (fOffsetY > 0)
	{
		m_pPlatform->SetOffsetY(fOffsetY - 5);
	}
	else if (fOffsetY < 0)
	{
		m_pPlatform->SetOffsetY(fOffsetY + 5);
	}
}

void CEffectsManager::PlaySwingEffects(int nDeltaValue)
{
	//if ()
	{
		emit StartSwingTimer();
	}
	m_nDeltaValue = nDeltaValue;
}

void CEffectsManager::Slot_TimerSwingTriggered()
{
	if (nullptr == m_pPlatform)
	{
		return;
	}
	float fAngle = 1500 / 10 * m_nDeltaValue;
	if (m_nSwingAddTimes % 2 == 0)
	{
		m_pPlatform->SetYaw(fAngle);
	}
	else
	{
		m_pPlatform->SetYaw(fAngle / 3);
	}
	m_nSwingAddTimes++;
}

void CEffectsManager::Slot_StartSwingTimer()
{
	if (nullptr != m_pTimerSwing)
	{
		m_pTimerSwing->start();
	}
}
