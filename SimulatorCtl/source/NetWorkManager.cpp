#define WASHOUT
#include "NetWorkManager.h"
#include <string>
#include <chrono>
#include <QUdpSocket>
#include <QTimer>
#include <QCoreApplication>
#include "UDPSocketImp.h"
#include "SimulationNetWorkManager.h"
#include "SimulationPlatform.h"
#include "LogSystem.h"
#include "SimulationSendThread.h"
#include "../3thPart/include/IBusClientv3.h"
#include "../3thPart/include/PackData.h"
#include "../3thPart/include/3Dcmd.h"

using namespace _3Dcmd;

CNetWorkManager* CNetWorkManager::m_pInstance = nullptr;

CNetWorkManager::CNetWorkManager(QObject* parent)
	: QObject(parent)
	, m_eSimulationStatus(E_SimulationPlatformStatus_Unkown)
{
	Init();
}

CNetWorkManager::~CNetWorkManager()
{
	
}

CNetWorkManager* CNetWorkManager::GetInstance()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CNetWorkManager;
	}

	return m_pInstance;
}

void CNetWorkManager::Release()
{
	if (nullptr != m_pInstance)
	{
		if (nullptr != m_pInstance->m_pUDPClient)
		{
			m_pInstance->m_pUDPClient->deleteLater();
		}

		if (nullptr != m_pInstance->m_pNetThread)
		{
			if (!m_pInstance->m_pNetThread->isFinished())
			{
				m_pInstance->m_pNetThread->quit();
				if (!m_pInstance->m_pNetThread->wait(5000))
				{
					m_pInstance->m_pNetThread->terminate();
				}
				delete m_pInstance->m_pNetThread;
				m_pInstance->m_pNetThread = nullptr;
			}
		}

		if (nullptr != m_pInstance->m_pSendThread)
		{
			if (!m_pInstance->m_pSendThread->isFinished())
			{
				m_pInstance->m_pSendThread->quit();
				if (!m_pInstance->m_pSendThread->wait(5000))
				{
					m_pInstance->m_pSendThread->terminate();
				}
				delete m_pInstance->m_pSendThread;
				m_pInstance->m_pSendThread = nullptr;
			}
		}

		if (nullptr != m_pInstance->m_pMileClient)
		{
			::ReleaseIBusClient(m_pInstance->m_pMileClient);
		}
		
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CNetWorkManager::Close()
{
	if (nullptr != m_pUDPClient)
	{
		m_pUDPClient->Close();
	}
}

void CNetWorkManager::SendCtrlData()
{
	if (nullptr == m_pSendThread)
	{
		return;
	}

	if (!m_pSendThread->isRunning())
	{
		m_pSendThread->start();
	}
}

bool CNetWorkManager::SendOnData()
{
	if (nullptr == m_pUDPClient)
	{
		return false;
	}

	SimulationCtrlWashInfo sendData;
	auto nowClock = std::chrono::system_clock::now();
	long long lMilliSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(nowClock.time_since_epoch()).count();
	sendData.time = lMilliSeconds;
	sendData.ctrlCMD |= E_Cmd_Code_Work;
	sendData.ctrlCMD |= E_Cmd_Code_Wash;
	sendData.SetLow8Bit();

	const int nCount = sizeof(sendData);
	char buffer[nCount] = { 0 };
	memcpy(buffer, &sendData, sizeof(sendData));
	int nSendSize = m_pUDPClient->writeDatagram(buffer, nCount, m_HostAddr, m_usPort);

	return true;
}

bool CNetWorkManager::SendOffData()
{
	if (nullptr == m_pUDPClient)
	{
		return false;
	}

	SimulationCtrlWashInfo sendData;
	auto nowClock = std::chrono::system_clock::now();
	long long lMilliSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(nowClock.time_since_epoch()).count();
	sendData.time = lMilliSeconds;
	sendData.ctrlCMD |= E_Cmd_Code_Stop;
	sendData.ctrlCMD |= E_Cmd_Code_Wash;
	sendData.SetLow8Bit();

	const int nCount = sizeof(sendData);
	char buffer[nCount] = { 0 };
	memcpy(buffer, &sendData, sizeof(sendData));
	int nSendSize = m_pUDPClient->writeDatagram(buffer, nCount, m_HostAddr, m_usPort);

	return true;
}

E_SimulationPlatformStatus CNetWorkManager::GetPlatStatus()
{
	return m_eSimulationStatus;
}

void CNetWorkManager::Slot_StatusChanged(int nStatus)
{
	m_eSimulationStatus = E_SimulationPlatformStatus(nStatus);
	CSimulationPlatform::GetInstance()->SetStatus(m_eSimulationStatus);
}

void CNetWorkManager::Init()
{
	InitSimulationNetWork();
	InitMileClient();
	InitConnect();
	if (nullptr == m_pSendThread)
	{
		m_pSendThread = new CSimulationSendThread;
		m_pSendThread->Inintalize(m_pUDPClient, m_HostAddr, m_usPort);
	}
}

void CNetWorkManager::InitSimulationNetWork()
{
	if (nullptr == m_pConfigMgr)
	{
		m_pConfigMgr = new CSimulationNetWorkManager(this);
		QString strFilePath = QCoreApplication::applicationDirPath();
		strFilePath += QString("/config/SimulationNetWorkConfig.xml");
		m_pConfigMgr->Initalize(strFilePath);
	}

	if (nullptr == m_pUDPClient)
	{
		m_pUDPClient = new CUDPSocketImp;
		m_HostAddr.setAddress(m_pConfigMgr->GetAddr());
		m_usPort = m_pConfigMgr->GetPort();
		m_pUDPClient->Initalize(m_HostAddr, m_usPort);
		connect(m_pUDPClient, &CUDPSocketImp::Sig_SimulationStatus, this, &CNetWorkManager::Slot_StatusChanged, Qt::QueuedConnection);
		do 
		{
			if (!m_pUDPClient->isValid())
			{
				break;
			}

			if (nullptr == m_pNetThread)
			{
				m_pNetThread = new QThread(this);
				m_pNetThread->start();
				m_pUDPClient->moveToThread(m_pNetThread);
				emit m_pUDPClient->Sig_StartRecv();
			}
		} while (0);
	}
}

void CNetWorkManager::InitMileClient()
{
	if (nullptr == m_pMileClient)
	{
		char err[255] = { 0 };
		m_pMileClient = CreateIBusClient("clientTMS", err);
		if (nullptr == m_pMileClient)
		{
			return;
		}
		m_pMileClient->SetDataCallback([](ClientPackData* pData, void* arg)
		{
			if (nullptr == pData)
			{
				return;
			}
			CNetWorkManager* pThis = (CNetWorkManager*)(arg);
			// TOD信息
			if (pData->head.id == 0x51)//TOD信息
			{
				TCMD m_cmd;
				memcpy(&m_cmd, pData->data, sizeof(TCMD));
				if (m_cmd.nType == DT_GLB)//公里标
				{
					stRTGLBInfo m_3dDate;
					memset(&m_3dDate, 0, sizeof(stRTGLBInfo));
					memcpy(&m_3dDate, pData->data, sizeof(stRTGLBInfo));
				
					float f_sPeed = m_3dDate.speed;
					float fCurGLB = m_3dDate.tf + 10700.0;
					if (nullptr != CSimulationPlatform::GetInstance())
					{
						emit pThis->Sig_UpDownTypeChanged((E_SimulationFlat_UpDown_Type)m_3dDate.des);
						emit pThis->Sig_SpeedChanged(f_sPeed);
						emit pThis->Sig_PositionChanged(fCurGLB);
					}
				}
			}
			else if (pData->head.id == 0x52)//TOD信息
			{
				TCMD m_cmd;
				memcpy(&m_cmd, pData->data, sizeof(TCMD));
				if (m_cmd.nType == DT_SyncTrainDirction)//列车车头向量
				{
					SimulatiorVector stSimulatorVector;
					memcpy(&stSimulatorVector, pData->data, sizeof(SimulatiorVector));
					if (nullptr != CSimulationPlatform::GetInstance())
					{
						emit pThis->Sig_VectorChanged(stSimulatorVector);
					}
				}
			}
			else if (pData->head.id == 0x45)//TOD信息
			{
				stBoardingData Data;
				memcpy(&Data, pData->data, sizeof(stBoardingData));
				if (nullptr != CSimulationPlatform::GetInstance())
				{
					unsigned char cStatus = 0;
					if (Data.boardingDown == 1)
					{
						cStatus |= E_Boad_Status_Down;
					}
					if (Data.boardingUp == 1)
					{
						cStatus |= E_Boad_Status_Up;
					}
					if (Data.adsStatus == -1)
					{
						cStatus |= E_Boad_Status_Error;
					}

					if (nullptr != CSimulationPlatform::GetInstance())
					{
						emit pThis->Sig_BoadStatusChanged(cStatus);
						emit pThis->Sig_AccBrakeChanged(Data.tractionGrade, Data.brakeGrade);
						emit pThis->Sig_RunMode(Data.runMode);
						emit pThis->Sig_Eb(Data.eb);
						emit pThis->Sig_Dir(Data.dir);
					}
				}
			}
		}, this);
		m_pMileClient->Start();
	}
}

void CNetWorkManager::ConstructCtrlData(SimulatorCtrlData& sendData)
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}
	sendData.frameHead.frameHead1 = 0xFB;
	sendData.frameHead.frameHead2 = 0xFD;

	sendData.heightOffset = pInstance->GetOffsetY();
	sendData.roll = pInstance->GetRoll();
	sendData.pitch = pInstance->GetPitch();
	sendData.yaw = pInstance->GetYaw();

	sendData.SetSumLow8Bit();
}

