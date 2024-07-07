#include "Person.h"

Person::Person():Customer()
{
    billing_address = " ";
    fullname = " ";
}
Person::Person(int i_cu,string ph,string bi_add,string fn):Customer(i_cu,ph)
{
    billing_address = bi_add;
    fullname = fn;
}
void Person::getData()
{
    Customer::getData();
    cout << "Enter Address of billing : " ;
    cin >> billing_address;
    cout<< "Enter Full Name : " ;
    cin >> fullname;
}
string Person::print()
{
    return Customer::print() + "\nAddress of billing : " + billing_address + "\nFull Name : " + fullname;
}
Person::~Person()
{
    //dtor
}
