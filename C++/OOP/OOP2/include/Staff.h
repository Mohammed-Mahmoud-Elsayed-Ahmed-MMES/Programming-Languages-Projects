#include<iostream>
#include<cmath>
#include<string>
#include "StaffMember.h"
#include "Department.h"
#include "Volunteer.h"
#include "Commision Employee.h"
#include "Excutive Employee.h"
#include "Hourly Employee.h"
#include "Salaried Employee.h"

using namespace std;

#ifndef STAFF_H
#define STAFF_H


class Staff : public StaffMember
{
    public:
        Staff();
        Staff(int s_m_s);
        void caclPayroll();
        void addMember();
        int searchForMember(int employeeID) const;
        void delMember();
        void showAll();
        bool assignDepartmentToEmployeeByID(int employeeID,Department* d);
        virtual ~Staff();

    protected:

    private:
        int staff_member_size;
        int staff_member_count;
        StaffMember** staffMembers;
};

#endif // STAFF_H
