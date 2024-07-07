#include "Customers.h"

Customers::Customers()
{
    count = 0;
    customer_size = 25;
    customer_count = 0;
    customers = new Customer[customer_size]; //ARRAY OF POINTER
}
Customers::Customers(int cu_s)
{
    customer_size = cu_s;
    customer_count = 0;
    customers = new Customer[customer_size];
}

void Customers::addCustomer()
{
    Customer* new_customer = new Customer();
    new_customer->getData();
    customers[customer_count++] = *new_customer;
    /*int type;
    cout << "Select Customer type : " << endl
         << "(1) Company | (2) Person " << endl;
    cin >> type;
    bool newMEmber = true;
    switch(type)
    {
    case 1:
        customers[++customer_count] = new Company();
        break;
    case 2:
        customers[++customer_count] = new Person();
        break;
    default:
        newMEmber = false;
    }
    if(newMEmber)
        customers[customer_count] ->getData();*/
}
bool Customers::searchForCustomer(int customerID) const
{
    //Search for Employee in List by ID
    for(int i = 0; i < customer_count; i++)
    {
        if(customers[i].getCustomerID() == customerID)
        {
            return true;
        }
    }
    return false;
}
void Customers::updateCustomer(int customer_id)
{
    /*int customerID;
    cout << "Enter Employee ID you want to Delete : " ;
    cin >> customerID;

    int customer_index = searchForCustomer(customerID);
    bool updated = false;
    if(customer_index >= 0)
    {
        for(int i = 0; i <= customer_count; ++i)
        {
            customers[i]->getData();
            updated = true;
            break;
        }

    }
    if (updated)
    {
        cout<<"CUSTOMER UPDATED SUCESSFULLY! \n";
    }
    else
    {
        cout <<"NO CUSTOMER EXIST\n";
    }*/
    if (customer_count == 0)
    {
        cout<<"NO CUSTOMER EXIST~!\n";
        return;
    }
    bool updated = false;
    for (int i=0; i< customer_count; ++i)
    {
        if (customers [i] . getCustomerID ()== customer_id )
        {
            //some process or
            customers[i].getData();
            updated = true;
            break;
        }
    }
    if (updated)
    {
        cout<<"CUSTOMER UPDATED SUCESSFULLY! \n";
    }
    else
    {
        cout <<"NO CUSTOMER EXIST\n";
    }
}

void Customers::deletCustomer(int customer_id)
{
    /*int customer_id;
    cout << "Enter Employee ID you want to Delete : " ;
    cin >> customer_id;*/
    if (customer_count == 0)
    {
        cout<<"NO CUSTOMER EXIST~!\n";
        return;
    }
    bool deleted = false;
    for (int i=0; i < customer_count; ++i)
    {
        if (customers [i] . getCustomerID() == customer_id)
        {
            //delete from array
            if (i == customer_count-1)
            {
                customer_count--;
            }
            else
            {
                //replace deleted with last member
                customers [i]= customers [customer_count--];
                customer_count--;
            }
            deleted = true;
            break;
        }
    }
    if (deleted)
    {
        cout<<"CUSTOMER DELETED SUCESSFULLY! \n";
    }
    else
    {
        cout <<"NO CUSTOMER EXIST\n";
    }
}
void Customers::print()
{
    for(int i=0; i< customer_count; ++i)
    {
        cout << customers[i].print() << endl;
    }
}
ostream&operator<<(ostream&out,Customers&cus)
{
    cus.print();
    return out;
}
istream&operator>>(istream&in,Customers&cus)
{
    cus.addCustomer();
    return in;
}
Customers::~Customers()
{
    delete [] customers;
}
