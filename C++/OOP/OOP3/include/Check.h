#ifndef CHECK_H
#define CHECK_H

#include<iostream>
#include<string>
#include<cstring>
#include<ctime>

using namespace std;

class Check
{
    public:
        Check();
        Check(string ch_na,string ba_id);
        void getData();
        string print();
        virtual ~Check();

    protected:

    private:
        string checkName;
        string bankID;
};

#endif // CHECK_H
