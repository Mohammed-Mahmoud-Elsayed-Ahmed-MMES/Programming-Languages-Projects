#ifndef CASH_H
#define CASH_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>

using namespace std;

class Cash
{
    public:
        Cash();
        Cash(double ca_va);
        void getData();
        string print();
        virtual ~Cash();

    protected:

    private:
        double cashValue;
};

#endif // CASH_H
