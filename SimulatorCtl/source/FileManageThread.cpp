#include "FileManageThread.h"
#include <QDir>
#include <QDebug>
#include <QDateTime>

const int g_nHistoryFileExistDay = 2;

CFileManageThread::CFileManageThread(QObject *parent)
	: QThread(parent)
{
}

CFileManageThread::~CFileManageThread()
{
}

void CFileManageThread::SetRootDir(const QString& strRootDir)
{
	m_strRootDir = strRootDir;
}

void CFileManageThread::run()
{
	if (m_strRootDir.isEmpty())
	{
		return;
	}

	if (!DeleteOverdueFiles(m_strRootDir))
	{
		qDebug() << QStringLiteral("删除过期文件失败!");
	}
}

bool CFileManageThread::DeleteOverdueFiles(const QString& strDir)
{
	QDir dir(strDir);

	QFileInfoList lstFileInfo = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);
	for each (const QFileInfo& oFileInfo in lstFileInfo)
	{
		QString strFileInfo = oFileInfo.absoluteFilePath();
		if (oFileInfo.isDir())
		{
			DeleteOverdueFiles(strFileInfo);
		}

		else if (oFileInfo.isFile())
		{
			QDateTime dateTime = oFileInfo.lastModified();
			QDateTime curDateTime = QDateTime::currentDateTime();
			long long lDeltaSecond = dateTime.secsTo(curDateTime);
			int nDeltaDay = lDeltaSecond / 3600 / 24;
			if (nDeltaDay > g_nHistoryFileExistDay)
			{
				if (!QFile::remove(strFileInfo))
				{
					qDebug() << QStringLiteral("%1-文件删除失败!").arg(strFileInfo);
					return false;
				}
			}
		}
	}
	lstFileInfo = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);
	if (strDir != m_strRootDir && lstFileInfo.empty())
	{
		dir.rmdir(strDir);
	}

	return true;
}
