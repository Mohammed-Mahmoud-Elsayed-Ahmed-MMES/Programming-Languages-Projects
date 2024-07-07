#include<iostream>
#include<cmath>
#include<string>
#include <cstring>
#include <cstdlib>
#include "Department.h"

using namespace std;

#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H


class StaffMember
{
    public:
        StaffMember();
        StaffMember(int e_id,string n,string ph,string em);
        void setEmployeeID(int e_id);
        int getEmployeeID() const;
        virtual void getData();
        virtual string print();
        virtual double pay();

        void setDepartment(Department* d){m_department = d;};//To receive data and pass it to (*m_department)
        Department getDepartment() const {return *m_department;};

        virtual ~StaffMember();

    protected:
        int employeeID;
        string name;
        string phone;
        string email;
        Department* m_department;//Have the job of (* departments) at the have access to the stored data

    private:
};

#endif // STAFFMEMBER_H
