#include "SimulatorCtl.h"
#include <QApplication>
#include <QTimer>
#include <QtMath>
#include <QIcon>
#include <QPixmap>
#include <QThread>
#include <QMenu>
#include <QPushButton>
#include <QSystemTrayIcon>
#include "SimulationPlatform.h"
#include "NetWorkManager.h"
#include "LogSystem.h"
#include "EffectsConfig.h"
#include "FileManageThread.h"


extern std::map<RailWayPointKey, RailWayPointNodeForPitch> g_mapSourceConfigForPitch;
extern std::map<RailWayPointKey, RailWayPointNodeForRoll> g_mapSourceConfigForRoll;

CSimulatorCtl::CSimulatorCtl(QWidget *parent)
	: QWidget(parent)
	, m_eSimulationStatus(E_Simulation_Status_Unkown)
	, m_dReachPoint(11000.0)
{
	ui.setupUi(this);

	Init();
}

CSimulatorCtl::~CSimulatorCtl()
{
	
}

void CSimulatorCtl::closeEvent(QCloseEvent *event)
{
	this->hide();
}

void CSimulatorCtl::Slot_Up()
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	float fTemp = pInstance->GetPitch() + 1.0f;
	if (fTemp < 15.001f)
	{
		pInstance->SetPitch(fTemp);
	}
}

void CSimulatorCtl::Slot_Down()
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	float fTemp = pInstance->GetPitch() - 1.0f;
	if (fTemp > -15.001f)
	{
		pInstance->SetPitch(fTemp);
	}
}

void CSimulatorCtl::Slot_Left()
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	float fTemp = pInstance->GetRoll() + 1.0f;
	if (fTemp < 15.001f)
	{
		pInstance->SetRoll(fTemp);
	}
}

void CSimulatorCtl::Slot_Right()
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	float fTemp = pInstance->GetRoll() - 1.0f;
	if (fTemp > -15.001)
	{
		pInstance->SetRoll(fTemp);
	}
}

void CSimulatorCtl::Slot_High()
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	float fTemp = pInstance->GetOffsetY() + 1.0f;
	if (fTemp < 15.001)
	{
		pInstance->SetOffsetY(fTemp);
	}
}

void CSimulatorCtl::Slot_Low()
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	float fTemp = pInstance->GetOffsetY() - 1.0f;
	if (fTemp > -15.001)
	{
		pInstance->SetOffsetY(fTemp);
	}
}

void CSimulatorCtl::Slot_BtnStatusClicked()
{
	if (m_eSimulationStatus == E_Simulation_Status_Unkown)
	{
		if (nullptr != m_pTimerSendData)
		{
			m_pTimerSendData->start();
		}

		CNetWorkManager::GetInstance()->SendOnData();

		m_eSimulationStatus = E_Simulation_Status_On;
		ui.Btn_Status->setText(QStringLiteral("停止"));
	}
	else if (m_eSimulationStatus == E_Simulation_Status_On)
	{
		if (nullptr != m_pTimerSendData)
		{
			m_pTimerSendData->stop();
		}

		// 发送断开数据包
		CNetWorkManager::GetInstance()->SendOffData();

		m_eSimulationStatus = E_Simulation_Status_Off;
		ui.Btn_Status->setText(QStringLiteral("开始"));
	}
	else if (m_eSimulationStatus == E_Simulation_Status_Off)
	{
		if (nullptr != m_pTimerSendData)
		{
			m_pTimerSendData->start();
		}

		CNetWorkManager::GetInstance()->SendOnData();

		m_eSimulationStatus = E_Simulation_Status_On;
		ui.Btn_Status->setText(QStringLiteral("停止"));
	}

	if (nullptr != m_pTimerForMile)
	{
		m_dReachPoint = 11000.0;
		m_pTimerForMile->start();
	}
}

