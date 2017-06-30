/********************************************************************************
** Form generated from reading UI file 'initialwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIALWINDOW_H
#define UI_INITIALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_initialWindow
{
public:
    QPushButton *pushButton_Done;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topThreeRows;
    QVBoxLayout *verticalLayout_Labels;
    QLabel *label_Dest;
    QLabel *label_StudyName_3;
    QLabel *label_StudyName_2;
    QHBoxLayout *buttonAndEdit;
    QVBoxLayout *verticalLayout_EditFields;
    QLineEdit *lineEdit_Dest;
    QComboBox *comboBox_Operator;
    QComboBox *comboBox_Subject;
    QVBoxLayout *verticalLayout_Buttons;
    QPushButton *pushButton_Dest;
    QPushButton *pushButton_OP;
    QPushButton *pushButton_Sub;
    QHBoxLayout *Studyname;
    QLabel *label_StudyName;
    QLineEdit *lineEdit_StudyName;

    void setupUi(QDialog *initialWindow)
    {
        if (initialWindow->objectName().isEmpty())
            initialWindow->setObjectName(QStringLiteral("initialWindow"));
        initialWindow->resize(645, 242);
        pushButton_Done = new QPushButton(initialWindow);
        pushButton_Done->setObjectName(QStringLiteral("pushButton_Done"));
        pushButton_Done->setGeometry(QRect(190, 190, 271, 31));
        widget = new QWidget(initialWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 30, 471, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topThreeRows = new QHBoxLayout();
        topThreeRows->setObjectName(QStringLiteral("topThreeRows"));
        verticalLayout_Labels = new QVBoxLayout();
        verticalLayout_Labels->setObjectName(QStringLiteral("verticalLayout_Labels"));
        label_Dest = new QLabel(widget);
        label_Dest->setObjectName(QStringLiteral("label_Dest"));
        label_Dest->setAlignment(Qt::AlignCenter);

        verticalLayout_Labels->addWidget(label_Dest);

        label_StudyName_3 = new QLabel(widget);
        label_StudyName_3->setObjectName(QStringLiteral("label_StudyName_3"));
        label_StudyName_3->setAlignment(Qt::AlignCenter);

        verticalLayout_Labels->addWidget(label_StudyName_3);

        label_StudyName_2 = new QLabel(widget);
        label_StudyName_2->setObjectName(QStringLiteral("label_StudyName_2"));
        label_StudyName_2->setAlignment(Qt::AlignCenter);

        verticalLayout_Labels->addWidget(label_StudyName_2);


        topThreeRows->addLayout(verticalLayout_Labels);

        buttonAndEdit = new QHBoxLayout();
        buttonAndEdit->setObjectName(QStringLiteral("buttonAndEdit"));
        verticalLayout_EditFields = new QVBoxLayout();
        verticalLayout_EditFields->setObjectName(QStringLiteral("verticalLayout_EditFields"));
        lineEdit_Dest = new QLineEdit(widget);
        lineEdit_Dest->setObjectName(QStringLiteral("lineEdit_Dest"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Dest->sizePolicy().hasHeightForWidth());
        lineEdit_Dest->setSizePolicy(sizePolicy);

        verticalLayout_EditFields->addWidget(lineEdit_Dest);

        comboBox_Operator = new QComboBox(widget);
        comboBox_Operator->setObjectName(QStringLiteral("comboBox_Operator"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_Operator->sizePolicy().hasHeightForWidth());
        comboBox_Operator->setSizePolicy(sizePolicy1);

        verticalLayout_EditFields->addWidget(comboBox_Operator);

        comboBox_Subject = new QComboBox(widget);
        comboBox_Subject->setObjectName(QStringLiteral("comboBox_Subject"));
        sizePolicy1.setHeightForWidth(comboBox_Subject->sizePolicy().hasHeightForWidth());
        comboBox_Subject->setSizePolicy(sizePolicy1);

        verticalLayout_EditFields->addWidget(comboBox_Subject);


        buttonAndEdit->addLayout(verticalLayout_EditFields);

        verticalLayout_Buttons = new QVBoxLayout();
        verticalLayout_Buttons->setObjectName(QStringLiteral("verticalLayout_Buttons"));
        pushButton_Dest = new QPushButton(widget);
        pushButton_Dest->setObjectName(QStringLiteral("pushButton_Dest"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_Dest->sizePolicy().hasHeightForWidth());
        pushButton_Dest->setSizePolicy(sizePolicy2);

        verticalLayout_Buttons->addWidget(pushButton_Dest);

        pushButton_OP = new QPushButton(widget);
        pushButton_OP->setObjectName(QStringLiteral("pushButton_OP"));
        sizePolicy2.setHeightForWidth(pushButton_OP->sizePolicy().hasHeightForWidth());
        pushButton_OP->setSizePolicy(sizePolicy2);

        verticalLayout_Buttons->addWidget(pushButton_OP);

        pushButton_Sub = new QPushButton(widget);
        pushButton_Sub->setObjectName(QStringLiteral("pushButton_Sub"));
        sizePolicy2.setHeightForWidth(pushButton_Sub->sizePolicy().hasHeightForWidth());
        pushButton_Sub->setSizePolicy(sizePolicy2);

        verticalLayout_Buttons->addWidget(pushButton_Sub);


        buttonAndEdit->addLayout(verticalLayout_Buttons);


        topThreeRows->addLayout(buttonAndEdit);


        verticalLayout->addLayout(topThreeRows);

        Studyname = new QHBoxLayout();
        Studyname->setObjectName(QStringLiteral("Studyname"));
        label_StudyName = new QLabel(widget);
        label_StudyName->setObjectName(QStringLiteral("label_StudyName"));
        label_StudyName->setAlignment(Qt::AlignCenter);

        Studyname->addWidget(label_StudyName);

        lineEdit_StudyName = new QLineEdit(widget);
        lineEdit_StudyName->setObjectName(QStringLiteral("lineEdit_StudyName"));
        sizePolicy.setHeightForWidth(lineEdit_StudyName->sizePolicy().hasHeightForWidth());
        lineEdit_StudyName->setSizePolicy(sizePolicy);

        Studyname->addWidget(lineEdit_StudyName);


        verticalLayout->addLayout(Studyname);

        pushButton_Done->raise();
        label_StudyName->raise();
        label_StudyName->raise();

        retranslateUi(initialWindow);

        QMetaObject::connectSlotsByName(initialWindow);
    } // setupUi

    void retranslateUi(QDialog *initialWindow)
    {
        initialWindow->setWindowTitle(QApplication::translate("initialWindow", "Dialog", 0));
        pushButton_Done->setText(QApplication::translate("initialWindow", "Done", 0));
        label_Dest->setText(QApplication::translate("initialWindow", "Destination Folder:", 0));
        label_StudyName_3->setText(QApplication::translate("initialWindow", "Operator:", 0));
        label_StudyName_2->setText(QApplication::translate("initialWindow", "Subject:", 0));
        pushButton_Dest->setText(QApplication::translate("initialWindow", "Select Folder", 0));
        pushButton_OP->setText(QApplication::translate("initialWindow", "Edit/Add/Delete", 0));
        pushButton_Sub->setText(QApplication::translate("initialWindow", "Edit/Add/Delete", 0));
        label_StudyName->setText(QApplication::translate("initialWindow", "Study Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class initialWindow: public Ui_initialWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALWINDOW_H
