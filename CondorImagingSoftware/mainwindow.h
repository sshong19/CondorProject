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
    void update();
    ~MainWindow();

private slots:

    void on_liveButton_clicked();
    
    void on_stopButton_clicked();
    
    void on_quitButton_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
