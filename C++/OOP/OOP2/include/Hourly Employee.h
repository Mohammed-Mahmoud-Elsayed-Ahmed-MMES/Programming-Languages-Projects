#include<iostream>
#include<cmath>
#include<string>

using namespace std;


#ifndef HOURLY EMPLOYEE_H
#define HOURLY EMPLOYEE_H
#include "Employee.h"


class Hourly_Employee : public Employee
{
public:
    Hourly_Employee();
    Hourly_Employee(int e_id,string n,string ph,string em,string ssn,double h_w,double ra);
    virtual void getData();
    void addHours(double moreHours);
    virtual string print();
    virtual double pay();
    virtual ~Hourly_Employee();

protected:
    double hoursWorked;
    double rate;
private:

};

#endif // HOURLY_EMPLOYEE_H
