/********************************************************************************
** Form generated from reading UI file 'SensingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSINGWIDGET_H
#define UI_SENSINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSensingWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *Btn_Up;
    QPushButton *Btn_Left;
    QPushButton *Btn_Down;
    QPushButton *Btn_Right;
    QToolButton *Btn_High;
    QToolButton *Btn_Low;

    void setupUi(QWidget *CSensingWidget)
    {
        if (CSensingWidget->objectName().isEmpty())
            CSensingWidget->setObjectName(QStringLiteral("CSensingWidget"));
        CSensingWidget->resize(405, 352);
        gridLayout = new QGridLayout(CSensingWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Btn_Up = new QPushButton(CSensingWidget);
        Btn_Up->setObjectName(QStringLiteral("Btn_Up"));
        Btn_Up->setMinimumSize(QSize(100, 100));
        Btn_Up->setMaximumSize(QSize(100, 100));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Up->setIcon(icon);
        Btn_Up->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Btn_Up, 0, 1, 1, 1);

        Btn_Left = new QPushButton(CSensingWidget);
        Btn_Left->setObjectName(QStringLiteral("Btn_Left"));
        Btn_Left->setMinimumSize(QSize(100, 100));
        Btn_Left->setMaximumSize(QSize(100, 100));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Left->setIcon(icon1);
        Btn_Left->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Btn_Left, 1, 0, 1, 1);

        Btn_Down = new QPushButton(CSensingWidget);
        Btn_Down->setObjectName(QStringLiteral("Btn_Down"));
        Btn_Down->setMinimumSize(QSize(100, 100));
        Btn_Down->setMaximumSize(QSize(100, 100));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Down->setIcon(icon2);
        Btn_Down->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Btn_Down, 2, 1, 1, 1);

        Btn_Right = new QPushButton(CSensingWidget);
        Btn_Right->setObjectName(QStringLiteral("Btn_Right"));
        Btn_Right->setMinimumSize(QSize(100, 100));
        Btn_Right->setMaximumSize(QSize(100, 100));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Right->setIcon(icon3);
        Btn_Right->setIconSize(QSize(100, 100));

        gridLayout->addWidget(Btn_Right, 1, 2, 1, 1);

        Btn_High = new QToolButton(CSensingWidget);
        Btn_High->setObjectName(QStringLiteral("Btn_High"));
        Btn_High->setMinimumSize(QSize(100, 100));
        QFont font;
        font.setPointSize(20);
        Btn_High->setFont(font);

        gridLayout->addWidget(Btn_High, 0, 3, 1, 1);

        Btn_Low = new QToolButton(CSensingWidget);
        Btn_Low->setObjectName(QStringLiteral("Btn_Low"));
        Btn_Low->setMinimumSize(QSize(100, 100));
        Btn_Low->setFont(font);

        gridLayout->addWidget(Btn_Low, 2, 3, 1, 1);


        retranslateUi(CSensingWidget);

        QMetaObject::connectSlotsByName(CSensingWidget);
    } // setupUi

    void retranslateUi(QWidget *CSensingWidget)
    {
        CSensingWidget->setWindowTitle(QApplication::translate("CSensingWidget", "CSensingWidget", 0));
        Btn_Up->setText(QString());
        Btn_Left->setText(QString());
        Btn_Down->setText(QString());
        Btn_Right->setText(QString());
        Btn_High->setText(QApplication::translate("CSensingWidget", "\344\270\212\345\215\207", 0));
        Btn_Low->setText(QApplication::translate("CSensingWidget", "\344\270\213\351\231\215", 0));
    } // retranslateUi

};

namespace Ui {
    class CSensingWidget: public Ui_CSensingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSINGWIDGET_H
