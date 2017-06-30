#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>

#include "ArchitectorSDKFunctions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow getUi();
    ~MainWindow();

private slots:

    void on_stopButton_clicked();

    void on_snapButton_clicked();

    void on_initiateButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
