#pragma once

#include <QtWidgets/QWidget>
#include "ui_SimulatorCtl.h"
#include "../include/CommonHeader.h"

enum E_Simulation_Status
{
	E_Simulation_Status_Unkown=0,
	E_Simulation_Status_On,
	E_Simulation_Status_Off,
};

class QSystemTrayIcon;
class CFileManageThread;

class CSimulatorCtl : public QWidget
{
	Q_OBJECT

public:
	CSimulatorCtl(QWidget *parent = Q_NULLPTR);
	~CSimulatorCtl();
	void Initalize();

protected:
	virtual void closeEvent(QCloseEvent *event) override;

private slots:
	void Slot_Up();
	void Slot_Down();
	void Slot_Left();
	void Slot_Right();

	void Slot_High();
	void Slot_Low();

	void Slot_BoadStatusChanged(unsigned char cStatus);
	void Slot_BtnStatusClicked();

	void Slot_Update();
	void Slot_SendCtrlData();

	void Slot_MileChanged();
	void Slot_AppShutDown();

private:
	void Init();
	void InitSystemTray();
	bool FindCurRailWayPointNodePitch(const double& dMile, RailWayPointKey& sKeyValue);
	bool FindCurRailWayPointNodeRoll(const double& dMile, RailWayPointKey& sKeyValue);

private:
	Ui::CSimulatorCtlClass ui;

	QTimer* m_pUpdateTimer = nullptr;
	QTimer* m_pTimerSendData = nullptr;
	E_Simulation_Status m_eSimulationStatus;
	QTimer* m_pTimerForMile = nullptr;
	double m_dReachPoint = 0.0;
	QTimer* m_pTimerStatusInvalid = nullptr;
	QSystemTrayIcon* m_pSysTrayIcon = nullptr;

	CFileManageThread* m_pFileThread = nullptr;
};
