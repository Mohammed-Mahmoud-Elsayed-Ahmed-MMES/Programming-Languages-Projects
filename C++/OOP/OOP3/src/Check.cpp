#include "Check.h"

Check::Check()
{
    //ctor
}
Check::Check(string ch_na,string ba_id)
{
    checkName = ch_na;
    bankID = ba_id;
}
void Check::getData()
{
    cin.ignore();
    cout<<"Enter your Check Name : ";
    getline(cin,checkName);
    cout<<"Enter your Bank ID :";
    getline(cin,bankID);
}
string Check::print()
{
    return "\nCustomer Check Name : " + checkName +
           "\nBank ID : " + bankID ;
}
Check::~Check()
{
    //dtor
}
