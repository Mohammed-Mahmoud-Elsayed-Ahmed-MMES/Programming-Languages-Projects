#include "Transaction.h"
//make object of Orders
//make object of payment
Transaction::Transaction()
{
    transactionDate = " ";
    //order_count = 0;
    //order_size = 5;
    //orderList = new Order[order_size];
}
Transaction::Transaction(string tr_da/*,int or_s*/)
{
    transactionDate = tr_da;
    //order_count ;
    //order_size = or_s;
    //orderList = new Order[order_size];
}
void Transaction::getData()
{
    //o.createOrder();
    cin.ignore();
    cout<<"Enter Transaction Date : ";
    getline(cin,transactionDate);
    py.pay();
}
void Transaction::addOrder()
{
    //Order* new_order = new Order();
    //orderList[order_count++] = *new_order;
}
/*void Transaction::getOrder()
{
    if(order_count == 0)
    {
        cout<< "YOU DID'T REQUEST ANY ORDER"<<endl;
        return;
    }
    for(int i = 0; i < order_count; ++i)
    {
        orderList[i].createOrder();
    }
}*/
void Transaction::updateTransaction(int order_id)
{
    int status;
    o.updateOrder(order_id,status);
    cin.ignore();
    cout << "Enter Transaction Date : ";
    getline(cin,transactionDate);
    py.update();
}
void Transaction::print()
{
    Transaction t;
    cout << o << endl;
    cout << t << endl;
    py.print();
}
ostream&operator <<(ostream &out, Transaction &T)
{
    out << T.o << endl <<"Transaction Date is : " << T.transactionDate<< T.py <<endl;
    return out;
}
/*Transaction operator +=(Product pr, Payment P)
{
    pr.getProductPrice()+= P.pay();
}*/
Transaction::~Transaction()
{
    //delete [] orderList;
}
