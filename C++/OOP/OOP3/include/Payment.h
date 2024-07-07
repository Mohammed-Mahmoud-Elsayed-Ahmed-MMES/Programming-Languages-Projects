#ifndef PAYMENT_H
#define PAYMENT_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include "Credit.h"
#include "Cash.h"
#include "Check.h"

using namespace std;

class Payment
{
public:
    Payment();
    Payment(string p_d,double am);

    double pay();
    string update();
    void print();
    friend ostream&operator <<(ostream &out, Payment &p);

    virtual ~Payment();

protected:

private:
    string paid_date;
    double amount;
};

#endif // PAYMENT_H
