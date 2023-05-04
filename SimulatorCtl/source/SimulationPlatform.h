#pragma once

#include <QObject>
#include <QMutex>
#include "../include/CommonHeader.h"
#include "../3thPart/include/3Dcmd.h"
#include "vector3D.h"

class QTimer;
class CEffectsManager;

class CSimulationPlatform : public QObject
{
	Q_OBJECT

public:
	CSimulationPlatform(QObject *parent = nullptr);
	~CSimulationPlatform();
	static CSimulationPlatform* GetInstance();

public:
	void GetMagneticLenth(float* pData);
	void SetMagneticLenth(float* pData);

	float GetPitch();
	void SetPitch(float fPitch);

	float GetRoll();
	void SetRoll(float fRoll);

	float GetYaw();
	void SetYaw(float fYaw);

	float GetOffsetX();
	void SetOffsetX(float fValue);

	float GetOffsetY();
	void SetOffsetY(float fValue);

	float GetOffsetZ();
	void SetOffsetZ(float fValue);

	float GetAccX();
	void SetAccX(float fValue);

	float GetAccY();
	void SetAccY(float fValue);

	float GetAccZ();
	void SetAccZ(float fValue);

	float GetSpeed();
	void SetSpeed(float fSpeed);

	E_SimulationFlat_UpDown_Type GetUpDownType();
	void SetUpDownType(E_SimulationFlat_UpDown_Type eType);

	float GetPosition();
	void SetPosition(float fPosition);

	E_SimulationPlatformStatus GetStatus();
	void SetStatus(E_SimulationPlatformStatus eStatus);

	unsigned char GetBoadStatus();
	void SetBoadStatus(unsigned char cBoadStatus);

	void SetSimulatorVector(_3Dcmd::SimulatiorVector& stVector);

	void SetAccBrakeLevel(int nAcc, int nBrake);

signals:
	void Sig_DoadStatusChanged(unsigned char cStatus);
	void Sig_StatusTimerRestart();

public slots:
	void Slot_StatusTimerRestart();

	void Slot_UpDownTypeChanged(E_SimulationFlat_UpDown_Type eType);
	void Slot_SpeedChanged(float fSpeed);
	void Slot_PositionChanged(float fCurGLB);
	void Slot_VectorChanged(const _3Dcmd::SimulatiorVector& stVector);
	void Slot_BoadStatusChanged(unsigned char cStatus);
	void Slot_AccBrakeChanged(int nAcc, int nBrake);

	void Slot_RunModeChanged(int nMode);
	void Slot_EbChanged(int nEb);
	void Slot_DirChanged(int nDir);

	void Slot_RunModeTimeout();

private:
	void Init();

private:
	static CSimulationPlatform* m_pInstance;

	QMutex m_Mutex;
	float m_fMagneticLenth[6];		// 电缸伸缩长度(作废)

	float m_fPitch = 0.0f;					// 俯仰
	float m_fRoll = 0.0f;					// 横滚
	float m_fYaw = 0.0f;					// 航向（并非真实航向，给定一个相对方向）

	float m_fOffSetX = 0.0f;				// 左右
	float m_fOffSetY = 0.0f;				// 前后
	float m_fOffSetZ = 0.0f;				// 高度

	float m_fAccX = 0.0f;					// x方向的加速度
	float m_fAccY = 0.0f;					// y方向的加速度
	float m_fAccZ = 0.0f;					// z方向的加速度

	float m_fLastSpeed = 0.0f;				// 上一帧的速度
	float m_fSpeed = 0.0f;					// 速度 m/s
	float m_fPosition = 0.0f;				// 公里标
	E_SimulationFlat_UpDown_Type m_eSimulationUpDownType;
	E_SimulationPlatformStatus m_eSimulationStatus;

	CVector3D m_vec3DStright;				// 直线行驶的世界坐标方向向量（用于转弯时添加转弯特效）
	QTimer* m_pTimerOff = nullptr;			// 模拟器心跳失效定时器
	int m_nEffectsTickCount = 20;			// 特效响应时间

	unsigned char m_cBoadStaus = 0;
	int m_nAccLevel = 0;

	int m_nRunMode = 0;						// 0 手动模式 1 自动驾驶模式
	int m_nEb = 0;							// 0 无Eb 1 有Eb
	int m_nDir = 0;							// 0 前进 2 后退
	float m_fTrainAcc = 0.0f;				// 列车加速度
	QTimer* m_pTimerRunModeMonitoring = nullptr;			// 模拟器心跳失效定时器

	CEffectsManager* m_pEffectsManager = nullptr;
};
