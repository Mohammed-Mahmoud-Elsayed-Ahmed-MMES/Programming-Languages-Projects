#include<iostream>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

#ifndef DEPARTMENT_H
#define DEPARTMENT_H


class Department
{
    public:
        Department();
        Department(int de_id,string de_na);
        void setDepartID(int de_id);
        int getDepartID();
        void setDepartName(string de_na);
        string getDepartName();
        void getData();
        void print();
        virtual ~Department();

    protected:

    private:
        int departID;
        string departName;
};

#endif // DEPARTMENT_H
