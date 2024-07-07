#ifndef PERSON_H
#define PERSON_H
#include"Customer.h"
#include <iostream>
#include<string>
#include<cstring>

using namespace std;

class Person : public Customer
{
    public:
        Person();
        Person(int i_cu,string ph,string bi_add,string fn);
        virtual void getData();
        virtual string print();
        virtual ~Person();

    protected:

    private:
        string billing_address;
        string fullname;
};

#endif // PERSON_H
