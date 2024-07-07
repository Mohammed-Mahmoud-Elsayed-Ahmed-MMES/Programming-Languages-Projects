#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include "OrderStatus.h"
#include "orderItem.h"
#include "Customer.h"

using namespace std;

class Order
{
    public:
        Order();
        Order(int or_id,int or_status,int nu,time_t da,double to,int or_s,int oRc_s);
        virtual void setOrderID(int or_id){orderID = or_id;};
        virtual int getOrderID(){return orderID;};

        void createOrder();
        void updateOrder(int or_id,int or_status);
        void editOrder(int or_id);
        orderItem* orderList;

        friend ostream&operator<<(ostream&outPut,Order&order);
        friend istream&operator>>(istream&inPut,Order&order);

        virtual ~Order();

    protected:

    private:
        int orderID,status,order_count,order_size,oRcustomer_count,oRcustomer_size;
        int number;
        time_t date;
        double total;

        Customer* customerData;
        OrderStatus os;
};

#endif // ORDER_H
