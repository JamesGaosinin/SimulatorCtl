#pragma once
#include <iostream>
#include <thread>
#include <mutex>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#elif _LINUX
#include <stdarg.h>
#include <sys/stat.h>
#endif

#ifdef _WIN32
#define ACCESS _access
#define MKDIR(a) _mkdir((a))
#elif _LINUX
#define ACCESS access
#define MKDIR(a) mkdir((a),0755)
#endif

enum E_Log_Type
{
	E_Log_Type_Unkown=0,	// δ֪
	E_Log_Type_File,		// ����ļ�
	E_Log_Type_Console,		// �������̨
};
enum E_Msg_Level
{
	E_Msg_Level_Unkown=0,	// δ֪
	E_Msg_Level_Normal,		// ��ͨ
	E_Msg_Level_Warning,	// ����
	E_Msg_Level_Error,		// ����
	E_Msg_Level_fatal,		// ��������
};

// windows��־ϵͳ
class CLogSystem
{
public:
	static CLogSystem* GetInstance();
	static void Release();

public:
	bool Initalize(E_Log_Type eLogType = E_Log_Type_Console, std::string strPath = "", int nIntervalMin = 5);
	bool WriteLog(const std::string& strContent, E_Msg_Level eMsgLevel = E_Msg_Level_Normal);

private:
	CLogSystem();
	~CLogSystem();
	CLogSystem(const CLogSystem& other);
	CLogSystem& operator=(const CLogSystem& other);

private:
	std::string ConstructMsg(const std::string& strContent, E_Msg_Level eMsgLevel);
	bool WriteFile(std::string& strMsg);
	bool CreatDir(const std::string& strFullFilePath);

	void WriteLogFunc(const std::string& strContent, E_Msg_Level eMsgLevel = E_Msg_Level_Normal);;

private:
	static CLogSystem* m_pInstance;

	E_Log_Type m_eLogType;			// ��־����
	std::string m_strLogFilePath;	// �ļ�·��
	int m_nIntervalMin;				// �ļ����ɼ��ʱ��

	std::mutex m_Mutex;
	std::thread m_WriteThread;
};

#ifndef INSTANCE_LOGSYSTEM
#define INSTANCE_LOGSYSTEM (*CLogSystem::GetInstance())
#endif // !INSTANCE_LOGSYSTEM



