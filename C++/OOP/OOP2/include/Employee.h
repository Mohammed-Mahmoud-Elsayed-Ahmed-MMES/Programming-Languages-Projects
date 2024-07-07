#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "StaffMember.h"

class Employee : public StaffMember
{
    public:
        Employee();
        Employee(int e_id,string n,string ph,string em,string ssn);
        void getData();
        virtual string print();
        virtual double pay() = 0;
        virtual ~Employee();

    protected:
        string socialSecurityNnumber;

    private:
};

#endif // EMPLOYEE_H
