#include "EffectsConfig.h"
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QCoreApplication>

CEffectsConfig* CEffectsConfig::m_pInstance = nullptr;

CEffectsConfig::CEffectsConfig()
{
	Init();
}

CEffectsConfig::~CEffectsConfig()
{
}

CEffectsConfig* CEffectsConfig::GetInstance()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CEffectsConfig;
	}
	return m_pInstance;
}

void CEffectsConfig::Release()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

bool CEffectsConfig::Init()
{
	QString strFilePath = QCoreApplication::applicationDirPath();
	strFilePath += QString("/config/SimulationEffectsConfig.xml");
	QFile file(strFilePath);
	if (!file.exists())
	{
		return false;
	}
	if (!file.open(QIODevice::ReadOnly))
	{
		return false;
	}
	QDomDocument doc;
	if (!doc.setContent(&file))
	{
		return false;
	}
	QDomElement rootEle = doc.documentElement();
	if (rootEle.isNull())
	{
		return false;
	}
	QDomElement shockEle = rootEle.firstChildElement("ShockRatio");
	if (shockEle.isNull())
	{
		return false;
	}
	m_fShockRatio = shockEle.attribute("value").toDouble();
	if (m_fShockRatio > 1.0f)
	{
		m_fShockRatio = 1.0f;
	}
	else if (m_fShockRatio < 0.0f)
	{
		m_fShockRatio = 0.0f;
	}
	QDomElement swingShockEle = rootEle.firstChildElement("SwingShockRatio");
	if (swingShockEle.isNull())
	{
		return false;
	}
	m_fSwingShockRatio = swingShockEle.attribute("value").toDouble();
	if (m_fSwingShockRatio > 1.0f)
	{
		m_fSwingShockRatio = 1.0f;
	}
	else if (m_fSwingShockRatio < 0.0f)
	{
		m_fSwingShockRatio = 0.0f;
	}
	
	QDomElement rollEle = rootEle.firstChildElement("RollRatio");
	if (rollEle.isNull())
	{
		return false;
	}
	m_fRollRatio = rollEle.attribute("value").toDouble();
	if (m_fRollRatio > 1.0f)
	{
		m_fRollRatio = 1.0f;
	}
	else if (m_fRollRatio < 0.0f)
	{
		m_fRollRatio = 0.0f;
	}

	QDomElement yawMultipleEle = rootEle.firstChildElement("YawMultiple");
	if (rollEle.isNull())
	{
		return false;
	}
	m_nYawMultiple = yawMultipleEle.attribute("value").toInt();
	if (m_nYawMultiple > 100)
	{
		m_nYawMultiple = 100;
	}
	else if (m_nYawMultiple < 10)
	{
		m_nYawMultiple = 10;
	}

	file.close();
	return true;
}

float CEffectsConfig::GetShockRatio()
{
	return m_fShockRatio;
}

float CEffectsConfig::GetRollRatio()
{
	return m_fRollRatio;
}

int CEffectsConfig::GetYawMultiple()
{
	return m_nYawMultiple;
}

float CEffectsConfig::GetSwingShockRatio()
{
	return m_fSwingShockRatio;
}
