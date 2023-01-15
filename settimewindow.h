#ifndef SETTIMEWINDOW_H
#define SETTIMEWINDOW_H

#include <QDialog>
#include <QTime>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class setTimeWindow;
}

class setTimeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit setTimeWindow(QWidget *parent = nullptr);
    ~setTimeWindow();

private slots:
    void on_startTimePushButton_clicked();
    void on_pushButtonSave_clicked();
    void setSaveDir(const QString& newDir);

    void on_pushButtonLoad_clicked();

signals:
    void StartTimeButtonWasPressed(QTime newTime);

private:
    Ui::setTimeWindow *ui;
    QString saveDir;
};

#endif // SETTIMEWINDOW_H
