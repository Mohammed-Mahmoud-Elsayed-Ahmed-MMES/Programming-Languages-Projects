#include<iostream>
#include<cmath>
#include<string>
#include <cstring>


using namespace std;

#ifndef EXCUTIVE EMPLOYEE_H
#define EXCUTIVE EMPLOYEE_H
#include "Salaried Employee.h"

class Excutive_Employee : public Salaried_Employee
{
    public:
        Excutive_Employee();
        Excutive_Employee(int e_id,string n,string ph,string em,string ssn,double sa,double bo);
        virtual void getData();
        void addBouns();
        virtual double pay();
        virtual string print();
        virtual ~Excutive_Employee();

    protected:
        double bonus;

    private:

};

#endif // EXCUTIVE EMPLOYEE_H
