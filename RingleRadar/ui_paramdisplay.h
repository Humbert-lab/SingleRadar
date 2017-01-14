/********************************************************************************
** Form generated from reading UI file 'paramdisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMDISPLAY_H
#define UI_PARAMDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ParamDisplay
{
public:
    QCheckBox *title;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *ParamDisplay)
    {
        if (ParamDisplay->objectName().isEmpty())
            ParamDisplay->setObjectName(QStringLiteral("ParamDisplay"));
        ParamDisplay->resize(240, 239);
        title = new QCheckBox(ParamDisplay);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(50, 60, 71, 16));
        checkBox_2 = new QCheckBox(ParamDisplay);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(50, 90, 71, 16));
        checkBox_3 = new QCheckBox(ParamDisplay);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(50, 120, 71, 16));
        pushButton_ok = new QPushButton(ParamDisplay);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(40, 200, 75, 23));
        pushButton_cancel = new QPushButton(ParamDisplay);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(130, 200, 75, 23));

        retranslateUi(ParamDisplay);

        QMetaObject::connectSlotsByName(ParamDisplay);
    } // setupUi

    void retranslateUi(QDialog *ParamDisplay)
    {
        ParamDisplay->setWindowTitle(QApplication::translate("ParamDisplay", "Dialog", 0));
        title->setText(QApplication::translate("ParamDisplay", "title", 0));
        checkBox_2->setText(QApplication::translate("ParamDisplay", "param1", 0));
        checkBox_3->setText(QApplication::translate("ParamDisplay", "param2", 0));
        pushButton_ok->setText(QApplication::translate("ParamDisplay", "ok", 0));
        pushButton_cancel->setText(QApplication::translate("ParamDisplay", "cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ParamDisplay: public Ui_ParamDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMDISPLAY_H
