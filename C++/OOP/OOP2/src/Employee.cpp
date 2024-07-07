#include "Employee.h"

Employee::Employee()
{
    socialSecurityNnumber = " ";
}
Employee::Employee(int e_id,string n,string ph,string em,string ssn) : StaffMember(e_id,n,ph,em)
{
    socialSecurityNnumber = ssn;
}
void Employee::getData()
{
    StaffMember::getData();
    cin.ignore();
    cout << "Enter Social Security Number : " ;
    getline(cin,socialSecurityNnumber);
}
string Employee::print()
{
    return StaffMember::print() + "\n Social Security Number is : " + socialSecurityNnumber;
}
Employee::~Employee()
{
    //dtor
}
