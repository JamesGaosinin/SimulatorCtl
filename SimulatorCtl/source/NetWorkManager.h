#pragma once
#include <QObject>
#include <QString>
#include <QHostAddress>
#include "../include/CommonHeader.h"
#include "../3thPart/include/3Dcmd.h"

class QUdpSocket;
class QTimer;
class CSimulationNetWorkManager;
class CUDPSocketImp;
class QThread;
class CSimulationSendThread;
class IBusClient;

Q_DECLARE_METATYPE(_3Dcmd::SimulatiorVector)
Q_DECLARE_METATYPE(E_SimulationFlat_UpDown_Type)

class CNetWorkManager : public QObject
{
	Q_OBJECT

public:
	CNetWorkManager(QObject* parent = nullptr);
	~CNetWorkManager();
	static CNetWorkManager* GetInstance();
	static void Release();

	void Close();

public:
	void SendCtrlData();
	bool SendOnData();
	bool SendOffData();
	bool SendStatusRequestData();
	E_SimulationPlatformStatus GetPlatStatus();

signals:
	void Sig_UpDownTypeChanged(E_SimulationFlat_UpDown_Type eType);
	void Sig_SpeedChanged(float fSpeed);
	void Sig_PositionChanged(float fCurGLB);
	void Sig_VectorChanged(const _3Dcmd::SimulatiorVector& stVector);
	void Sig_BoadStatusChanged(unsigned char cStatus);
	void Sig_AccBrakeChanged(int nAccLevel, int nBrakeLevel);
	void Sig_RunMode(int nMode);
	void Sig_Eb(int nEb);
	void Sig_Dir(int nEb);

private slots :
	void Slot_StatusChanged(int nStatus);

private:
	void Init();
	void InitSimulationNetWork();
	void InitMileClient();
	void InitConnect();

private:
	// 老协议
	void ConstructCtrlData(SimulatorCtrlData& sendData);
	// 新协议
	void ConstructCtrlWashData(SimulationCtrlWashInfo& sendData);

private:
	static CNetWorkManager* m_pInstance;
	CSimulationNetWorkManager* m_pConfigMgr = nullptr;
	CUDPSocketImp* m_pUDPClient = nullptr;
	QHostAddress m_HostAddr;
	unsigned short m_usPort;
	E_SimulationPlatformStatus m_eSimulationStatus;

	QThread* m_pNetThread = nullptr;
	CSimulationSendThread* m_pSendThread = nullptr;
	IBusClient* m_pMileClient = nullptr;
};
