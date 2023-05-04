/********************************************************************************
** Form generated from reading UI file 'SimulatorCtl.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATORCTL_H
#define UI_SIMULATORCTL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SensingWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CSimulatorCtlClass
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLabel *label_Status;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_Status;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_Pitch;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_L1;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_Roll;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_L2;
    QFrame *frame_Yaw;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_Yaw;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_L3;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_Height;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_L4;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_L5;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_L6;
    CSensingWidget *SensingWgt;

    void setupUi(QWidget *CSimulatorCtlClass)
    {
        if (CSimulatorCtlClass->objectName().isEmpty())
            CSimulatorCtlClass->setObjectName(QStringLiteral("CSimulatorCtlClass"));
        CSimulatorCtlClass->resize(551, 728);
        verticalLayout = new QVBoxLayout(CSimulatorCtlClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_4 = new QFrame(CSimulatorCtlClass);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame_4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_11->addWidget(label_11);

        label_Status = new QLabel(frame_4);
        label_Status->setObjectName(QStringLiteral("label_Status"));
        label_Status->setMinimumSize(QSize(32, 32));
        label_Status->setMaximumSize(QSize(32, 32));
        label_Status->setPixmap(QPixmap(QString::fromUtf8(":/img/no.png")));
        label_Status->setScaledContents(true);

        horizontalLayout_11->addWidget(label_Status);

        horizontalSpacer = new QSpacerItem(464, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        Btn_Status = new QPushButton(frame_4);
        Btn_Status->setObjectName(QStringLiteral("Btn_Status"));
        Btn_Status->setMinimumSize(QSize(100, 50));

        horizontalLayout_11->addWidget(Btn_Status);


        verticalLayout->addWidget(frame_4);

        frame_3 = new QFrame(CSimulatorCtlClass);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(frame_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        doubleSpinBox_Pitch = new QDoubleSpinBox(frame);
        doubleSpinBox_Pitch->setObjectName(QStringLiteral("doubleSpinBox_Pitch"));
        doubleSpinBox_Pitch->setMinimum(-15);
        doubleSpinBox_Pitch->setMaximum(15);

        horizontalLayout->addWidget(doubleSpinBox_Pitch);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_6);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(frame_6);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_5);

        doubleSpinBox_L1 = new QDoubleSpinBox(frame_6);
        doubleSpinBox_L1->setObjectName(QStringLiteral("doubleSpinBox_L1"));

        horizontalLayout_5->addWidget(doubleSpinBox_L1);


        gridLayout->addWidget(frame_6, 0, 1, 1, 1);

        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_Roll = new QDoubleSpinBox(frame_2);
        doubleSpinBox_Roll->setObjectName(QStringLiteral("doubleSpinBox_Roll"));
        doubleSpinBox_Roll->setMinimum(-15);
        doubleSpinBox_Roll->setMaximum(15);

        horizontalLayout_2->addWidget(doubleSpinBox_Roll);


        gridLayout->addWidget(frame_2, 1, 0, 1, 1);

        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_7);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(frame_7);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_6);

        doubleSpinBox_L2 = new QDoubleSpinBox(frame_7);
        doubleSpinBox_L2->setObjectName(QStringLiteral("doubleSpinBox_L2"));

        horizontalLayout_6->addWidget(doubleSpinBox_L2);


        gridLayout->addWidget(frame_7, 1, 1, 1, 1);

        frame_Yaw = new QFrame(frame_3);
        frame_Yaw->setObjectName(QStringLiteral("frame_Yaw"));
        frame_Yaw->setFrameShape(QFrame::StyledPanel);
        frame_Yaw->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_Yaw);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame_Yaw);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_3);

        doubleSpinBox_Yaw = new QDoubleSpinBox(frame_Yaw);
        doubleSpinBox_Yaw->setObjectName(QStringLiteral("doubleSpinBox_Yaw"));
        doubleSpinBox_Yaw->setMinimum(-15);
        doubleSpinBox_Yaw->setMaximum(15);

        horizontalLayout_3->addWidget(doubleSpinBox_Yaw);


        gridLayout->addWidget(frame_Yaw, 2, 0, 1, 1);

        frame_8 = new QFrame(frame_3);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_8);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(frame_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(label_7);

        doubleSpinBox_L3 = new QDoubleSpinBox(frame_8);
        doubleSpinBox_L3->setObjectName(QStringLiteral("doubleSpinBox_L3"));

        horizontalLayout_7->addWidget(doubleSpinBox_L3);


        gridLayout->addWidget(frame_8, 2, 1, 1, 1);

        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_4);

        doubleSpinBox_Height = new QDoubleSpinBox(frame_5);
        doubleSpinBox_Height->setObjectName(QStringLiteral("doubleSpinBox_Height"));
        doubleSpinBox_Height->setMinimum(-15);
        doubleSpinBox_Height->setMaximum(15);

        horizontalLayout_4->addWidget(doubleSpinBox_Height);


        gridLayout->addWidget(frame_5, 3, 0, 1, 1);

        frame_9 = new QFrame(frame_3);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_9);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(frame_9);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_8);

        doubleSpinBox_L4 = new QDoubleSpinBox(frame_9);
        doubleSpinBox_L4->setObjectName(QStringLiteral("doubleSpinBox_L4"));

        horizontalLayout_8->addWidget(doubleSpinBox_L4);


        gridLayout->addWidget(frame_9, 3, 1, 1, 1);

        frame_10 = new QFrame(frame_3);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_10);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(frame_10);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(label_9);

        doubleSpinBox_L5 = new QDoubleSpinBox(frame_10);
        doubleSpinBox_L5->setObjectName(QStringLiteral("doubleSpinBox_L5"));

        horizontalLayout_9->addWidget(doubleSpinBox_L5);


        gridLayout->addWidget(frame_10, 4, 1, 1, 1);

        frame_11 = new QFrame(frame_3);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_11);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(frame_11);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(label_10);

        doubleSpinBox_L6 = new QDoubleSpinBox(frame_11);
        doubleSpinBox_L6->setObjectName(QStringLiteral("doubleSpinBox_L6"));

        horizontalLayout_10->addWidget(doubleSpinBox_L6);


        gridLayout->addWidget(frame_11, 5, 1, 1, 1);


        verticalLayout->addWidget(frame_3);

        SensingWgt = new CSensingWidget(CSimulatorCtlClass);
        SensingWgt->setObjectName(QStringLiteral("SensingWgt"));

        verticalLayout->addWidget(SensingWgt);


        retranslateUi(CSimulatorCtlClass);

        QMetaObject::connectSlotsByName(CSimulatorCtlClass);
    } // setupUi

    void retranslateUi(QWidget *CSimulatorCtlClass)
    {
        CSimulatorCtlClass->setWindowTitle(QApplication::translate("CSimulatorCtlClass", "CSimulatorCtl", 0));
        label_11->setText(QApplication::translate("CSimulatorCtlClass", "\345\212\250\346\204\237\345\271\263\345\217\260\347\212\266\346\200\201:", 0));
        label_Status->setText(QString());
        Btn_Status->setText(QApplication::translate("CSimulatorCtlClass", "\345\274\200\345\247\213", 0));
        label->setText(QApplication::translate("CSimulatorCtlClass", "\344\277\257\344\273\260", 0));
        label_5->setText(QApplication::translate("CSimulatorCtlClass", "L1", 0));
        label_2->setText(QApplication::translate("CSimulatorCtlClass", "\346\250\252\346\273\232", 0));
        label_6->setText(QApplication::translate("CSimulatorCtlClass", "L2", 0));
        label_3->setText(QApplication::translate("CSimulatorCtlClass", "\350\210\252\345\220\221", 0));
        label_7->setText(QApplication::translate("CSimulatorCtlClass", "L3", 0));
        label_4->setText(QApplication::translate("CSimulatorCtlClass", "\351\253\230\345\272\246", 0));
        label_8->setText(QApplication::translate("CSimulatorCtlClass", "L4", 0));
        label_9->setText(QApplication::translate("CSimulatorCtlClass", "L5", 0));
        label_10->setText(QApplication::translate("CSimulatorCtlClass", "L6", 0));
    } // retranslateUi

};

namespace Ui {
    class CSimulatorCtlClass: public Ui_CSimulatorCtlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORCTL_H
