#include "Customer.h"

Customer::Customer()
{
    customerID = 0;
    phone = " ";
}
Customer::Customer(int i_cu,string ph)
{
    customerID = i_cu;
    phone = ph;
}
void Customer::getData()
{
    cout << "Enter Customer ID : ";
    cin>> customerID ;
    cout << "Enter Customer Phone : " ;
    cin >> phone ;
}
string Customer::print()
{
    return "Customer ID : " +to_string(customerID)+
           "\nPhone : " + phone ;
}
ostream&operator<<(ostream&out,Customer&cu)
{
    out << "Customer ID : " << cu.customerID << endl << "Customer Phone : " << cu.phone << endl;
    return out;
}
istream&operator>>(istream&in,Customer&cu)
{
    cout << "Enter Customer ID : ";
    in >> cu.customerID;
    //in >> cu.customerID >> cu.phone;
    in.ignore();
    cout << "Enter Customer Phone : ";
    getline(in,cu.phone);
    return in;
}
Customer::~Customer()
{
    //dtor
}
