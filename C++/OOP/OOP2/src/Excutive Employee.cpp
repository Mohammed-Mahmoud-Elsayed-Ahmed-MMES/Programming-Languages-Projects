#include "Excutive Employee.h"

Excutive_Employee::Excutive_Employee()
{
    bonus = 0.0;
}
Excutive_Employee::Excutive_Employee(int e_id,string n,string ph,string em,string ssn,double sa,double bo) : Salaried_Employee(e_id,n,ph,em,ssn,sa)
{
    bonus = bo;
}
void Excutive_Employee::getData()
{
    Salaried_Employee::getData();

    cout << "Enter Bonus : ";
    cin >> bonus;
}
void Excutive_Employee::addBouns()
{
    double moreBonus;
    cin >> moreBonus;
    if(moreBonus!=0)
        bonus = bonus + moreBonus;
}
double Excutive_Employee::pay()
{
    return salary + bonus;
}
string Excutive_Employee::print()
{
    return Employee::print() + "\n Calculate Payroll of Executive Employee : " + to_string(bonus);
}
Excutive_Employee::~Excutive_Employee()
{
    //dtor
}
