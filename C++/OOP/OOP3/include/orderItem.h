#ifndef ORDERITEM_H
#define ORDERITEM_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include "Stock.h"
#include "Product.h"

using namespace std;

class orderItem
{
    public:
        orderItem();
        orderItem(double sa_pr,double qu);
        void getData();
        void setSalePrice(double sa_pr){salePrice = sa_pr;};
        double getSalePrice(){return salePrice;};
        void updateQuantity(double newQuantity);

        void operator++();
        void operator--();
        void operator+=(int n);
        void operator-=(int n);

        string print();
        virtual ~orderItem();

    protected:

    private:
        double salePrice;
        double quantity;
        Stock st;
        Product pro;
};

#endif // ORDERITEM_H
