#ifndef COMPANY_H
#define COMPANY_H
#include"Customer.h"
#include <iostream>
#include<string>
#include<cstring>

using namespace std;


class Company : public Customer
{
    public:
        Company();
        Company(int i_cu,string ph,string lo,string co_na);
        virtual void getData();
        virtual string print();
        virtual ~Company();

    protected:

    private:
        string location;
        string company_name;
};

#endif // COMPANY_H
