#include "SimulationPlatform.h"
#include <iostream>
#include <QMutexLocker>
#include <QTimer>
#include <QTime>
#include "EffectsManager.h"
#include "EffectsConfig.h"

CSimulationPlatform* CSimulationPlatform::m_pInstance = nullptr;

CSimulationPlatform::CSimulationPlatform(QObject *parent)
	: QObject(parent)
	, m_eSimulationStatus(E_SimulationPlatformStatus_Unkown)
	, m_eSimulationUpDownType(E_SimulationFlat_UpDown_Type_Unkown)
{
	memset(m_fMagneticLenth, 0, sizeof(m_fMagneticLenth));
	Init();
	m_pInstance = this;
}

CSimulationPlatform::~CSimulationPlatform()
{
	if (nullptr != m_pTimerOff)
	{
		m_pTimerOff->stop();
	}
	m_pInstance = nullptr;
}

CSimulationPlatform* CSimulationPlatform::GetInstance()
{
	return m_pInstance;
}

void CSimulationPlatform::GetMagneticLenth(float* pData)
{
	QMutexLocker lock(&m_Mutex);
	for (int i = 0; i < 6; ++i)
	{
		pData[i] = m_fMagneticLenth[i];
	}
}

void CSimulationPlatform::SetMagneticLenth(float* pData)
{
	if (nullptr == pData)
	{
		return;
	}

	QMutexLocker lock(&m_Mutex);
	for (int i = 0; i < 6; ++i)
	{
		m_fMagneticLenth[i] = pData[i];
	}
}

float CSimulationPlatform::GetPitch()
{
	QMutexLocker lock(&m_Mutex);
	return m_fPitch;
}

void CSimulationPlatform::SetPitch(float fPitch)
{
	QMutexLocker lock(&m_Mutex);
	m_fPitch = fPitch;
}

float CSimulationPlatform::GetRoll()
{
	QMutexLocker lock(&m_Mutex);
	return m_fRoll;
}

void CSimulationPlatform::SetRoll(float fRoll)
{
	QMutexLocker lock(&m_Mutex);
	m_fRoll = fRoll;
}

float CSimulationPlatform::GetYaw()
{
	QMutexLocker lock(&m_Mutex);
	return m_fYaw;
}

void CSimulationPlatform::SetYaw(float fYaw)
{
	QMutexLocker lock(&m_Mutex);
	m_fYaw = fYaw;
}

float CSimulationPlatform::GetOffsetX()
{
	QMutexLocker lock(&m_Mutex);
	return m_fOffSetX;
}

void CSimulationPlatform::SetOffsetX(float fValue)
{
	QMutexLocker lock(&m_Mutex);
	m_fOffSetX = fValue;
}

float CSimulationPlatform::GetOffsetY()
{
	QMutexLocker lock(&m_Mutex);
	return m_fOffSetY;
}

void CSimulationPlatform::SetOffsetY(float fValue)
{
	QMutexLocker lock(&m_Mutex);
	m_fOffSetY = fValue;
}

float CSimulationPlatform::GetOffsetZ()
{
	QMutexLocker lock(&m_Mutex);
	return m_fOffSetZ;
}

void CSimulationPlatform::SetOffsetZ(float fValue)
{
	QMutexLocker lock(&m_Mutex);
	m_fOffSetZ = fValue;
}

float CSimulationPlatform::GetAccX()
{
	QMutexLocker lock(&m_Mutex);
	return m_fAccX;
}

void CSimulationPlatform::SetAccX(float fValue)
{
	QMutexLocker lock(&m_Mutex);
	m_fAccX = fValue;
}

float CSimulationPlatform::GetAccY()
{
	QMutexLocker lock(&m_Mutex);
	return m_fAccY;
}

void CSimulationPlatform::SetAccY(float fValue)
{
	QMutexLocker lock(&m_Mutex);
	m_fAccY = fValue;
}

float CSimulationPlatform::GetAccZ()
{
	QMutexLocker lock(&m_Mutex);
	return m_fAccZ;
}

void CSimulationPlatform::SetAccZ(float fValue)
{
	QMutexLocker lock(&m_Mutex);
	m_fAccZ = fValue;
}

float CSimulationPlatform::GetSpeed()
{
	QMutexLocker lock(&m_Mutex);
	return m_fSpeed;
}

