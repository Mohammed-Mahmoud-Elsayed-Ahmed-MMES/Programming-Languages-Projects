#include "Hourly Employee.h"

Hourly_Employee::Hourly_Employee()
{
    hoursWorked = 0.0;
    rate = 0.0;
}
Hourly_Employee::Hourly_Employee(int e_id,string n,string ph,string em,string ssn,double h_w,double ra) : Employee(e_id,n,ph,em,ssn)
{
    hoursWorked = h_w;
    rate = ra;
}
void Hourly_Employee::getData()
{
    Employee::getData();

    cout << "Enter hours worked : ";
    cin >> hoursWorked;

    cout << "Enter rate : ";
    cin >> rate;
}
void Hourly_Employee::addHours(double moreHours)
{
    hoursWorked = hoursWorked + moreHours;
}
double Hourly_Employee::pay()
{
    return hoursWorked*rate;
}
string Hourly_Employee::print()
{
    return Employee::print() +
    "\n Rate : " + to_string(rate)+
    "\n Worked hours : " + to_string(hoursWorked);
}
Hourly_Employee::~Hourly_Employee()
{
    //dtor
}
