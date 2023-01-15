#include "mainwindow.h"
#include "ui_mainwindow.h"

//----------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , time(0)
    , pixelCounter(-2)
    , oldX(0)
    , oldY(0)
    , saveFileDir(QDir::currentPath())
    , isСounting(false)
    , timeDialogWindow(nullptr)

{
    ui->setupUi(this);

    timeDialogWindow = new setTimeWindow(this);

    timer = new QTimer(this);
    timer->start(1000);

    QObject::connect(timeDialogWindow, SIGNAL(StartTimeButtonWasPressed(QTime)), this, SLOT(cursoreController(QTime)));
    QObject::connect(ui->mouseAreaLabel, SIGNAL(ChengePose()), this, SLOT(mousePose()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    QObject::connect(this, SIGNAL(saveDirWasChenged(QString)), timeDialogWindow, SLOT(setSaveDir(QString)));
    saveDirWasChenged(saveFileDir);
}
//----------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//----------------------------------------------------
void MainWindow::timerSlot()
{
      if(time > 0){
       --time;
        ui->labelTime->setText(QString::number(time));
      }
      if (time == 0 && isСounting) {

           QDateTime date(QDateTime::currentDateTime());
           QFile file(saveFileDir + "//" + date.date().toString() + " " + date.time().toString().replace(':', '-') +  ".txt");
           if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
               QTextStream stream(&file);
               stream << pixelCounter << '\n';
               file.close();
           }

           QMessageBox msgBox;
           msgBox.setWindowTitle("Результат сохранен");
           msgBox.setText(saveFileDir + "//" + date.date().toString() + " " + date.time().toString().replace(':', '-') +  ".txt");
           msgBox.exec();

          isСounting = false;
      }
}
//----------------------------------------------------
void MainWindow::cursoreController(QTime newTime) {

    time = QTime(0, 0, 0).secsTo(newTime);
    isСounting = true;
    pixelCounter = -2;

}
//----------------------------------------------------
void MainWindow::mousePose() {

    if(time > 0) {

        if(oldX != ui->mouseAreaLabel->GetX()) {
             oldX = ui->mouseAreaLabel->GetX();
             ++pixelCounter;
        }

        if (oldY != ui->mouseAreaLabel->GetY()) {
              oldY = ui->mouseAreaLabel->GetY();
             ++pixelCounter;
        }

    ui->labelPixels->setText(QString("Пикселей пройдено: %1").arg(pixelCounter));

  }

    ui->labelPosition->setText(QString("Положение курсора X = %1, Y = %2").arg(ui->mouseAreaLabel->GetX()).arg(ui->mouseAreaLabel->GetY()));

}
//----------------------------------------------------
void MainWindow::on_pushButton_clicked() { timeDialogWindow->show(); }
//----------------------------------------------------
void MainWindow::on_pushButtonSaveDir_clicked()
{
    saveFileDir = QFileDialog::getExistingDirectory(this, tr("Папка для сохранения"),
                                                QString(),
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);

     saveDirWasChenged(saveFileDir);
}
//----------------------------------------------------