void CSimulationPlatform::SetSpeed(float fSpeed)
{
	QMutexLocker lock(&m_Mutex);
	m_fSpeed = fSpeed;
	m_fTrainAcc = (m_fSpeed - m_fLastSpeed) / 0.15;
	std::cout << m_fTrainAcc << std::endl;
	m_fLastSpeed = m_fSpeed;

	//修改特效定时器
	if (DOUBLE_IS_NULL(m_fSpeed))
	{
		m_fPitch = 0.0f;
		m_fYaw = 0.0f;
		m_fRoll = 0.0f;
	}
}

E_SimulationFlat_UpDown_Type CSimulationPlatform::GetUpDownType()
{
	QMutexLocker lock(&m_Mutex);
	return m_eSimulationUpDownType;
}

void CSimulationPlatform::SetUpDownType(E_SimulationFlat_UpDown_Type eType)
{
	QMutexLocker lock(&m_Mutex);
	m_eSimulationUpDownType = eType;
}

float CSimulationPlatform::GetPosition()
{
	QMutexLocker lock(&m_Mutex);
	return m_fPosition;
}

void CSimulationPlatform::SetPosition(float fPosition)
{
	QMutexLocker lock(&m_Mutex);
	m_fPosition = fPosition;
}

E_SimulationPlatformStatus CSimulationPlatform::GetStatus()
{
	QMutexLocker lock(&m_Mutex);
	return m_eSimulationStatus;
}

void CSimulationPlatform::SetStatus(E_SimulationPlatformStatus eStatus)
{
	QMutexLocker lock(&m_Mutex);
	m_eSimulationStatus = eStatus;

	if (nullptr != m_pTimerOff)
	{
		m_pTimerOff->start();
	}
}

void CSimulationPlatform::SetSimulatorVector(_3Dcmd::SimulatiorVector& stVector)
{
	if (DOUBLE_IS_NULL(m_fSpeed))
	{
		return;
	}

	QTime::currentTime();
	CVector3D vec3DLast = CVector3D(stVector.lastForwardX, stVector.lastForwardY, stVector.lastForwardZ);
	CVector3D vec3DCurrent = CVector3D(stVector.curForwardX, stVector.curForwardY, stVector.curForwardZ);
	vec3DLast.Normalize();
	vec3DCurrent.Normalize();

	m_fPitch = vec3DCurrent.GetPitch();
	float fAngle1 = vec3DLast.GetCourse();
	float fAngle2 = vec3DCurrent.GetCourse();
	float fDeltaAngle = fAngle2 - fAngle1;
	float fDeltaValue = -fDeltaAngle * 10000;// 转弯角度左转未正，右转未负 分辨率 10000
	m_fYaw = fDeltaAngle * CEffectsConfig::GetInstance()->GetYawMultiple();
	//m_pEffectsManager->PlaySwingEffects(fDeltaValue);
}

void CSimulationPlatform::Init()
{
	if (nullptr == m_pTimerOff)
	{
		m_pTimerOff = new QTimer(this);
		m_pTimerOff->setInterval(10000);
		m_pTimerOff->setSingleShot(false);
		connect(m_pTimerOff, &QTimer::timeout, this, [=](){ 
			emit Sig_DoadStatusChanged(0);
		});
		connect(this, &CSimulationPlatform::Sig_StatusTimerRestart, this, &CSimulationPlatform::Slot_StatusTimerRestart, Qt::QueuedConnection);
		emit Sig_StatusTimerRestart();
	}

	if (nullptr == m_pTimerRunModeMonitoring)
	{
		m_pTimerRunModeMonitoring = new QTimer(this);
		m_pTimerRunModeMonitoring->setInterval(500);
		m_pTimerRunModeMonitoring->setSingleShot(false);
		connect(m_pTimerRunModeMonitoring, &QTimer::timeout, this, &CSimulationPlatform::Slot_RunModeTimeout);
		m_pTimerRunModeMonitoring->start();
	}

	for (int i = 0; i < 6; ++i)
	{
		m_fMagneticLenth[i] = 0.0f;
	}

	if (nullptr == m_pEffectsManager)
	{
		m_pEffectsManager = new CEffectsManager(this);
		m_pEffectsManager->Initalize();
	}
}

unsigned char CSimulationPlatform::GetBoadStatus()
{
	QMutexLocker lock(&m_Mutex);
	return m_cBoadStaus;
}

void CSimulationPlatform::SetBoadStatus(unsigned char cStatus)
{
	QMutexLocker lock(&m_Mutex);
	{
		m_cBoadStaus = cStatus;
		emit Sig_DoadStatusChanged(cStatus);
	}

	// 用于记录等车梯状态10秒内未收到消息，停止发送控制平台数据
	emit Sig_StatusTimerRestart();
}

