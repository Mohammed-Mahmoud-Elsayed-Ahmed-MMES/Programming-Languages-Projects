#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#ifndef BUDGET_H
#define BUDGET_H


class Budget
{
    public:
        Budget();
        Budget(int i,double va);
        void getData();
        void setBudgetID(int i){id = i;};
        int getBudgetID() const {return id;};
        void setBudgetValue(double va){value = va;};
        double getBudgetValue() const {return value;};
        double increaseBudget();
        void print() const;
        virtual ~Budget();

    protected:
        int id;
        double value;

    private:

};

#endif // BUDGET_H
