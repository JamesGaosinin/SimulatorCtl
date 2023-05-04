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

std::map<RailWayPointKey, RailWayPointNodeForPitch> g_mapSourceConfigForPitch;		// 公里标段计算得到 俯仰角
std::map<RailWayPointKey, RailWayPointNodeForRoll> g_mapSourceConfigForRoll;		// 公里标段计算得到 横滚角

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString strLogPath = QCoreApplication::applicationDirPath() + QString("/log/");
	INSTANCE_LOGSYSTEM.Initalize(E_Log_Type_File, strLogPath.toLocal8Bit().data(), 5);
	// 读取轨道参数 TODO
	if (!ReadRailWayConfig())
	{
		QMessageBox box;
		box.setWindowTitle(QStringLiteral("提示"));
		box.setText(QStringLiteral("轨道数据解析失败！"));
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
	QString strFullFileName = QCoreApplication::applicationDirPath() + QStringLiteral("/config/南京4号线数据整理.xls");
	QByteArray arr = strFullFileName.toLocal8Bit();
	YExcel::BasicExcel e;
	if (!e.Load(arr.data()))
	{
		cout << "读取轨道文件失败！" << endl;
		return false;
	}

	// 俯仰
	{
		// 终点 千分度 距离 高度
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

				// 计算俯仰角
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
				INSTANCE_LOGSYSTEM.WriteLog(std::string("起点：") + std::to_string(node.maxRange - node.distance) + std::string("终点：") + std::to_string(node.maxRange) + std::string("长度：") + std::to_string(node.distance) + std::string("\t") + std::string("俯仰：") + std::to_string(node.pitch));

				g_mapSourceConfigForPitch[key] = node;
			}
		}
	}

	// 横滚
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

				// 弧长	终点	半径	方向
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
					if (strSide == ("左"))
					{
						node.side = 1;
					}
					else if (strSide == ("右"))
					{
						node.side = -1;
					}
					else
					{
						node.side = 0;
					}
				}

				// 计算向心力(假设转弯速度始终为40km/h)
				//double fPhysicalSthrenth = 40 * 40 / node.radius;
				double angle = 0.0;
				if (node.side == 0)
				{
					node.roll = 0;
				}
				else
				{
					// TODO 根据接受到的速度计算，(向心力人体自然克服一半)
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
				INSTANCE_LOGSYSTEM.WriteLog(std::string("起点：") + std::to_string(node.maxRange - node.distance) + std::string("终点：") + std::to_string(node.maxRange) + std::string("长度：") + std::to_string(node.distance) + std::string("\t") + std::string("横滚：") + std::to_string(node.roll));
			}
		}
	}

	return true;
}

void Wchar_tToString(std::string& szDst, wchar_t *wchar)
{
	wchar_t * wText = wchar;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);// WideCharToMultiByte的运用
	char *psText; // psText为char*的临时数组，作为赋值给std::string的中间变量
	psText = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);// WideCharToMultiByte的再次运用
	szDst = psText;// std::string赋值
	delete[]psText;// psText的清除
}
