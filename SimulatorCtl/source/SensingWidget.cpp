#include "SensingWidget.h"
#include "ui_SensingWidget.h"

CSensingWidget::CSensingWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::CSensingWidget();
	ui->setupUi(this);
	Init();
}

CSensingWidget::~CSensingWidget()
{
	delete ui;
}

void CSensingWidget::Slot_BtnClicked()
{
	QObject* pObj = sender();
	if (pObj == ui->Btn_Up)
	{
		emit Sig_Up();
	}
	else if (pObj == ui->Btn_Down)
	{
		emit Sig_Down();
	}
	else if (pObj == ui->Btn_Left)
	{
		emit Sig_Left();
	}
	else if (pObj == ui->Btn_Right)
	{
		emit Sig_Right();
	}
	else if (pObj == ui->Btn_High)
	{
		emit Sig_High();
	}
	else if (pObj == ui->Btn_Low)
	{
		emit Sig_Low();
	}
}

void CSensingWidget::Init()
{
	connect(ui->Btn_Up, &QPushButton::clicked, this, &CSensingWidget::Slot_BtnClicked);
	connect(ui->Btn_Down, &QPushButton::clicked, this, &CSensingWidget::Slot_BtnClicked);
	connect(ui->Btn_Left, &QPushButton::clicked, this, &CSensingWidget::Slot_BtnClicked);
	connect(ui->Btn_Right, &QPushButton::clicked, this, &CSensingWidget::Slot_BtnClicked);
	connect(ui->Btn_High, &QPushButton::clicked, this, &CSensingWidget::Slot_BtnClicked);
	connect(ui->Btn_Low, &QPushButton::clicked, this, &CSensingWidget::Slot_BtnClicked);
}
