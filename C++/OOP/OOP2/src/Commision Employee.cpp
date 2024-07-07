#include "Commision Employee.h"

Commision_Employee::Commision_Employee()
{
    target = 0.0;
}
Commision_Employee::Commision_Employee(int e_id,string n,string ph,string em,string ssn,double ta): Employee(e_id,n,ph,em,ssn)
{
    target = ta;
}
void Commision_Employee::getData()
{
    Employee::getData();

    cout << "Enter target : " ;
    cin >> target;
}
double Commision_Employee::pay()
{
    return  target * (5/100);
}
string Commision_Employee::print()
{
    //Employee::print();

    //cout << "Calculate Payroll of Commision Employee : " << target << endl;
    return Employee::print() + "\n Calculate Payroll of Commision Employee : " + to_string(target);
}
Commision_Employee::~Commision_Employee()
{
    //dtor
}
