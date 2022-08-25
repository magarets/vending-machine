#ifndef WIDGET_H
#define WIDGET_H
#define SIZE 3
#define NASI 9990
#define COFFEE 3500
#define MILK 3000

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

    public:
        Widget(QWidget *parent = nullptr);
        ~Widget();

        int money = 0;
        int exChange_500 = 0;
        int exChange_100 = 0;
        int exChange_50 = 0;
        int exChange_10 = 0;
        int priceArray[5] = {9990, 3500, 3000};

        std::string s_500;
        std::string s_100;
        std::string s_50;
        std::string s_10;

        void Exchange(int money);
        void changeMoney(int diff);
        void isCheckPrice(int money, int Price);
        void isCheckMoney(int money, int Price);
        void int2str(int m500, int m100, int m50, int m10);

    private slots:
        void on_pb500_clicked();
        void on_pb100_clicked();
        void on_pb50_clicked();
        void on_pb10_clicked();
        void on_pbCoffee_clicked();
        void on_pbMilk_clicked();
        void on_pbNasi_clicked();
        void on_pbReset_clicked();

private:
        Ui::Widget *ui;
};
#endif // WIDGET_H
