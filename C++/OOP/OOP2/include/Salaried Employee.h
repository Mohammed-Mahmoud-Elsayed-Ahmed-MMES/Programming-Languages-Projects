#include<iostream>
#include<cmath>
#include<string>

using namespace std;


#ifndef SALARIED EMPLOYEE_H
#define SALARIED EMPLOYEE_H
#include "Employee.h"

class Salaried_Employee : public Employee
{
    public:
        Salaried_Employee();
        Salaried_Employee(int e_id,string n,string ph,string em,string ssn,double sa);
        virtual void getData();
        virtual string print();
        virtual double pay();
        virtual ~Salaried_Employee();

    protected:
        double salary;

    private:
};

#endif // SALARIED EMPLOYEE_H