void CSimulationPlatform::SetAccBrakeLevel(int nAcc, int nBrake)
{
	QMutexLocker lock(&m_Mutex);
	if (DOUBLE_IS_NULL(m_fSpeed))
	{
		return;
	}

	int nDelta = nAcc - nBrake;
	if (nullptr != m_pEffectsManager)
	{
		m_pEffectsManager->PlayAccEffects(nDelta);
	}

	m_nAccLevel = nDelta;
}

void CSimulationPlatform::Slot_StatusTimerRestart()
{
	if (nullptr != m_pTimerOff)
	{
		m_pTimerOff->start();
	}
}


void CSimulationPlatform::Slot_UpDownTypeChanged(E_SimulationFlat_UpDown_Type eType)
{
	QMutexLocker lock(&m_Mutex);
	m_eSimulationUpDownType = eType;
}

void CSimulationPlatform::Slot_SpeedChanged(float fSpeed)
{
	QMutexLocker lock(&m_Mutex);
	m_fSpeed = fSpeed;
	m_fTrainAcc = (m_fSpeed - m_fLastSpeed) / 0.15;
	//std::cout << m_fTrainAcc << std::endl;
	m_fLastSpeed = m_fSpeed;

	//修改特效定时器
	if (DOUBLE_IS_NULL(m_fSpeed))
	{
		m_fPitch = 0.0f;
		m_fYaw = 0.0f;
		m_fRoll = 0.0f;
	}
}

void CSimulationPlatform::Slot_PositionChanged(float fCurGLB)
{
	QMutexLocker lock(&m_Mutex);
	m_fPosition = fCurGLB;
}

void CSimulationPlatform::Slot_VectorChanged(const _3Dcmd::SimulatiorVector& stVector)
{
	if (DOUBLE_IS_NULL(m_fSpeed))
	{
		return;
	}

	QTime::currentTime();
	CVector3D vec3DLast = CVector3D(stVector.lastForwardX, stVector.lastForwardY, stVector.lastForwardZ);
	CVector3D vec3DCurrent = CVector3D(stVector.curForwardX, stVector.curForwardY, stVector.curForwardZ);
	vec3DLast.Normalize();
	vec3DCurrent.Normalize();

	m_fPitch = vec3DCurrent.GetPitch();
	float fAngle1 = vec3DLast.GetCourse();
	float fAngle2 = vec3DCurrent.GetCourse();
	float fDeltaAngle = fAngle2 - fAngle1;
	float fDeltaValue = fDeltaAngle * 10000;// 转弯角度左转未正，右转未负 分辨率 10000
	m_fYaw = fDeltaAngle * CEffectsConfig::GetInstance()->GetYawMultiple();
}

void CSimulationPlatform::Slot_BoadStatusChanged(unsigned char cStatus)
{
	QMutexLocker lock(&m_Mutex);
	{
		m_cBoadStaus = cStatus;
		emit Sig_DoadStatusChanged(cStatus);
	}

	// 用于记录等车梯状态10秒内未收到消息，停止发送控制平台数据
	emit Sig_StatusTimerRestart();
}

void CSimulationPlatform::Slot_AccBrakeChanged(int nAcc, int nBrake)
{
	QMutexLocker lock(&m_Mutex);
	if (DOUBLE_IS_NULL(m_fSpeed))
	{
		return;
	}

	int nDelta = nAcc - nBrake;
	if (nullptr != m_pEffectsManager)
	{
		m_pEffectsManager->PlayAccEffects(m_nDir ? -nDelta : nDelta);
	}

	m_nAccLevel = nDelta;
}

void CSimulationPlatform::Slot_RunModeChanged(int nMode)
{
	QMutexLocker lock(&m_Mutex);
	m_nRunMode = nMode;
}

void CSimulationPlatform::Slot_EbChanged(int nEb)
{
	QMutexLocker lock(&m_Mutex);
	m_nEb = nEb;
}

void CSimulationPlatform::Slot_DirChanged(int nDir)
{
	QMutexLocker lock(&m_Mutex);
	m_nDir = nDir;
}

void CSimulationPlatform::Slot_RunModeTimeout()
{
	if (DOUBLE_IS_NULL(m_fSpeed))
	{
		return;
	}

	// ATO
	if (m_nRunMode == 1)
	{
		if (m_fTrainAcc > 0.3f)
		{
			m_pEffectsManager->PlayAccEffects(100);
		}
		else if (m_fTrainAcc < -0.3f)
		{
			m_pEffectsManager->PlayAccEffects(-100);
		}
	}
	// Eb
	if (m_nEb == 1)
	{
		m_pEffectsManager->PlayAccEffects(-100);
	}
}
