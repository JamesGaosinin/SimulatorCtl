#include "UDPSocketImp.h"

#include <QCoreApplication>
#include <QUdpSocket>
#include "../include/CommonHeader.h"
#include "SimulationPlatform.h"
#include "LogSystem.h"

CUDPSocketImp::CUDPSocketImp(QObject *parent)
	: QUdpSocket(parent)
	, m_bRun(true)
{
}

CUDPSocketImp::~CUDPSocketImp()
{
}

void CUDPSocketImp::readPendingDatagrams()
{

	while (m_bRun._My_val)
	{
		ParseData();
	}
}

void CUDPSocketImp::ParseData()
{
	char buffer[32] = { 0 };
	int nSize = readDatagram(buffer, 32);
	if (-1 == nSize)
	{
		return;
	}

	FrameHead sFrameHead;
	memcpy(&sFrameHead, buffer, sizeof(sFrameHead));

	// ������
	if (sFrameHead.frameHead1 == 0xa0 && sFrameHead.frameHead2 == 0x53)
	{
		HeartBeatData sHeartBeatData;
		memcpy(&sHeartBeatData, buffer, sizeof(sHeartBeatData));

		emit Sig_SimulationStatus(E_SimulationPlatformStatus_Awake);
	}
	else if (sFrameHead.frameHead1 == 0xfb && sFrameHead.frameHead2 == 0xfd)
	{
		SimulatorData sSimulatorData;
		memcpy(&sSimulatorData, buffer, sizeof(sSimulatorData));

		// У��
#if 1
		unsigned char cTemp = sSimulatorData.GetSumLow8Bit();
		if (sSimulatorData.frameTail != cTemp)
		{
			return;
		}
#endif
		// ����ģ��ƽ̨�������
		CSimulationPlatform* pPlat = CSimulationPlatform::GetInstance();
		if (nullptr != pPlat)
		{
			pPlat->SetMagneticLenth(sSimulatorData.magneticLenth);
		}
		
		std::string strMsg = std::string("����--")
			+ std::string("\tL1��") + std::to_string(sSimulatorData.magneticLenth[0])
			+ std::string("\tL2��") + std::to_string(sSimulatorData.magneticLenth[1])
			+ std::string("\tL3��") + std::to_string(sSimulatorData.magneticLenth[2])
			+ std::string("\tL4��") + std::to_string(sSimulatorData.magneticLenth[3])
			+ std::string("\tL5��") + std::to_string(sSimulatorData.magneticLenth[4])
			+ std::string("\tL6��") + std::to_string(sSimulatorData.magneticLenth[5]);
		INSTANCE_LOGSYSTEM.WriteLog(strMsg);
	}
}

void CUDPSocketImp::Initalize(QHostAddress& host, unsigned short usPort)
{
	if (!bind(QHostAddress::Any, usPort))
	{
		return;
	}

	connect(this, SIGNAL(Sig_StartRecv()), this, SLOT(readPendingDatagrams()));
}

void CUDPSocketImp::Close()
{
	m_bRun._My_val = false;
}
