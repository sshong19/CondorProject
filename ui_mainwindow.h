/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *FourDisplaysLayout;
    QHBoxLayout *ColorCameraLayout;
    QLabel *ColorCamera_Img;
    QGroupBox *ColorCamera_StatsGraph;
    QWidget *layoutWidget_8;
    QVBoxLayout *ColorCamera_StatLabels;
    QLabel *ColorCamera_FPS;
    QLabel *ColorCamera_EXP;
    QLabel *ColorCamera_WL;
    QHBoxLayout *NIR1Layout;
    QLabel *NIR1_Img;
    QGroupBox *NIR1_StatsGraph;
    QWidget *layoutWidget_3;
    QVBoxLayout *NIR1_StatLabels;
    QLabel *NIR1_FPS;
    QLabel *NIR1_EXP;
    QLabel *NIR1_WL;
    QHBoxLayout *NIR2_Layout;
    QLabel *NIR2_Img;
    QGroupBox *NIR2_StatsGraph;
    QWidget *layoutWidget_5;
    QVBoxLayout *NIR2_StatLabels;
    QLabel *NIR2_FPS;
    QLabel *NIR2_EXP;
    QLabel *NIR2_WL;
    QHBoxLayout *LiveStatsLayout;
    QLabel *Merge_Img;
    QGroupBox *LiveStatsandGraph;
    QWidget *layoutWidget_7;
    QVBoxLayout *LiveStats_StatLabels;
    QLabel *LiveStats_FPS;
    QLabel *LiveStats_EXP;
    QLabel *LiveStats_WL;
    QWidget *layoutWidget1;
    QGridLayout *VideoControlButtons;
    QPushButton *liveButton;
    QPushButton *snapButton;
    QPushButton *stopButton;
    QPushButton *recordButton;
    QPushButton *initiateButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1444, 741);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 30, 1704, 972));
        FourDisplaysLayout = new QGridLayout(layoutWidget);
        FourDisplaysLayout->setSpacing(6);
        FourDisplaysLayout->setContentsMargins(11, 11, 11, 11);
        FourDisplaysLayout->setObjectName(QStringLiteral("FourDisplaysLayout"));
        FourDisplaysLayout->setContentsMargins(0, 0, 0, 0);
        ColorCameraLayout = new QHBoxLayout();
        ColorCameraLayout->setSpacing(6);
        ColorCameraLayout->setObjectName(QStringLiteral("ColorCameraLayout"));
        ColorCamera_Img = new QLabel(layoutWidget);
        ColorCamera_Img->setObjectName(QStringLiteral("ColorCamera_Img"));
        ColorCamera_Img->setMinimumSize(QSize(640, 480));

        ColorCameraLayout->addWidget(ColorCamera_Img);

        ColorCamera_StatsGraph = new QGroupBox(layoutWidget);
        ColorCamera_StatsGraph->setObjectName(QStringLiteral("ColorCamera_StatsGraph"));
        ColorCamera_StatsGraph->setMinimumSize(QSize(200, 480));
        layoutWidget_8 = new QWidget(ColorCamera_StatsGraph);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 40, 97, 101));
        ColorCamera_StatLabels = new QVBoxLayout(layoutWidget_8);
        ColorCamera_StatLabels->setSpacing(6);
        ColorCamera_StatLabels->setContentsMargins(11, 11, 11, 11);
        ColorCamera_StatLabels->setObjectName(QStringLiteral("ColorCamera_StatLabels"));
        ColorCamera_StatLabels->setContentsMargins(0, 0, 0, 0);
        ColorCamera_FPS = new QLabel(layoutWidget_8);
        ColorCamera_FPS->setObjectName(QStringLiteral("ColorCamera_FPS"));
        ColorCamera_FPS->setMinimumSize(QSize(0, 18));

        ColorCamera_StatLabels->addWidget(ColorCamera_FPS);

        ColorCamera_EXP = new QLabel(layoutWidget_8);
        ColorCamera_EXP->setObjectName(QStringLiteral("ColorCamera_EXP"));
        ColorCamera_EXP->setMinimumSize(QSize(0, 18));

        ColorCamera_StatLabels->addWidget(ColorCamera_EXP);

        ColorCamera_WL = new QLabel(layoutWidget_8);
        ColorCamera_WL->setObjectName(QStringLiteral("ColorCamera_WL"));
        ColorCamera_WL->setMinimumSize(QSize(0, 18));

        ColorCamera_StatLabels->addWidget(ColorCamera_WL);


        ColorCameraLayout->addWidget(ColorCamera_StatsGraph);


        FourDisplaysLayout->addLayout(ColorCameraLayout, 0, 0, 1, 1);

        NIR1Layout = new QHBoxLayout();
        NIR1Layout->setSpacing(6);
        NIR1Layout->setObjectName(QStringLiteral("NIR1Layout"));
        NIR1_Img = new QLabel(layoutWidget);
        NIR1_Img->setObjectName(QStringLiteral("NIR1_Img"));
        NIR1_Img->setMinimumSize(QSize(640, 480));

        NIR1Layout->addWidget(NIR1_Img);

        NIR1_StatsGraph = new QGroupBox(layoutWidget);
        NIR1_StatsGraph->setObjectName(QStringLiteral("NIR1_StatsGraph"));
        NIR1_StatsGraph->setMinimumSize(QSize(200, 480));
        layoutWidget_3 = new QWidget(NIR1_StatsGraph);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 40, 97, 101));
        NIR1_StatLabels = new QVBoxLayout(layoutWidget_3);
        NIR1_StatLabels->setSpacing(6);
        NIR1_StatLabels->setContentsMargins(11, 11, 11, 11);
        NIR1_StatLabels->setObjectName(QStringLiteral("NIR1_StatLabels"));
        NIR1_StatLabels->setContentsMargins(0, 0, 0, 0);
        NIR1_FPS = new QLabel(layoutWidget_3);
        NIR1_FPS->setObjectName(QStringLiteral("NIR1_FPS"));
        NIR1_FPS->setMinimumSize(QSize(0, 18));

        NIR1_StatLabels->addWidget(NIR1_FPS);

        NIR1_EXP = new QLabel(layoutWidget_3);
        NIR1_EXP->setObjectName(QStringLiteral("NIR1_EXP"));
        NIR1_EXP->setMinimumSize(QSize(0, 18));

        NIR1_StatLabels->addWidget(NIR1_EXP);

        NIR1_WL = new QLabel(layoutWidget_3);
        NIR1_WL->setObjectName(QStringLiteral("NIR1_WL"));
        NIR1_WL->setMinimumSize(QSize(0, 18));

        NIR1_StatLabels->addWidget(NIR1_WL);


        NIR1Layout->addWidget(NIR1_StatsGraph);


        FourDisplaysLayout->addLayout(NIR1Layout, 0, 1, 1, 1);

        NIR2_Layout = new QHBoxLayout();
        NIR2_Layout->setSpacing(6);
        NIR2_Layout->setObjectName(QStringLiteral("NIR2_Layout"));
        NIR2_Img = new QLabel(layoutWidget);
        NIR2_Img->setObjectName(QStringLiteral("NIR2_Img"));
        NIR2_Img->setMinimumSize(QSize(640, 480));

        NIR2_Layout->addWidget(NIR2_Img);

        NIR2_StatsGraph = new QGroupBox(layoutWidget);
        NIR2_StatsGraph->setObjectName(QStringLiteral("NIR2_StatsGraph"));
        NIR2_StatsGraph->setMinimumSize(QSize(200, 480));
        layoutWidget_5 = new QWidget(NIR2_StatsGraph);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 40, 97, 101));
        NIR2_StatLabels = new QVBoxLayout(layoutWidget_5);
        NIR2_StatLabels->setSpacing(6);
        NIR2_StatLabels->setContentsMargins(11, 11, 11, 11);
        NIR2_StatLabels->setObjectName(QStringLiteral("NIR2_StatLabels"));
        NIR2_StatLabels->setContentsMargins(0, 0, 0, 0);
        NIR2_FPS = new QLabel(layoutWidget_5);
        NIR2_FPS->setObjectName(QStringLiteral("NIR2_FPS"));
        NIR2_FPS->setMinimumSize(QSize(0, 18));

        NIR2_StatLabels->addWidget(NIR2_FPS);

        NIR2_EXP = new QLabel(layoutWidget_5);
        NIR2_EXP->setObjectName(QStringLiteral("NIR2_EXP"));
        NIR2_EXP->setMinimumSize(QSize(0, 18));

        NIR2_StatLabels->addWidget(NIR2_EXP);

        NIR2_WL = new QLabel(layoutWidget_5);
        NIR2_WL->setObjectName(QStringLiteral("NIR2_WL"));
        NIR2_WL->setMinimumSize(QSize(0, 18));

        NIR2_StatLabels->addWidget(NIR2_WL);


        NIR2_Layout->addWidget(NIR2_StatsGraph);


        FourDisplaysLayout->addLayout(NIR2_Layout, 1, 0, 1, 1);

        LiveStatsLayout = new QHBoxLayout();
        LiveStatsLayout->setSpacing(6);
        LiveStatsLayout->setObjectName(QStringLiteral("LiveStatsLayout"));
        Merge_Img = new QLabel(layoutWidget);
        Merge_Img->setObjectName(QStringLiteral("Merge_Img"));
        Merge_Img->setMinimumSize(QSize(640, 480));

        LiveStatsLayout->addWidget(Merge_Img);

        LiveStatsandGraph = new QGroupBox(layoutWidget);
        LiveStatsandGraph->setObjectName(QStringLiteral("LiveStatsandGraph"));
        LiveStatsandGraph->setMinimumSize(QSize(200, 480));
        layoutWidget_7 = new QWidget(LiveStatsandGraph);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 40, 97, 101));
        LiveStats_StatLabels = new QVBoxLayout(layoutWidget_7);
        LiveStats_StatLabels->setSpacing(6);
        LiveStats_StatLabels->setContentsMargins(11, 11, 11, 11);
        LiveStats_StatLabels->setObjectName(QStringLiteral("LiveStats_StatLabels"));
        LiveStats_StatLabels->setContentsMargins(0, 0, 0, 0);
        LiveStats_FPS = new QLabel(layoutWidget_7);
        LiveStats_FPS->setObjectName(QStringLiteral("LiveStats_FPS"));
        LiveStats_FPS->setMinimumSize(QSize(0, 18));

        LiveStats_StatLabels->addWidget(LiveStats_FPS);

        LiveStats_EXP = new QLabel(layoutWidget_7);
        LiveStats_EXP->setObjectName(QStringLiteral("LiveStats_EXP"));
        LiveStats_EXP->setMinimumSize(QSize(0, 18));

        LiveStats_StatLabels->addWidget(LiveStats_EXP);

        LiveStats_WL = new QLabel(layoutWidget_7);
        LiveStats_WL->setObjectName(QStringLiteral("LiveStats_WL"));
        LiveStats_WL->setMinimumSize(QSize(0, 18));

        LiveStats_StatLabels->addWidget(LiveStats_WL);


        LiveStatsLayout->addWidget(LiveStatsandGraph);


        FourDisplaysLayout->addLayout(LiveStatsLayout, 1, 1, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 168, 70));
        VideoControlButtons = new QGridLayout(layoutWidget1);
        VideoControlButtons->setSpacing(6);
        VideoControlButtons->setContentsMargins(11, 11, 11, 11);
        VideoControlButtons->setObjectName(QStringLiteral("VideoControlButtons"));
        VideoControlButtons->setContentsMargins(0, 0, 0, 0);
        liveButton = new QPushButton(layoutWidget1);
        liveButton->setObjectName(QStringLiteral("liveButton"));
        liveButton->setMinimumSize(QSize(75, 31));

        VideoControlButtons->addWidget(liveButton, 0, 0, 1, 1);

        snapButton = new QPushButton(layoutWidget1);
        snapButton->setObjectName(QStringLiteral("snapButton"));
        snapButton->setMinimumSize(QSize(75, 31));

        VideoControlButtons->addWidget(snapButton, 0, 1, 1, 1);

        stopButton = new QPushButton(layoutWidget1);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setMinimumSize(QSize(75, 31));

        VideoControlButtons->addWidget(stopButton, 1, 0, 1, 1);

        recordButton = new QPushButton(layoutWidget1);
        recordButton->setObjectName(QStringLiteral("recordButton"));
        recordButton->setMinimumSize(QSize(75, 31));

        VideoControlButtons->addWidget(recordButton, 1, 1, 1, 1);

        initiateButton = new QPushButton(centralWidget);
        initiateButton->setObjectName(QStringLiteral("initiateButton"));
        initiateButton->setGeometry(QRect(10, 110, 171, 51));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        initiateButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1444, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        ColorCamera_Img->setText(QString());
        ColorCamera_StatsGraph->setTitle(QApplication::translate("MainWindow", "Color Camera", 0));
        ColorCamera_FPS->setText(QApplication::translate("MainWindow", "Frames Per second:", 0));
        ColorCamera_EXP->setText(QApplication::translate("MainWindow", "Esposure:", 0));
        ColorCamera_WL->setText(QApplication::translate("MainWindow", "White Light:", 0));
        NIR1_Img->setText(QString());
        NIR1_StatsGraph->setTitle(QApplication::translate("MainWindow", "Color Camera", 0));
        NIR1_FPS->setText(QApplication::translate("MainWindow", "Frames Per second:", 0));
        NIR1_EXP->setText(QApplication::translate("MainWindow", "Esposure:", 0));
        NIR1_WL->setText(QApplication::translate("MainWindow", "White Light:", 0));
        NIR2_Img->setText(QString());
        NIR2_StatsGraph->setTitle(QApplication::translate("MainWindow", "Color Camera", 0));
        NIR2_FPS->setText(QApplication::translate("MainWindow", "Frames Per second:", 0));
        NIR2_EXP->setText(QApplication::translate("MainWindow", "Esposure:", 0));
        NIR2_WL->setText(QApplication::translate("MainWindow", "White Light:", 0));
        Merge_Img->setText(QString());
        LiveStatsandGraph->setTitle(QApplication::translate("MainWindow", "Color Camera", 0));
        LiveStats_FPS->setText(QApplication::translate("MainWindow", "Frames Per second:", 0));
        LiveStats_EXP->setText(QApplication::translate("MainWindow", "Esposure:", 0));
        LiveStats_WL->setText(QApplication::translate("MainWindow", "White Light:", 0));
        liveButton->setText(QApplication::translate("MainWindow", "Live", 0));
        snapButton->setText(QApplication::translate("MainWindow", "Snap", 0));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        recordButton->setText(QApplication::translate("MainWindow", "Record", 0));
        initiateButton->setText(QApplication::translate("MainWindow", "Initiate Camera", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