void CSimulatorCtl::Slot_Update()
{
	CSimulationPlatform* pInstance = CSimulationPlatform::GetInstance();
	if (nullptr == pInstance)
	{
		return;
	}

	ui.doubleSpinBox_Pitch->setValue(pInstance->GetPitch());
	ui.doubleSpinBox_Roll->setValue(pInstance->GetRoll());
	ui.doubleSpinBox_Yaw->setValue(pInstance->GetYaw());
	ui.doubleSpinBox_Height->setValue(pInstance->GetOffsetY());

	float fMagneticLenth[6] = { 0 }; 
	pInstance->GetMagneticLenth(fMagneticLenth);

	ui.doubleSpinBox_L1->setValue(fMagneticLenth[0]);
	ui.doubleSpinBox_L2->setValue(fMagneticLenth[1]);
	ui.doubleSpinBox_L3->setValue(fMagneticLenth[2]);
	ui.doubleSpinBox_L4->setValue(fMagneticLenth[3]);
	ui.doubleSpinBox_L5->setValue(fMagneticLenth[4]);
	ui.doubleSpinBox_L6->setValue(fMagneticLenth[5]);

	E_SimulationPlatformStatus eStatus = pInstance->GetStatus();
	if (eStatus == E_SimulationPlatformStatus_Unkown)
	{
		ui.label_Status->setPixmap(QPixmap(":/img/no.png"));
	}
	else if (eStatus == E_SimulationPlatformStatus_Awake)
	{
		ui.label_Status->setPixmap(QPixmap(":/img/ok.png"));
	}
	else if (eStatus == E_SimulationPlatformStatus_Sleep)
	{
		ui.label_Status->setPixmap(QPixmap(":/img/no.png"));
	}
}

void CSimulatorCtl::Slot_SendCtrlData()
{
	CNetWorkManager::GetInstance()->SendCtrlData();
}

void CSimulatorCtl::Slot_MileChanged()
{
	m_dReachPoint += 0.2;

	float fCurMilePoint = CSimulationPlatform::GetInstance()->GetPosition();

	RailWayPointKey sKeyValue;
	/*if (!FindCurRailWayPointNodePitch(fCurMilePoint, sKeyValue))
	{
	return;
	}
	RailWayPointNodeForPitch node = g_mapSourceConfigForPitch[sKeyValue];
	CSimulationPlatform::GetInstance()->SetPitch(node.pitch);*/

	if (!FindCurRailWayPointNodeRoll(fCurMilePoint, sKeyValue))
	{
		return;
	}
	RailWayPointNodeForRoll nodeRoll = g_mapSourceConfigForRoll[sKeyValue];

	float fSpeed = CSimulationPlatform::GetInstance()->GetSpeed();
	if (fSpeed == 0.0f)
	{
		nodeRoll.roll = 0.0f;
	}
	else
	{
		float angle = (atanf((fSpeed * fSpeed / nodeRoll.radius) / 10)) * 180.0 / M_PI;
		float roll = angle * nodeRoll.side;
		E_SimulationFlat_UpDown_Type eType = CSimulationPlatform::GetInstance()->GetUpDownType();
		if (eType == E_SimulationFlat_UpDown_Type_Down)
		{
			roll = -roll;
		}

		float RollRatio = CEffectsConfig::GetInstance()->GetRollRatio();
		nodeRoll.roll = roll * RollRatio;
	}

	CSimulationPlatform::GetInstance()->SetRoll(nodeRoll.roll);
}

void CSimulatorCtl::Initalize()
{
	setWindowIcon(QIcon(":/img/icon.png"));

	connect(ui.SensingWgt, &CSensingWidget::Sig_Up, this, &CSimulatorCtl::Slot_Up);
	connect(ui.SensingWgt, &CSensingWidget::Sig_Down, this, &CSimulatorCtl::Slot_Down);
	connect(ui.SensingWgt, &CSensingWidget::Sig_Left, this, &CSimulatorCtl::Slot_Left);
	connect(ui.SensingWgt, &CSensingWidget::Sig_Right, this, &CSimulatorCtl::Slot_Right);
	connect(ui.SensingWgt, &CSensingWidget::Sig_High, this, &CSimulatorCtl::Slot_High);
	connect(ui.SensingWgt, &CSensingWidget::Sig_Low, this, &CSimulatorCtl::Slot_Low);
	//connect(ui.Btn_Status, &QPushButton::clicked, this, &CSimulatorCtl::Slot_BtnStatusClicked);
	connect(CSimulationPlatform::GetInstance(), &CSimulationPlatform::Sig_DoadStatusChanged, this, &CSimulatorCtl::Slot_BoadStatusChanged);

	if (nullptr == m_pUpdateTimer)
	{
		m_pUpdateTimer = new QTimer(this);
		m_pUpdateTimer->setInterval(200);
		m_pUpdateTimer->setSingleShot(false);
		connect(m_pUpdateTimer, &QTimer::timeout, this, &CSimulatorCtl::Slot_Update);
		m_pUpdateTimer->start();
	}

	if (nullptr == m_pTimerSendData)
	{
		m_pTimerSendData = new QTimer(this);
		m_pTimerSendData->setInterval(100);
		m_pTimerSendData->setSingleShot(false);
		connect(m_pTimerSendData, &QTimer::timeout, this, &CSimulatorCtl::Slot_SendCtrlData);
	}

	if (nullptr == m_pTimerForMile)
	{
		m_pTimerForMile = new QTimer(this);
		m_pTimerForMile->setInterval(10);
		m_pTimerForMile->setSingleShot(false);
		connect(m_pTimerForMile, &QTimer::timeout, this, &CSimulatorCtl::Slot_MileChanged);
		m_pTimerForMile->start();
	}
}

