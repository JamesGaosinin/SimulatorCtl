#pragma once

#include <atomic>
#include <QUdpSocket>
#include <QHostAddress>
#include <QThread>
#include <QTimer>
#include "../include/CommonHeader.h"

class CUDPSocketImp : public QUdpSocket
{
	Q_OBJECT

public:
	CUDPSocketImp(QObject *parent = nullptr);
	~CUDPSocketImp();

public:
	void Initalize(QHostAddress& host, unsigned short usPort);
	void Close();

signals:
	void Sig_StartRecv();
	void Sig_SimulationStatus(int nStatus);

private slots:
	void readPendingDatagrams();

private:
	void ParseData();

private:
	std::atomic<bool> m_bRun;
};
