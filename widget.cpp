#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbCoffee->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->pbNasi->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::isCheckPrice(int money, int price){ // check can buy
    switch(price){
        case COFFEE:
            if( ui->pbCoffee->isEnabled() == true && money < COFFEE ){
                ui->pbCoffee->setEnabled(false);
                ui->pbCoffee->toggle();
            }
            else if(money < COFFEE){
                ui->pbCoffee->setEnabled(false);
                ui->pbCoffee->toggle();
            }

            if( ui->pbCoffee->isEnabled() == false && money > COFFEE){
                ui->pbCoffee->setEnabled(true);
                ui->pbCoffee->toggle();
            }
            break;

        case MILK:
            if( ui->pbMilk->isEnabled() == true && money < MILK ){
                ui->pbMilk->setEnabled(false);
                ui->pbMilk->toggle();
            }
            else if(money < MILK){
                ui->pbMilk->setEnabled(false);
                ui->pbMilk->toggle();
            }

            if( ui->pbMilk->isEnabled() == false && money > MILK){
                ui->pbMilk->setEnabled(true);
                ui->pbMilk->toggle();
            }
            break;

        case NASI:
            if( ui->pbNasi->isEnabled() == true && money < NASI ){
                ui->pbNasi->setEnabled(false);
                ui->pbNasi->toggle();
            }
            else if(money < NASI){
                ui->pbNasi->setEnabled(false);
                ui->pbNasi->toggle();
            }

            if( ui->pbNasi->isEnabled() == false && money > NASI){
                ui->pbNasi->setEnabled(true);
                ui->pbNasi->toggle();
            }
            break;
    }
}

void Widget::isCheckMoney(int money, int price){ // trun on button
    switch(price){

        case COFFEE:
            if( money >= price && ui->pbCoffee->isEnabled() == false){ // coffee
                ui->pbCoffee->setEnabled(true);
                ui->pbCoffee->toggle();
            }
            break;

        case MILK:
            if( money >= price && ui->pbMilk->isEnabled() == false){ // coffee
                ui->pbMilk->setEnabled(true);
                ui->pbMilk->toggle();
            }
            break;

        case NASI:
            if( money >= price && ui->pbNasi->isEnabled() == false){ // coffee
                ui->pbNasi->setEnabled(true);
                ui->pbNasi->toggle();
            }
            break;
   }
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    for(int i=0; i<SIZE; ++i){
        isCheckMoney(money, priceArray[i]);
    }
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    for(int i=0; i<SIZE; ++i){
        isCheckMoney(money, priceArray[i]);
    }
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    for(int i=0; i<SIZE; ++i){
        isCheckMoney(money, priceArray[i]);
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    for(int i=0; i<SIZE; ++i){
        isCheckMoney(money, priceArray[i]);
    }
}

void Widget::on_pbCoffee_clicked()
{

    changeMoney(-COFFEE);
    for(int i=0; i<SIZE; ++i)
        isCheckPrice(money, priceArray[i]);

}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-MILK);
    for(int i=0; i<SIZE; ++i)
        isCheckPrice(money, priceArray[i]);
}

void Widget::on_pbNasi_clicked()
{
    changeMoney(-NASI);
    for(int i=0; i<SIZE; ++i)
            isCheckPrice(money, priceArray[i]);
}

void Widget::Exchange(int money){
   if(money >= 500){
       exChange_500 = money / 500;
       money -= exChange_500 * 500;
   }

   if(money >= 100){
       exChange_100 = money / 100;
       money -= exChange_100 * 100;
   }

   if(money >= 50){
        exChange_50 = money / 50;
        money -= exChange_50 * 50;
   }

   if(money >= 10){
       exChange_10 = money / 10;
       money -= exChange_10 * 10;
   }
   ui->lcdNumber->display(money);
}

void Widget::int2str(int m500, int m100, int m50, int m10){
    s_500 = std::to_string(m500);
    s_100 = std::to_string(m100);
    s_50 = std::to_string(m50);
    s_10 = std::to_string(m10);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;

    Exchange(money);
    int2str(exChange_500, exChange_100, exChange_50, exChange_10);
    std::string msgExchangeMoney = "500: " + s_500 + ' ' + "100: " + s_100 + ' ' + "50: " + s_50 + ' ' + "10: " + s_10;
    msg.information(nullptr, "Exchange", msgExchangeMoney.c_str());
    money = 0;
}








