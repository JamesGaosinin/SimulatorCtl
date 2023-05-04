#include "SimulationSendThread.h"
#include <chrono>
#include <QUdpSocket>
#include "../include/CommonHeader.h"
#include "SimulationPlatform.h"
#include "LogSystem.h"

CSimulationSendThread::CSimulationSendThread(QObject *parent)
	: QThread(parent)
	, m_pSenderSocket(nullptr)
{
}

CSimulationSendThread::~CSimulationSendThread()
{
}

void CSimulationSendThread::Inintalize(QUdpSocket* pSenderSocket, QHostAddress& host, unsigned short usPort)
{
	m_pSenderSocket = pSenderSocket;
	m_HostAddress = host;
	m_usPort = usPort;
}

void CSimulationSendThread::run()
{
	if (nullptr == m_pSenderSocket)
	{
		return;
	}

	SimulationCtrlWashInfo sendData;
	ConstructCtrlWashData(sendData);

	const int nCount = sizeof(sendData);
	char buffer[nCount] = { 0 };
	memcpy(buffer, &sendData, sizeof(sendData));
	int nSendSize = m_pSenderSocket->writeDatagram(buffer, nCount, m_HostAddress, m_usPort);
	QString strTemp = m_pSenderSocket->errorString();

	double dPosition = 0.0;
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr != pInstance)
	{
		dPosition = pInstance->GetPosition();
	}

	std::string strMsg = 
		std::string("�����:") + std::to_string(dPosition)
		+ std::string(" ����:") + std::to_string(sendData.pitch)
		+ std::string(" ���:") + std::to_string(sendData.roll)
		+ std::string(" ����:") + std::to_string(sendData.yaw)
		+ std::string(" Xƫ��:") + std::to_string(sendData.offsetX)
		+ std::string(" Yƫ��:") + std::to_string(sendData.offsetY)
		+ std::string(" Zƫ��:") + std::to_string(sendData.offsetZ)
		+ std::string(" X���ٶ�:") + std::to_string(sendData.accX)
		+ std::string(" Y���ٶ�:") + std::to_string(sendData.accY)
		+ std::string(" Z���ٶ�:") + std::to_string(sendData.accZ);
	std::cout << strMsg << std::endl;

	INSTANCE_LOGSYSTEM.WriteLog(strMsg);
}

void CSimulationSendThread::ConstructCtrlWashData(SimulationCtrlWashInfo& sendData)
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	auto nowClock = std::chrono::system_clock::now();
	long long lMilliSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(nowClock.time_since_epoch()).count();

	sendData.time = lMilliSeconds;

	sendData.roll = pInstance->GetRoll();
	sendData.pitch = pInstance->GetPitch();
	sendData.yaw = pInstance->GetYaw();
	sendData.offsetX = pInstance->GetOffsetX();
	sendData.offsetY = pInstance->GetOffsetY();
	sendData.offsetZ = pInstance->GetOffsetZ();
	sendData.accX = pInstance->GetAccX();
	sendData.accY = pInstance->GetAccY();
	sendData.accZ = pInstance->GetAccZ();

	// ���Ƹ��� ����ƽ̨��װ�������ȣ��߶Ȳ���
	if (sendData.pitch > 8.0f)
	{
		sendData.pitch = 8.0f;
	}
	else if (sendData.pitch < -8.0f)
	{
		sendData.pitch = -8.0f;
	}
	// ���ƺ�� ����ƽ̨��װ�������ȣ��߶Ȳ���
	if (sendData.roll > 5.0f)
	{
		sendData.roll = 5.0f;
	}
	else if (sendData.roll < -5.0f)
	{
		sendData.roll = -5.0f;
	}

	sendData.ctrlCMD |= E_Cmd_Code_Work;
	sendData.ctrlCMD |= E_Cmd_Code_Wash;

	sendData.SetLow8Bit();
}
