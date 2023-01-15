#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include "settimewindow.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void cursoreController(QTime newTime);
    void mousePose();
    void on_pushButton_clicked();
    void timerSlot();
    void on_pushButtonSaveDir_clicked();

signals:
    void saveDirWasChenged(QString newDir);

private:
    Ui::MainWindow *ui;
    QTimer* timer;

    int time;
    uint pixelCounter;
    int oldX;
    int oldY;
    QString saveFileDir;
    bool isСounting;

    setTimeWindow* timeDialogWindow;
};
#endif // MAINWINDOW_H
