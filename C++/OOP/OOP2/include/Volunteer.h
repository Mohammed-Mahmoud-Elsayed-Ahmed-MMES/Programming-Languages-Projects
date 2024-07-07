#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>

using namespace std;

#ifndef VOLUNTEER_H
#define VOLUNTEER_H
#include "StaffMember.h"

class Volunteer : public StaffMember
{
    public:
        Volunteer();
        Volunteer(int e_id,string n,string ph,string em,int am);
        virtual void getData();
        virtual string print();
        virtual double pay();
        virtual ~Volunteer();

    protected:

    private:
        int amount;
};

#endif // VOLUNTEER_H
