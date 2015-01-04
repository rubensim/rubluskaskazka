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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessUiClass
{
public:
    QAction *actionNew_Game_2;
    QAction *actionExit;
    QAction *actionSettings;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QScrollArea *steps_Box;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *your_Steps;
    QGroupBox *opponent_Steps;
    QMenuBar *menuBar;
    QMenu *menuMEnu;
    QMenu *menuAbout;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChessUiClass)
    {
        if (ChessUiClass->objectName().isEmpty())
            ChessUiClass->setObjectName(QStringLiteral("ChessUiClass"));
        ChessUiClass->resize(1005, 670);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChessUiClass->sizePolicy().hasHeightForWidth());
        ChessUiClass->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ChessUi/Resources/chess-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChessUiClass->setWindowIcon(icon);
        ChessUiClass->setIconSize(QSize(64, 64));
        actionNew_Game_2 = new QAction(ChessUiClass);
        actionNew_Game_2->setObjectName(QStringLiteral("actionNew_Game_2"));
        actionNew_Game_2->setIcon(icon);
        actionExit = new QAction(ChessUiClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ChessUi/Resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionSettings = new QAction(ChessUiClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ChessUi/Resources/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon2);
        centralWidget = new QWidget(ChessUiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(60, 40, 515, 515));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(515, 515));
        graphicsView->setMaximumSize(QSize(515, 515));
        graphicsView->setMouseTracking(false);
        graphicsView->setFrameShape(QFrame::Box);
        graphicsView->setFrameShadow(QFrame::Raised);
        graphicsView->setInteractive(true);
        steps_Box = new QScrollArea(centralWidget);
        steps_Box->setObjectName(QStringLiteral("steps_Box"));
        steps_Box->setGeometry(QRect(640, 280, 251, 271));
        steps_Box->setMaximumSize(QSize(251, 271));
        steps_Box->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 249, 269));
        your_Steps = new QGroupBox(scrollAreaWidgetContents);
        your_Steps->setObjectName(QStringLiteral("your_Steps"));
        your_Steps->setGeometry(QRect(10, 0, 101, 311));
        sizePolicy1.setHeightForWidth(your_Steps->sizePolicy().hasHeightForWidth());
        your_Steps->setSizePolicy(sizePolicy1);
        your_Steps->setMinimumSize(QSize(101, 261));
        opponent_Steps = new QGroupBox(scrollAreaWidgetContents);
        opponent_Steps->setObjectName(QStringLiteral("opponent_Steps"));
        opponent_Steps->setGeometry(QRect(140, 0, 101, 331));
        steps_Box->setWidget(scrollAreaWidgetContents);
        ChessUiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChessUiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1005, 21));
        menuMEnu = new QMenu(menuBar);
        menuMEnu->setObjectName(QStringLiteral("menuMEnu"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        ChessUiClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ChessUiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChessUiClass->setStatusBar(statusBar);

        menuBar->addAction(menuMEnu->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMEnu->addAction(actionNew_Game_2);
        menuMEnu->addAction(actionSettings);
        menuMEnu->addAction(actionExit);

        retranslateUi(ChessUiClass);

        QMetaObject::connectSlotsByName(ChessUiClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChessUiClass)
    {
        ChessUiClass->setWindowTitle(QApplication::translate("ChessUiClass", "Chess", 0));
        actionNew_Game_2->setText(QApplication::translate("ChessUiClass", "New Game", 0));
        actionNew_Game_2->setShortcut(QApplication::translate("ChessUiClass", "Ctrl+N", 0));
        actionExit->setText(QApplication::translate("ChessUiClass", "Exit", 0));
        actionSettings->setText(QApplication::translate("ChessUiClass", "Settings", 0));
        your_Steps->setTitle(QApplication::translate("ChessUiClass", "White(You)", 0));
        opponent_Steps->setTitle(QApplication::translate("ChessUiClass", "Black(Opponent)", 0));
        menuMEnu->setTitle(QApplication::translate("ChessUiClass", "Menu", 0));
        menuAbout->setTitle(QApplication::translate("ChessUiClass", "About", 0));
        menuHelp->setTitle(QApplication::translate("ChessUiClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class ChessUiClass: public Ui_ChessUiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSUI_H