bool CSimulatorCtl::FindCurRailWayPointNodePitch(const double& dMile, RailWayPointKey& sKeyValue)
{
	auto itr = g_mapSourceConfigForPitch.begin();
	for (; itr != g_mapSourceConfigForPitch.end(); ++itr)
	{
		RailWayPointKey sKey = itr->first;
		if (sKey.findRight(dMile))
		{
			sKeyValue = sKey;
			return true;
		}
	}

	return false;
}

bool CSimulatorCtl::FindCurRailWayPointNodeRoll(const double& dMile, RailWayPointKey& sKeyValue)
{
	auto itr = g_mapSourceConfigForRoll.begin();
	for (; itr != g_mapSourceConfigForRoll.end(); ++itr)
	{
		RailWayPointKey sKey = itr->first;
		if (sKey.findRight(dMile))
		{
			sKeyValue = sKey;
			return true;
		}
	}

	return false;
}

void CSimulatorCtl::Slot_BoadStatusChanged(unsigned char cStatus)
{

	E_Simulation_Status eStatus;
	if ((cStatus & E_Boad_Status_Error) == E_Boad_Status_Null)
	{
		if ((cStatus & E_Boad_Status_Up) == E_Boad_Status_Up)
		{
			if ((cStatus & E_Boad_Status_Down) == E_Boad_Status_Null)
			{
				eStatus = E_Simulation_Status_On;
			}
			else
			{
				eStatus = E_Simulation_Status_Off;
			}
		}
		else
		{
			eStatus = E_Simulation_Status_Off;
		}
	}
	else
	{
		eStatus = E_Simulation_Status_Off;
	}

	if (eStatus != m_eSimulationStatus)
	{
		m_eSimulationStatus = eStatus;
		if (m_eSimulationStatus == E_Simulation_Status_Off)
		{
			if (nullptr != m_pTimerSendData)
			{
				m_pTimerSendData->stop();
			}
		}
		else if (m_eSimulationStatus == E_Simulation_Status_On)
		{
			if (nullptr != m_pTimerSendData)
			{
				m_pTimerSendData->start();
			}
		}
	}
}

void CSimulatorCtl::Init()
{
	InitSystemTray();
}

void CSimulatorCtl::InitSystemTray()
{
	if (nullptr == m_pSysTrayIcon)
	{
		m_pSysTrayIcon = new QSystemTrayIcon(this);
	}
	if (nullptr == m_pFileThread)
	{
		m_pFileThread = new CFileManageThread(this);
		QString strDir = QApplication::applicationDirPath() + QString("/log");
		m_pFileThread->SetRootDir(strDir);
		m_pFileThread->start();
	}

	QIcon icon = QIcon(":/img/icon.png");
	m_pSysTrayIcon->setIcon(icon);
	m_pSysTrayIcon->setToolTip(QStringLiteral("平台控制器"));

	QMenu* pMenu = new QMenu;
	QAction* pActionShow = pMenu->addAction(QStringLiteral("显示"));
	QAction* pActionHide = pMenu->addAction(QStringLiteral("隐藏"));
	pActionShow->setVisible(false);
	pActionHide->setVisible(false);
	QAction* pActionQuit = pMenu->addAction(QStringLiteral("退出"));
	m_pSysTrayIcon->setContextMenu(pMenu);
	m_pSysTrayIcon->show();

	connect(pActionQuit, &QAction::triggered, this, &CSimulatorCtl::Slot_AppShutDown);
	connect(pActionHide, &QAction::triggered, [=](){
		this->hide();
	});
	connect(pActionShow, &QAction::triggered, [=](){
		this->show();
	});

	connect(m_pSysTrayIcon, &QSystemTrayIcon::activated,
		[=](QSystemTrayIcon::ActivationReason reason){
		if (reason == QSystemTrayIcon::Trigger)
		{
			//this->show();
		}
	});
}

void CSimulatorCtl::Slot_AppShutDown()
{
	if (nullptr != m_pUpdateTimer)
	{
		if (m_pUpdateTimer->isActive())
		{
			m_pUpdateTimer->stop();
		}
	}

	if (nullptr != m_pTimerSendData)
	{
		if (m_pTimerSendData->isActive())
		{
			m_pTimerSendData->stop();
		}
	}
	QThread::msleep(50);

	CNetWorkManager::GetInstance()->Close();
	qApp->quit();
}
