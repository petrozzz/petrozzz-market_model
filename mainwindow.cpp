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
    time = new mytime();
    market->init_market();
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

void MainWindow::on_pb_start_clicked(){
    if(timer->isActive()){
        timer->stop();
        ui->pb_start->setText("Старт");
    } else {
        timer->start();
        ui->pb_start->setText("Пауза");
    }
}
