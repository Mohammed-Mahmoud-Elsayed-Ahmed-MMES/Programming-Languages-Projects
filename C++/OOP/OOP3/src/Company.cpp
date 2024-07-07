#include "Company.h"

Company::Company() : Customer()
{
    location = " ";
    company_name = " ";
}
Company::Company(int i_cu,string ph,string lo,string co_na) : Customer(i_cu,ph)
{
    location = lo;
    company_name = co_na;
}
void Company::getData()
{
    Customer::getData();
    cout << "Enter Location : " ;
    cin >> location;
    cout<< "Enter Company Name : " ;
    cin >> company_name;
}
string Company::print()
{
    return Customer::print() + "\nLocation : " + location + "\nCompany Name : " + company_name;
}
Company::~Company()
{
    //dtor
}
