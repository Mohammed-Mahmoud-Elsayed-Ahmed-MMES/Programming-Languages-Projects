#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include "Customer.h"
#include "Person.h"
#include "Company.h"

class Customers
{
    public:
        Customers();
        Customers(int cu_s);

        void addCustomer();
        bool searchForCustomer(int customerID)const;
        void updateCustomer(int customer_id);
        void deletCustomer(int customer_id);
        virtual void print();

        friend ostream&operator<<(ostream&out,Customers&cus);
        friend istream&operator>>(istream&in,Customers&cus);

        virtual ~Customers();

    protected:

    private:
        int count;
        int customer_size;
        int customer_count;
        Customer* customers;
};

#endif // CUSTOMERS_H
