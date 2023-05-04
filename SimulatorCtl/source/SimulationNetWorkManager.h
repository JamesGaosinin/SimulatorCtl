#pragma once

#include <QObject>

class CSimulationNetWorkManager : public QObject
{
	Q_OBJECT

public:
	CSimulationNetWorkManager(QObject *parent);
	~CSimulationNetWorkManager();

public:
	void Initalize(const QString& strFilePath);
	QString GetAddr();
	unsigned short GetPort();

private:
	QString m_strAddr;
	unsigned short m_usPort;
};
