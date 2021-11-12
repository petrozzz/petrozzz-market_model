#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(10); // 5 min;
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
    datetime = QDateTime(QDate(2021, 10, 1), QTime(10, 30, 00));    
    market = new Market();
    time = new Mytime();
    market->init_market();
    init_tb_store();
    showhide_store();
}

MainWindow::~MainWindow(){
    delete ui;
    if(timer) delete timer;
    if(market) delete market;
    if(time) delete time;
}

void MainWindow::on_timeout(){
    datetime = datetime.addSecs(5*60);
    refresh_time();
}

void MainWindow::refresh_time(){
    QString str = datetime.toString("dd.MM.yyyy:) hh:mm");
    set_mytime();
    ui->lb_time->setText(datetime.toString("dd.MM.yyyy (") +
                         QString(time->nameweekday.data()) +
                         datetime.toString(") hh:mm"));
    market->refresh(time);
    str = QString(market->get_message().data());
    if (str.length()>0)
        ui->te_log->append(str);
    if(!is_store){
        refresh_tb_store();
    }
}

void MainWindow::set_mytime(){
    time->year = datetime.date().year();
    time->month = datetime.date().month();
    time->day = datetime.date().day();
    time->wday = datetime.date().dayOfWeek();
    time->hour = datetime.time().hour();
    time->minute = datetime.time().minute();
    time->nameweekday = time->namesweekday[time->wday-1];
}

void MainWindow::init_tb_store(){    
    ui->tb_store->setColumnCount(2);
    ui->tb_store->setRowCount(7);
    ui->tb_store->setItem(0, 0, new QTableWidgetItem("Капитал"));
    ui->tb_store->setItem(1, 0, new QTableWidgetItem("Баланс"));
    ui->tb_store->setItem(2, 0, new QTableWidgetItem("Хлеб"));
    ui->tb_store->setItem(3, 0, new QTableWidgetItem("Масло"));
    ui->tb_store->setItem(4, 0, new QTableWidgetItem("Шоколад"));
    ui->tb_store->setItem(5, 0, new QTableWidgetItem("Чай"));
    ui->tb_store->setItem(6, 0, new QTableWidgetItem("Сыр"));
    refresh_tb_store();
}

void MainWindow::refresh_tb_store(){
    ui->tb_store->setItem(0, 1, new QTableWidgetItem(QString("%1").arg(market->balance + market->stack.balance)));
    ui->tb_store->setItem(1, 1, new QTableWidgetItem(QString("%1").arg(market->balance)));
    ui->tb_store->setItem(2, 1, new QTableWidgetItem(QString("%1").arg(market->stack.count_good(31))));
    ui->tb_store->setItem(3, 1, new QTableWidgetItem(QString("%1").arg(market->stack.count_good(41))));
    ui->tb_store->setItem(4, 1, new QTableWidgetItem(QString("%1").arg(market->stack.count_good(11))));
    ui->tb_store->setItem(5, 1, new QTableWidgetItem(QString("%1").arg(market->stack.count_good(21))));
    ui->tb_store->setItem(6, 1, new QTableWidgetItem(QString("%1").arg(market->stack.count_good(42))));
}

void MainWindow::showhide_store(){
    if(is_store){
        ui->pb_store->setText("События");
        ui->te_log->setVisible(true);
        ui->tb_store->setVisible(false);
    } else {
        ui->pb_store->setText("Склад");
        ui->te_log->setVisible(false);
        ui->tb_store->setVisible(true);
    }
}

void MainWindow::on_pb_start_clicked(){
    if(timer->isActive()){
        timer->stop();
        ui->pb_start->setText("Старт");
    } else {
        timer->start();
        ui->pb_start->setText("Пауза");
    }
}

void MainWindow::on_pb_store_clicked(){
    is_store = !is_store;
    showhide_store();
}
