#ifndef CREDIT_H
#define CREDIT_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>

using namespace std;

class Credit
{
    public:
        Credit();
        Credit(string cr_nu,string ex_da,string cr_ty);
        void getData();
        string print();
        virtual ~Credit();

    protected:

    private:
        string creditNumber;
        string expireDate;
        string creditType;
};

#endif // CREDIT_H
