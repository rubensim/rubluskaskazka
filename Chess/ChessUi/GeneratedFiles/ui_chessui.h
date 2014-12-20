/********************************************************************************
** Form generated from reading UI file 'chessui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSUI_H
#define UI_CHESSUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessUiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChessUiClass)
    {
        if (ChessUiClass->objectName().isEmpty())
            ChessUiClass->setObjectName(QStringLiteral("ChessUiClass"));
        ChessUiClass->resize(600, 400);
        menuBar = new QMenuBar(ChessUiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ChessUiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChessUiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChessUiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ChessUiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ChessUiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ChessUiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChessUiClass->setStatusBar(statusBar);

        retranslateUi(ChessUiClass);

        QMetaObject::connectSlotsByName(ChessUiClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChessUiClass)
    {
        ChessUiClass->setWindowTitle(QApplication::translate("ChessUiClass", "ChessUi", 0));
    } // retranslateUi

};

namespace Ui {
    class ChessUiClass: public Ui_ChessUiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSUI_H
