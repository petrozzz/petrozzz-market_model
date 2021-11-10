#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include "market.h"
#include "mytime.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_timeout();
    void on_pb_start_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer = nullptr;
    QDateTime datetime;

    void refresh_time();
    Market* market = nullptr;
    mytime *time = nullptr;
    void set_mytime();
};

#endif // MAINWINDOW_H
