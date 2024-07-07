#include "Salaried Employee.h"

Salaried_Employee::Salaried_Employee()
{
    salary = 0.0;
}
Salaried_Employee::Salaried_Employee(int e_id,string n,string ph,string em,string ssn,double sa) : Employee(e_id,n,ph,em,ssn)
{
    salary = sa;
}
void Salaried_Employee::getData()
{
    Employee::getData();

    cout << "Enter Salary : " ;
    cin >> salary;
}
double Salaried_Employee::pay()
{
    return salary;
}
string Salaried_Employee::print()
{
    return Employee::print() + "\n Calculate Payroll of Salaried Employee : " + to_string(salary);
}
Salaried_Employee::~Salaried_Employee()
{
    //dtor
}
