#define  _CRT_SECURE_NO_WARNINGS
#include "LogSystem.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <thread>

using namespace std;

CLogSystem* CLogSystem::m_pInstance = nullptr;

CLogSystem* CLogSystem::GetInstance()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CLogSystem;
	}

	return m_pInstance;
}

void CLogSystem::Release()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

bool CLogSystem::Initalize(E_Log_Type eLogType /*= E_Log_Type_Console*/, std::string strPath /*= ""*/, int nIntervalMin /*= 5*/)
{
	m_eLogType = eLogType;
	m_strLogFilePath = strPath;
	m_nIntervalMin = nIntervalMin;
	bool bRet = true;

	if (eLogType == E_Log_Type_File)
	{
		return CreatDir(strPath);
	}

	return bRet;
}

bool CLogSystem::WriteLog(const string& strContent, E_Msg_Level eMsgLevel /*= E_Msg_Level_Normal*/)
{
	m_Mutex.lock();
	m_WriteThread = std::thread(&CLogSystem::WriteLogFunc, this, strContent, eMsgLevel);
	m_WriteThread.join();
	m_Mutex.unlock();
	return true;
}

CLogSystem::CLogSystem()
	: m_eLogType(E_Log_Type_Console)
{
}

CLogSystem::CLogSystem(const CLogSystem& other)
{
}

CLogSystem& CLogSystem::operator=(const CLogSystem& other)
{
	return *this;
}

CLogSystem::~CLogSystem()
{
}

string CLogSystem::ConstructMsg(const std::string& strContent, E_Msg_Level eMsgLevel)
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	long long lMillSeconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	time_t tt = std::chrono::system_clock::to_time_t(now);
	struct tm* tmNow = localtime(&tt);
	char date[32] = { 0 };
	sprintf(date, "%d-%02d-%02d %02d:%02d:%02d.%03d", (int)tmNow->tm_year + 1900, (int)tmNow->tm_mon + 1, (int)tmNow->tm_mday, (int)tmNow->tm_hour, (int)tmNow->tm_min, (int)tmNow->tm_sec, (int)(lMillSeconds%1000));
	std::string timeNow(date);
	string strMsg = timeNow + string("\t");

	switch (eMsgLevel)
	{
	case E_Msg_Level_Unkown:
	{
		strMsg += "未知\t";
	}break;

	case E_Msg_Level_Normal:
	{
		strMsg += "提示\t";
	}break;

	case E_Msg_Level_Warning:
	{
		strMsg += "警告\t";
	}break;

	case E_Msg_Level_Error:
	{
		strMsg += "错误\t";
	}break;

	case E_Msg_Level_fatal:
	{
		strMsg += "致命错误\t";
	}break;

	default:
		break;
	}
	strMsg += strContent + string("\r\n");

	return strMsg;
}

bool CLogSystem::WriteFile(std::string& strMsg)
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	time_t tt = std::chrono::system_clock::to_time_t(now);
	tt /= m_nIntervalMin * 60;
	tt *= m_nIntervalMin * 60;
	struct tm* tmNow = localtime(&tt);
	char date[20] = { 0 };
	sprintf(date, "%d-%02d-%02d %02d-%02d-%02d", (int)tmNow->tm_year + 1900, (int)tmNow->tm_mon + 1, (int)tmNow->tm_mday, (int)tmNow->tm_hour, (int)tmNow->tm_min, (int)tmNow->tm_sec);
	std::string timeNow(date);
	string strFileName = timeNow;
	string strFullFilePath = m_strLogFilePath + strFileName + ".txt";

	ofstream fout;
	fout.open(strFullFilePath.c_str(), ios::out | ios::app | ios::binary);
	fout.write(strMsg.c_str(), strMsg.length());
	fout.close();

	return true;
}


bool CLogSystem::CreatDir(const string& strFullFilePath)
{
	if (strFullFilePath.size() > 1024)
	{
		return false;
	}

	char *pszDir = new char[1024];
	strcpy(pszDir, strFullFilePath.c_str());

	int i = 0;
	int iRet;
	int iLen = strlen(pszDir);
	//在末尾加/
	if (pszDir[iLen - 1] != '\\' && pszDir[iLen - 1] != '/')
	{
		pszDir[iLen] = '/';
		pszDir[iLen + 1] = '\0';
	}

	// 创建目录
	for (i = 0; i < iLen; i++)
	{
		if (pszDir[i] == '\\' || pszDir[i] == '/')
		{
			pszDir[i] = '\0';

			//如果不存在,创建
			iRet = ACCESS(pszDir, 0);
			if (iRet != 0)
			{
				iRet = MKDIR(pszDir);
				if (iRet != 0)
				{
					return false;
				}
			}
			//支持linux,将所有\换成/
			pszDir[i] = '/';
		}
	}

	delete pszDir;
	pszDir = nullptr;

	return true;
}

void CLogSystem::WriteLogFunc(const std::string& strContent, E_Msg_Level eMsgLevel /*= E_Msg_Level_Normal*/)
{
	string strMsg = ConstructMsg(strContent, eMsgLevel);

	switch (m_eLogType)
	{
	case E_Log_Type_Unkown:
		break;
	case E_Log_Type_File:
	{
		WriteFile(strMsg);
	}break;

	case E_Log_Type_Console:
	{
		std::cout << strMsg.c_str();
	}break;

	default:
		break;
	}
}
