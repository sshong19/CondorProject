#ifndef INITIALWINDOW_H
#define INITIALWINDOW_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class initialWindow;
}

class initialWindow : public QDialog
{
    Q_OBJECT

public:
    explicit initialWindow(QWidget *parent = 0);
    ~initialWindow();

private slots:

    void on_pushButton_Dest_clicked();

    void on_pushButton_OP_clicked();

    void on_pushButton_Sub_clicked();

    void on_lineEdit_Dest_editingFinished();

    void on_pushButton_Done_clicked();

    void on_comboBox_Subject_currentIndexChanged(const QString &arg1);

    void on_comboBox_Operator_currentIndexChanged(const QString &arg1);

    void on_lineEdit_StudyName_editingFinished();

private:
    Ui::initialWindow *ui;
};

#endif // INITIALWINDOW_H
