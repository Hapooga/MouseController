#include "settimewindow.h"
#include "ui_settimewindow.h"

//----------------------------------------------------
setTimeWindow::setTimeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setTimeWindow)
{
    ui->setupUi(this);
}
//----------------------------------------------------
setTimeWindow::~setTimeWindow() { delete ui; }
//----------------------------------------------------
void setTimeWindow::on_startTimePushButton_clicked()
{
    this->close();
    emit StartTimeButtonWasPressed(ui->timeEdit->time());
}
//----------------------------------------------------
void setTimeWindow::setSaveDir(const QString& newDir) { saveDir = newDir; }
//----------------------------------------------------
void setTimeWindow::on_pushButtonSave_clicked()
{
    QDateTime date(QDateTime::currentDateTime());
    QFile file(saveDir + "//" + date.date().toString() + " " + ui->timeEdit->time().toString().replace(':', '-') +  ".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << ui->timeEdit->time().toString() << '\n';
        file.close();
    }
}
//----------------------------------------------------
void setTimeWindow::on_pushButtonLoad_clicked()
{
    QString Filename = QFileDialog::getOpenFileName( this,
    QString("Открыть файл"), QString(),
    QString("Текстовые файлы (*.txt);"));

    QFile file(Filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString buffer;
        stream >> buffer;
        QStringList list(buffer.split(':'));
        QTime time;
        time.setHMS(list[0].toInt(), list[1].toInt(), list[2].toInt());
        ui->timeEdit->setTime(time);
        file.close();
    }

}

