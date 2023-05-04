#pragma once

#include <QThread>

class CFileManageThread : public QThread
{
	Q_OBJECT

public:
	CFileManageThread(QObject *parent);
	~CFileManageThread();
	void SetRootDir(const QString& strRootDir);

protected:
	virtual void run() override;

private:
	bool DeleteOverdueFiles(const QString& strDir);

private:
	QString m_strRootDir;
};
