#include "Order.h"
//make list of orderItems
//make pointer to customer like an attribute
Order::Order()
{
    orderID = 0;
    number = 0;
    date = 0;
    total = 0.0;
    order_count = 0;
    order_size = 5;
    orderList = new orderItem[order_size];
    oRcustomer_count = 0;
    oRcustomer_size = 5;
    customerData = new Customer[oRcustomer_size];
}
Order::Order(int or_id,int or_status,int nu,time_t da,double to,int or_s,int oRc_s)
{
    orderID = or_id;
    status = or_status;
    number = nu;
    date = da;
    total = to ;
    order_count ;
    order_size = or_s;
    orderList = new orderItem[order_size];
    oRcustomer_count;
    oRcustomer_size = oRc_s;
    customerData = new Customer[oRcustomer_size];
}
ostream&operator<<(ostream&outPut,Order&order)
{
    outPut //<< "Customer Data : \n" <<order.customerData->print() << endl
           << "Order ID : " << order.orderID << endl
           << "Order Number : " << order.number << endl
           << "Order Date : " << order.date << endl
           << "Order Status : ";
           if(order.os == OrderStatus::NEW)
            outPut << "NEW\n";
           if(order.os == OrderStatus::HOLD)
            outPut << "HOLD\n";
           if(order.os == OrderStatus::PAID)
            outPut << "PAID\n";
           if(order.os == OrderStatus::CANCELED)
            outPut << "CANCELED\n";
           outPut << "Order Total : " << order.total << endl;
           outPut << "\tOrder Item : \n" << order.orderList->print() << endl;
    return outPut;
}
istream&operator>>(istream&inPut,Order&order)
{
    //cout << "\tEnter Customer Data : " << endl;
    //order.customerData->getData();             //   //ERROR
    cout << endl;
    cout << "Enter Order ID : ";
    inPut >> order.orderID;
    cout << "Enter Order Number : ";
    inPut >> order.number;
    cout << "Enter Order Date : " ;
    inPut >> order.date;
    cout << "Enter Order Status : ";
    inPut >> order.status;
    cout << "Enter Order Total : ";
    inPut >> order.total;
    cout << endl;
    cout << "\tEnter Oder Item : \n";
    order.orderList->getData();
    return inPut;
}
void Order::createOrder()
{
    //cout << "\tEnter Customer Data : "<< endl;
    //customerData->getData();
    cout << "Enter Order ID : ";
    cin >> orderID;
    cout << "Enter Order Number : ";
    cin >> number;
    cout << "Enter Order Date : " ;
    cin >> date;
    cout << "Enter Order Status : ";
    cin >> status;
    cout << "Enter Order Total : ";
    cin >> total;
    cout << "\tEnter Oder Item : ";
    orderList->getData();
}
void Order::updateOrder(int or_id,int status)
{
    bool updated;
    int quantity;
    cout << "Enter NEW Customer Data IF there NOT enter last Data : \n";
    customerData[oRcustomer_count++].getData();
    cout << "Enter Order Number : ";
    cin >> number;
    cout << "Enter Order Date : " ;
    cin >> date;
    switch(status)
    {
    case 1:
        os = OrderStatus::NEW;
        break;
    case 2:
       os = OrderStatus::HOLD;
       break;
    case 3:
        os = OrderStatus::PAID;
        break;
    case 4:
        os = OrderStatus::CANCELED;
        break;
    }
    cout << "\tEnter Oder Item : ";
    orderList->updateQuantity(quantity);
    if(updated)
        cout << "\tORDER UPDATED SUCCEFULY\n";
}
void Order::editOrder(int or_id)
{

}
Order::~Order()
{
    //dtor
}