void CNetWorkManager::ConstructCtrlWashData(SimulationCtrlWashInfo& sendData)
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	auto nowClock = std::chrono::system_clock::now();
	long long lMilliSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(nowClock.time_since_epoch()).count();

	sendData.time = lMilliSeconds;

	sendData.offsetY = pInstance->GetOffsetY();
	sendData.roll = pInstance->GetRoll();
	sendData.pitch = pInstance->GetPitch();;
	sendData.yaw = pInstance->GetYaw();

	sendData.ctrlCMD |= E_Cmd_Code_Work;
	sendData.ctrlCMD |= E_Cmd_Code_Wash;

	sendData.SetLow8Bit();
}

void CNetWorkManager::InitConnect()
{
	connect(this, &CNetWorkManager::Sig_UpDownTypeChanged, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_UpDownTypeChanged, Qt::QueuedConnection);
	connect(this, &CNetWorkManager::Sig_SpeedChanged, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_SpeedChanged, Qt::QueuedConnection);
	connect(this, &CNetWorkManager::Sig_PositionChanged, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_PositionChanged, Qt::QueuedConnection);
	connect(this, &CNetWorkManager::Sig_VectorChanged, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_VectorChanged, Qt::QueuedConnection);
	connect(this, &CNetWorkManager::Sig_BoadStatusChanged, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_BoadStatusChanged, Qt::QueuedConnection);
	connect(this, &CNetWorkManager::Sig_AccBrakeChanged, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_AccBrakeChanged, Qt::QueuedConnection);
	connect(this, &CNetWorkManager::Sig_RunMode, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_RunModeChanged, Qt::QueuedConnection);
	connect(this, &CNetWorkManager::Sig_Eb, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_EbChanged, Qt::QueuedConnection);
	connect(this, &CNetWorkManager::Sig_Dir, CSimulationPlatform::GetInstance(), &CSimulationPlatform::Slot_DirChanged, Qt::QueuedConnection);
}
