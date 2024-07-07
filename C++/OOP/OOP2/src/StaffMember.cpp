#include "StaffMember.h"

StaffMember::StaffMember()
{
    employeeID = 0;
    name = " ";
    phone = " ";
    email = " ";
    m_department = nullptr;
}
StaffMember::StaffMember(int e_id,string n,string ph,string em)
{
    employeeID = e_id;
    name = n;
    phone = ph;
    email = em;
}
void StaffMember::setEmployeeID(int e_id)
{
    employeeID = e_id;
}
int StaffMember::getEmployeeID() const
{
    return employeeID;
}
void StaffMember::getData()
{
    cout << "Enter employee ID : " ;
    cin >> employeeID;
    cin.ignore();
    cout << "Enter Name : " ;
    getline(cin,name);
    cout << "Enter Phone : " ;
    getline(cin,phone);
    cout << "Enter Email : " ;
    getline(cin,email);
}
string StaffMember::print()
{
    return "\n Employee ID : " + to_string(employeeID)+
           " \n Name : " + name+
           " \n Phone : " + phone+
           " \n Email : " + email+
           ((m_department != nullptr)?
                    "\nDepartment name : " + m_department -> getDepartName() //To print the name of department of an employee
                    : " " );
}
double StaffMember::pay()
{

}
StaffMember::~StaffMember()
{
    //dtor
}
