#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;


class Customer
{
    public:
        Customer();
        Customer(int i_cu,string ph);
        void setCustomerID(int i_cu){customerID = i_cu;};
        int getCustomerID(){return customerID;};
        void getData();
        friend ostream&operator<<(ostream&out,Customer&cu);
        friend istream&operator>>(istream&in,Customer&cu);
        virtual string print();
        virtual ~Customer();

    protected:


    private:
        int customerID;
        string phone;
};

#endif // CUSTOMER_H
