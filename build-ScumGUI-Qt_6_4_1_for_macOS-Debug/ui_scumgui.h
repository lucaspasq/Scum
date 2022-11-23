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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScumGUI
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ScumGUI)
    {
        if (ScumGUI->objectName().isEmpty())
            ScumGUI->setObjectName("ScumGUI");
        ScumGUI->resize(800, 600);
        centralwidget = new QWidget(ScumGUI);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(230, 20, 191, 71));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 270, 100, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(430, 270, 100, 32));
        ScumGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ScumGUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        textBrowser->setHtml(QCoreApplication::translate("ScumGUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt; font-weight:700; text-decoration: underline;\">S C U M</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("ScumGUI", "Play", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ScumGUI", "Rules", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScumGUI: public Ui_ScumGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCUMGUI_H
