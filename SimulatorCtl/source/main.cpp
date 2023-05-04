#include "SimulatorCtl.h"
#include <windows.h>
#include <QtMath>
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include "NetWorkManager.h"
#include "SimulationPlatform.h"
#include "LogSystem.h"
#include "excel/BasicExcel.hpp"
#include "EffectsConfig.h"

using namespace std;

void Wchar_tToString(std::string& szDst, wchar_t *wchar);
bool ReadRailWayConfig();

std::map<RailWayPointKey, RailWayPointNodeForPitch> g_mapSourceConfigForPitch;		// �����μ���õ� ������
std::map<RailWayPointKey, RailWayPointNodeForRoll> g_mapSourceConfigForRoll;		// �����μ���õ� �����

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString strLogPath = QCoreApplication::applicationDirPath() + QString("/log/");
	INSTANCE_LOGSYSTEM.Initalize(E_Log_Type_File, strLogPath.toLocal8Bit().data(), 5);
	// ��ȡ������� TODO
	if (!ReadRailWayConfig())
	{
		QMessageBox box;
		box.setWindowTitle(QStringLiteral("��ʾ"));
		box.setText(QStringLiteral("������ݽ���ʧ�ܣ�"));
		box.exec();

		return 0;
	}

	CSimulatorCtl w;
	CSimulationPlatform objEntity;
	CNetWorkManager::GetInstance();
	CEffectsConfig::GetInstance();
	w.Initalize();
	w.show();
	w.hide();

	int nRet = a.exec();
	CNetWorkManager::Release();
	CLogSystem::Release();
	CEffectsConfig::Release();

	return nRet;
}

bool ReadRailWayConfig()
{
	QString strFullFileName = QCoreApplication::applicationDirPath() + QStringLiteral("/config/�Ͼ�4������������.xls");
	QByteArray arr = strFullFileName.toLocal8Bit();
	YExcel::BasicExcel e;
	if (!e.Load(arr.data()))
	{
		cout << "��ȡ����ļ�ʧ�ܣ�" << endl;
		return false;
	}

	// ����
	{
		// �յ� ǧ�ֶ� ���� �߶�
		YExcel::BasicExcelWorksheet* sheet1 = e.GetWorksheet((size_t)0);
		if (sheet1)
		{
			size_t maxRows = sheet1->GetTotalRows();
			size_t maxCols = sheet1->GetTotalCols();
			for (size_t r = 1; r < maxRows; ++r)
			{
				RailWayPointNodeForPitch node;
				RailWayPointKey key;

				YExcel::BasicExcelCell* cell = sheet1->Cell(r, 0);
				if (nullptr != cell)
				{
					node.maxRange = cell->GetDouble();
					key.maxRange = cell->GetDouble();
				}
				cell = sheet1->Cell(r, 1);
				if (nullptr != cell)
				{
					node.rate = cell->GetDouble();
				}
				cell = sheet1->Cell(r, 2);
				if (nullptr != cell)
				{
					node.distance = cell->GetDouble();
					key.distance = cell->GetDouble();
					key.range = key.maxRange - key.distance;
				}
				cell = sheet1->Cell(r, 3);
				if (nullptr != cell)
				{
					node.height = cell->GetDouble();
				}

				// ���㸩����
				double dTemp = (qAsin(node.rate / 1000)) * 180.0 / M_PI;
				if (dTemp > MAX_ANGLE_DEF)
				{
					dTemp = MAX_ANGLE_DEF;
				}
				else if (dTemp < -MAX_ANGLE_DEF)
				{
					dTemp = -MAX_ANGLE_DEF;
				}
				node.pitch = dTemp;
				INSTANCE_LOGSYSTEM.WriteLog(std::string("��㣺") + std::to_string(node.maxRange - node.distance) + std::string("�յ㣺") + std::to_string(node.maxRange) + std::string("���ȣ�") + std::to_string(node.distance) + std::string("\t") + std::string("������") + std::to_string(node.pitch));

				g_mapSourceConfigForPitch[key] = node;
			}
		}
	}

	// ���
	{
		YExcel::BasicExcelWorksheet* sheet2 = e.GetWorksheet((size_t)1);
		if (sheet2)
		{
			size_t maxRows = sheet2->GetTotalRows();
			size_t maxCols = sheet2->GetTotalCols();

			for (size_t r = 1; r < maxRows; ++r)
			{
				int ncolum = 0;
				RailWayPointNodeForRoll node;
				RailWayPointKey key;

				// ����	�յ�	�뾶	����
				YExcel::BasicExcelCell* cell = sheet2->Cell(r, ncolum++);
				if (nullptr != cell)
				{
					node.distance = cell->GetDouble();
					key.distance = cell->GetDouble();
				}
				cell = sheet2->Cell(r, ncolum++);
				if (nullptr != cell)
				{
					node.maxRange = cell->GetDouble();
					key.maxRange = cell->GetDouble();
					key.range = key.maxRange - key.distance;
				}
				cell = sheet2->Cell(r, ncolum++);
				if (nullptr != cell)
				{
					node.radius = cell->GetDouble();
				}
				cell = sheet2->Cell(r, ncolum++);
				if (nullptr != cell)
				{
					std::string strSide = "";
					const wchar_t* cDes = cell->GetWString();
					if (nullptr != cDes)
					{
						Wchar_tToString(strSide, (wchar_t*)cDes);
					}
					if (strSide == ("��"))
					{
						node.side = 1;
					}
					else if (strSide == ("��"))
					{
						node.side = -1;
					}
					else
					{
						node.side = 0;
					}
				}

				// ����������(����ת���ٶ�ʼ��Ϊ40km/h)
				//double fPhysicalSthrenth = 40 * 40 / node.radius;
				double angle = 0.0;
				if (node.side == 0)
				{
					node.roll = 0;
				}
				else
				{
					// TODO ���ݽ��ܵ����ٶȼ��㣬(������������Ȼ�˷�һ��)
					angle = (atanf((40 * 40 / node.radius) / 10)) * 180.0 / M_PI;
					if (angle > MAX_ANGLE_DEF)
					{
						angle = MAX_ANGLE_DEF;
					}
					else if (angle < -MAX_ANGLE_DEF)
					{
						angle = -MAX_ANGLE_DEF;
					}
					node.roll = angle * node.side;
				}

				g_mapSourceConfigForRoll[key] = node;
				INSTANCE_LOGSYSTEM.WriteLog(std::string("��㣺") + std::to_string(node.maxRange - node.distance) + std::string("�յ㣺") + std::to_string(node.maxRange) + std::string("���ȣ�") + std::to_string(node.distance) + std::string("\t") + std::string("�����") + std::to_string(node.roll));
			}
		}
	}

	return true;
}

void Wchar_tToString(std::string& szDst, wchar_t *wchar)
{
	wchar_t * wText = wchar;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);// WideCharToMultiByte������
	char *psText; // psTextΪchar*����ʱ���飬��Ϊ��ֵ��std::string���м����
	psText = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);// WideCharToMultiByte���ٴ�����
	szDst = psText;// std::string��ֵ
	delete[]psText;// psText�����
}
