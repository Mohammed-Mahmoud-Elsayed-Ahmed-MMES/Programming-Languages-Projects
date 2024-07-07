#include "Budget.h"

Budget::Budget()
{
    id = 0;
    value = 0.0;
}
Budget::Budget(int i,double va)
{
    id = i;
    value = va;
}
void Budget::getData()
{
    cout << "Enter budget ID : ";
    cin >> id;
    cout << "Enter budget value : ";
    cin >> value;
}

double Budget::increaseBudget()
{
    double amount;
    cout<<"Enter Increase Budget ";
    cin>>amount;
    return value+=amount;
}

void Budget::print()const
{
    cout<<"Budget ID : "<<id<<endl;
    cout<<"Budget value : "<<value<<endl;
}

Budget::~Budget()
{
    //dtor
}
