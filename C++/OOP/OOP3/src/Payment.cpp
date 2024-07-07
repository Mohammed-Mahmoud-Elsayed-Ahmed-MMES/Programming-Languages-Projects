#include "Payment.h"

Payment::Payment()
{
    //ctor
}
Payment::Payment(string p_d,double am)
{
    paid_date = p_d;
    amount = am;
}

Credit cr;
Cash ca;
Check ch;
double Payment::pay()
{
    cout<< "How do you want to pay ?"<<endl;
    cout<<"\t 1- Cash  ||  2- Check  ||  3- Credit\n";
    cout << "CHOOSE : ";
    int type;
    cin>>type;
    switch(type)
    {
    case 1:
        ca.getData();
        cout << "Enter Paid Date : ";
        cin >> paid_date;
        break;
    case 2:
        ch.getData();
        cout << "Enter Paid Date : ";
        cin >> paid_date;
        break;
    case 3:
        cr.getData();
        cout << "Enter Paid Date : ";
        cin >> paid_date;
        break;

    }
}
string Payment::update()
{
    bool updated;

    if(updated)
        cout << "\tPAYMENT UPDATED SUCCEFULY\n";
}
void Payment::print()
{
    cout << "Enter the Way you paid with to Know how much you Paid : ";
    int type;
    cin>>type;
    switch(type)
    {
    case 1:
        ca.print();
        cout << "Paid Date : " << paid_date << endl;
        break;
    case 2:
       ch.print();
       cout << "Paid Date : " << paid_date << endl;
       break;
    case 3:
        cr.print();
        cout << "Paid Date : " << paid_date << endl;
        break;
    }
}
ostream&operator <<(ostream &out, Payment &p)
{
    cout << "Enter the Way you paid with to Know how much you Paid : ";
    int type;
    cin>>type;
    switch(type)
    {
    case 1:
        ca.print();
        out << "Paid Date : " << p.paid_date << endl;
        break;
    case 2:
       ch.print();
       out << "Paid Date : " << p.paid_date << endl;
       break;
    case 3:
        cr.print();
        out << "Paid Date : " << p.paid_date << endl;
        break;
    }
}
Payment::~Payment()
{
    //dtor
}
