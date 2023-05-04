#pragma once

#include <QThread>
#include <QHostAddress>
#include "../include/CommonHeader.h"

class QUdpSocket;

class CSimulationSendThread : public QThread
{
	Q_OBJECT

public:
	CSimulationSendThread(QObject *parent = nullptr);
	~CSimulationSendThread();

	void Inintalize(QUdpSocket* pSenderSocket, QHostAddress& host, unsigned short usPort);

protected:
	virtual void run() override;

private:
	// ÐÂÐ­Òé
	void ConstructCtrlWashData(SimulationCtrlWashInfo& sendData);

private:
	QUdpSocket* m_pSenderSocket = nullptr;
	QHostAddress m_HostAddress;
	unsigned short m_usPort;
};
