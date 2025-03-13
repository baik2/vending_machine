#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    money=0;
    Rest();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Rest()
{
    ui->pbCoffee->setEnabled(false);
    ui->pbmilk->setEnabled(false);
    ui->pbTea->setEnabled(false);

    if(money>=100){
        ui->pbCoffee->setEnabled(true);
    }
    else if(money>=150){
        ui->pbmilk->setEnabled(true);
    }
    else if(money>=200){
        ui->pbTea->setEnabled(true);
    }
    ui->lcdNumber->display(money);
}

void Widget::increaseMoney(int value)
{
    money+=value;
    ui-> lcdNumber->display(money);
    Rest();
}

void Widget::on_pb10_clicked()
{
    increaseMoney(10);
}


void Widget::on_pb50_clicked()
{
    increaseMoney(50);
}


void Widget::on_pb100_clicked()
{
    increaseMoney(100);
}


void Widget::on_pb500_clicked()
{
    increaseMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    increaseMoney(-100);
}


void Widget::on_pbmilk_clicked()
{
    increaseMoney(-150);

}

void Widget::on_pbTea_clicked()
{
    increaseMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    int change = money;
    int coin500 = change / 500;
    change %= 500;
    int coin100 = change / 100;
    change %= 100;
    int coin50 = change / 50;
    change %= 50;
    int coin10 = change / 10;

    QString message = QString("500won: %1\n100won: %2\n50won: %3\n10won: %4")
                          .arg(coin500).arg(coin100).arg(coin50).arg(coin10);

    QMessageBox::information(this, "Result", message);

    // Reset money
    money = 0;
    ui->lcdNumber->display(money);
}

