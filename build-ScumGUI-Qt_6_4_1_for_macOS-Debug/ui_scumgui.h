/********************************************************************************
** Form generated from reading UI file 'scumgui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCUMGUI_H
#define UI_SCUMGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScumGUI
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ScumGUI)
    {
        if (ScumGUI->objectName().isEmpty())
            ScumGUI->setObjectName("ScumGUI");
        ScumGUI->resize(800, 600);
        centralwidget = new QWidget(ScumGUI);
        centralwidget->setObjectName("centralwidget");
        ScumGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ScumGUI);
        menubar->setObjectName("menubar");
        ScumGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(ScumGUI);
        statusbar->setObjectName("statusbar");
        ScumGUI->setStatusBar(statusbar);

        retranslateUi(ScumGUI);

        QMetaObject::connectSlotsByName(ScumGUI);
    } // setupUi

    void retranslateUi(QMainWindow *ScumGUI)
    {
        ScumGUI->setWindowTitle(QCoreApplication::translate("ScumGUI", "ScumGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScumGUI: public Ui_ScumGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCUMGUI_H
