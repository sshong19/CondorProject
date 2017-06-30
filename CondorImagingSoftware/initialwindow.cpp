#include "initialwindow.h"
#include "ui_initialwindow.h"
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>
#include <QDate>

QString currentDir, currentOP, currentSub, studyName;
QStringList operators, subjects;

initialWindow::initialWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::initialWindow){
        ui->setupUi(this);
        this->setWindowTitle("Study Specifications");

        // Setup for Directory Selection
        currentDir = "C:/Expiriments/Data";
        ui->lineEdit_Dest->setText(currentDir);
        QDir startDir(currentDir);
        if(!startDir.exists()){
            startDir.mkpath(currentDir);
        }

        // Setup for Operator Selection
        operators << "Select:" << "ABC" << "DEF" << "PERSON";
        currentOP = "Select:";
        ui->comboBox_Operator->addItems(operators);

        // Setup for Subject Selection
        subjects << "Select:" << "Brain Imaging" << "DFO-EPL" << "Exosome" << "FH" << "GIST " << "H--dot" << "Heart" <<
                     "Inflamation" << "Insulinoma" << "MIS_Project" << "Nerve" << "Ovary" << "Parathyroid" <<
                     "POS" << "Vaccine" << "Proatate" << "Temp";
        currentSub = "Select:";
        ui->comboBox_Subject->addItems(subjects);

        // Setup for StudyName

}

initialWindow::~initialWindow()
{
    delete ui;
}

void initialWindow::on_pushButton_Dest_clicked()
{
    currentDir = QFileDialog::getExistingDirectory(this, tr("Select Folder"),
                                                         currentDir,
                                                         QFileDialog::ShowDirsOnly|
                                                         QFileDialog::DontResolveSymlinks);
    //QMessageBox::information(this,tr("File Name"), directory);
    ui->lineEdit_Dest->setText(currentDir);
}

void initialWindow::on_pushButton_OP_clicked()
{
    QString filename = QFileDialog::getExistingDirectory(this, tr("Select Folder"),
                                                         "C:/Expiriments/Data",
                                                         QFileDialog::ShowDirsOnly|
                                                         QFileDialog::DontResolveSymlinks);
    QMessageBox::information(this,tr("File Name:"), filename);
}

void initialWindow::on_pushButton_Sub_clicked()
{
    QString filename = QFileDialog::getExistingDirectory(this, tr("Select Folder"),
                                                         "C:/Expiriments/Data",
                                                         QFileDialog::ShowDirsOnly|
                                                         QFileDialog::DontResolveSymlinks);
    QMessageBox::information(this,tr("File Name"), filename);
}

void initialWindow::on_lineEdit_Dest_editingFinished(){
    currentDir = ui->lineEdit_Dest->text();
}

void initialWindow::on_pushButton_Done_clicked(){
    bool err = false;
    QString errmsg = "";
    QDir directory(currentDir);
    if(!directory.exists()){
        // Error since directory is wrong
        errmsg += "Directory Specified doesnt exist. \n";
        err = true;
    }
    if(currentOP == "Select:"){
        // They didn't change operator
        errmsg += "Please specify an operator. \n";
        err = true;
    }
    if(currentSub == "Select:"){
        // They didn't change subject
        errmsg += "Please specify a subject. \n";
        err = true;
    }
    if(ui->lineEdit_StudyName->text() == ""){
        // No study name entered
        errmsg += "Please enter a study name. \n";
        err = true;
    }

    if(!err){
        // Make correct filepath: C:Expiriments/Data/SUBJECT/YEARMONTHDAY/STUDYNAME by default
        QDate current = QDate::currentDate();
        QString numdate = QString::number(current.year()) + QString::number(current.month()) + QString::number(current.day());
        QString dest = currentDir + "/" + currentSub + "/" + numdate + "/" + studyName + "/";
        directory.mkpath(currentDir + "/" + currentSub + "/" + numdate + "/" + studyName + "/");
        QMessageBox::information(this,"Setup","Directory has been made");
        this->hide();
        MainWindow *main = new MainWindow();
        main->show();
    }
    else{
        QMessageBox::information(this,"Error, Please fix: ",errmsg);
    }
}

void initialWindow::on_comboBox_Subject_currentIndexChanged(const QString &arg1){
    currentSub = ui->comboBox_Subject->currentText();
}

void initialWindow::on_comboBox_Operator_currentIndexChanged(const QString &arg1){
    currentOP = ui->comboBox_Operator->currentText();
}

void initialWindow::on_lineEdit_StudyName_editingFinished(){
    studyName = ui->lineEdit_StudyName->text();
}
