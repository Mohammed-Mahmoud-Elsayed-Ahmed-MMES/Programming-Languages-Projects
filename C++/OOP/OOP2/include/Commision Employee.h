#include<iostream>
#include<cmath>
#include<string>
#include <cstring>

using namespace std;

#ifndef COMMISION EMPLOYEE_H
#define COMMISION EMPLOYEE_H
#include "Employee.h"

class Commision_Employee : public Employee
{
    public:
        Commision_Employee();
        Commision_Employee(int e_id,string n,string ph,string em,string ssn,double ta);
        virtual void getData();
        virtual double pay();
        virtual string print();
        virtual ~Commision_Employee();

    protected:
        double target;
    private:
};

#endif // COMMISION EMPLOYEE_H
