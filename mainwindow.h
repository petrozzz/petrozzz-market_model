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

    void on_pb_store_clicked();

    void on_cb_Audit_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer = nullptr;
    QDateTime datetime;

    void refresh_time();
    Market* market = nullptr;
    Mytime *time = nullptr;
    void set_mytime();
    bool is_store = true;
    void init_tb_store();
    void refresh_tb_store();
    void showhide_store();

};

#endif // MAINWINDOW_H
