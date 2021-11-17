/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pb_start;
    QPushButton *pb_store;
    QCheckBox *cb_Audit;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QTableWidget *tb_store;
    QTextEdit *te_log;
    QLabel *lb_time;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pb_start = new QPushButton(centralWidget);
        pb_start->setObjectName(QStringLiteral("pb_start"));
        pb_start->setFont(font);

        verticalLayout_2->addWidget(pb_start);

        pb_store = new QPushButton(centralWidget);
        pb_store->setObjectName(QStringLiteral("pb_store"));
        pb_store->setFont(font);

        verticalLayout_2->addWidget(pb_store);

        cb_Audit = new QCheckBox(centralWidget);
        cb_Audit->setObjectName(QStringLiteral("cb_Audit"));

        verticalLayout_2->addWidget(cb_Audit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tb_store = new QTableWidget(centralWidget);
        tb_store->setObjectName(QStringLiteral("tb_store"));
        tb_store->setFont(font);
        tb_store->horizontalHeader()->setVisible(false);
        tb_store->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tb_store);

        te_log = new QTextEdit(centralWidget);
        te_log->setObjectName(QStringLiteral("te_log"));
        te_log->setFont(font);

        verticalLayout->addWidget(te_log);

        lb_time = new QLabel(centralWidget);
        lb_time->setObjectName(QStringLiteral("lb_time"));
        lb_time->setFont(font);
        lb_time->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_time);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", Q_NULLPTR));
        pb_start->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", Q_NULLPTR));
        pb_store->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\273\320\260\320\264", Q_NULLPTR));
        cb_Audit->setText(QApplication::translate("MainWindow", "\320\220\321\203\320\264\320\270\321\202", Q_NULLPTR));
        lb_time->setText(QApplication::translate("MainWindow", "25.10.21 (\320\237\320\275) 12:30", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
