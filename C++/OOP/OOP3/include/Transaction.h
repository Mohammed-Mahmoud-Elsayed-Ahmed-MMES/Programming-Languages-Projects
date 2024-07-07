#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include "Payment.h"
#include "Order.h"

using namespace std;

class Transaction
{
    public:
        Transaction();
        Transaction(string tr_da/*,int or_s*/);
        void getData();
        void setOrderID(int or_id){orderID = or_id;};
        int getOrderID(){return orderID;};
        void updateTransaction(int order_id);

        void addOrder();
        void getOrder();
        void print();
        friend ostream&operator <<(ostream &out, Transaction &T);
        friend Transaction operator +=(Order T, Payment P);
        virtual ~Transaction();

    protected:

    private:
        string transactionDate;
        int orderID;
        Order o;
        Payment py;
        /*int order_count;
        int order_size;
        Order* orderList;*/
};

#endif // TRANSACTION_H
