#include<iostream>
#include<cmath>
#include<string>
#include "Employee.h"
#include "StaffMember.h"
#include "Budget.h"

using namespace std;


#ifndef PROJECT_H
#define PROJECT_H


class Project: public Budget
{
    public:
        Project();
        Project(int pr_id,int ma_id,string lo,string ma_na,string ma_ph,string ma_em,double cu,int bu_s);
        void setProjectID(int pr_id){projectId = pr_id;};
        int getProjectID() const {return projectId;};
        void getData();
        void addBudget();
        void getTotalBudget();
        void print();
        virtual ~Project();

    protected:

    private:
        int projectId,managerId;
        string location,managerName,managerPhone,managerEmail;
        double currentCost;
        Budget* budgets;
        int budget_size;
        int budget_count;

};

#endif // PROJECT_H
