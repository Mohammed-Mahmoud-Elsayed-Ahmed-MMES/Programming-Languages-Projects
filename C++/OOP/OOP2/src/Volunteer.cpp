#include "Volunteer.h"

Volunteer::Volunteer()
{
    amount = 0;
}
Volunteer::Volunteer(int e_id,string n,string ph,string em,int am) : StaffMember(e_id,n,ph,em)
{
    amount = am;
}
void Volunteer::getData()
{
    StaffMember::getData();

    cout << "Enter Amount : ";
    cin >> amount;
}
string Volunteer::print()
{
    return StaffMember::print() + "\n Amount : " + to_string(amount) ;
}
double Volunteer::pay()
{
    return amount;
}
Volunteer::~Volunteer()
{
    //dtor
}
