#include "SimulationNetWorkManager.h"
#include <QFile>
#include <QDomDocument>

CSimulationNetWorkManager::CSimulationNetWorkManager(QObject *parent)
	: QObject(parent)
{
}

CSimulationNetWorkManager::~CSimulationNetWorkManager()
{
}

void CSimulationNetWorkManager::Initalize(const QString& strFilePath)
{
	QFile file(strFilePath);
	QDomDocument doc;
	if (!file.open(QIODevice::ReadOnly))
	{
		return;
	}

	if (!doc.setContent(&file)) 
	{
		file.close();
		return;
	}
	file.close();

	QDomElement rootElem = doc.documentElement();
	if (rootElem.isNull())
	{
		return;
	}

	QDomElement ipElem = rootElem.firstChildElement("IP");
	if (ipElem.isNull())
	{
		return;
	}

	QDomElement portElem = rootElem.firstChildElement("PORT");
	if (portElem.isNull())
	{
		return;
	}
	
	m_strAddr = ipElem.attribute("value");
	m_usPort = portElem.attribute("value").toUShort();
}

QString CSimulationNetWorkManager::GetAddr()
{
	return m_strAddr;
}

unsigned short CSimulationNetWorkManager::GetPort()
{
	return m_usPort;
}
