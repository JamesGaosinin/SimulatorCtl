#pragma once

#include <QWidget>
namespace Ui { class CSensingWidget; };

class CSensingWidget : public QWidget
{
	Q_OBJECT

public:
	CSensingWidget(QWidget *parent = Q_NULLPTR);
	~CSensingWidget();

signals:
	void Sig_Up();
	void Sig_Down();
	void Sig_Left();
	void Sig_Right();
	void Sig_High();
	void Sig_Low();

private slots:
	void Slot_BtnClicked();

private:
	void Init();

private:
	Ui::CSensingWidget *ui;
};
