#include "Cash.h"
//function of profit
Cash::Cash()
{
    //ctor
}
Cash::Cash(double ca_va)
{
    cashValue = ca_va;
}
void Cash::getData()
{
    cout<<"Enter Cash Value : ";
    cin>>cashValue;
}
string Cash::print()
{
    return "Cash Value : " + to_string(cashValue);
}
Cash::~Cash()
{
    //dtor
}
