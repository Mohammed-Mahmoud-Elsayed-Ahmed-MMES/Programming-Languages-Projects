#include "Staff.h"

Staff::Staff()
{
    staff_member_size = 25;
    staff_member_count = -1;
    staffMembers = new StaffMember*[staff_member_size]; //ARRAY OF POINTER
}
Staff::Staff(int s_m_s)
{
    staff_member_size = s_m_s;
    staff_member_count = -1;
    staffMembers = new StaffMember*[staff_member_size];
}
void Staff::caclPayroll()
{
    cout << "**********EMPLOYEES CALCULATE PAYROLL LIST**********" << endl;
    double total = 0.0;
    for(int i=0; i<= staff_member_count; ++i)
    {
        total=total+staffMembers[i]-> pay();
    }
    cout << "\tTotal : " << total << endl;
}
void Staff::addMember()
{
    int type;
    cout << "Select employee type : " << endl
         << "(1) Volunteer | (2) Salaried Employee | (3) Hourly Employee | (4) Commission Employee | (5) Executive Employee " << endl;
    cin >> type;
    bool newMEmber = true;
    switch(type)
    {
    case 1:
        staffMembers[++staff_member_count] = new Volunteer();
        break;
    case 2:
        staffMembers[++staff_member_count] = new Salaried_Employee();
        break;
    case 3:
        staffMembers[++staff_member_count] = new Hourly_Employee();
        break;
    case 4:
        staffMembers[++staff_member_count] = new Commision_Employee();
        break;
    case 5:
        staffMembers[++staff_member_count] = new Excutive_Employee();
        break;
    default:
        newMEmber = false;
    }
    if(newMEmber)
        staffMembers[staff_member_count] ->getData();

}
int Staff::searchForMember(int employeeID) const
{
    //Search for Employee in List by ID
    for(int i = 0; i <= staff_member_count; i++)
    {
        if(staffMembers[i]->getEmployeeID() == employeeID)
        {
            return i;
        }
    }
    return -1;
}
void Staff::delMember()
{
    int employee_id;
    cout << "Enter Employee ID you want to Delete : " ;
    cin >> employee_id;
    if (staff_member_count == -1)
    {
        cout<<"NO MEMBER EXIST~!\n";
        return;
    }
    bool deleted = false;
    for (int i=0; i <= staff_member_count; ++i)
    {
        if (staffMembers [i] -> getEmployeeID() == employee_id)
        {
            //delete from array
            if (i == staff_member_count-1)
            {
                staff_member_count--;
            }
            else
            {
                //replace deleted with last member
                staffMembers [i]= staffMembers [staff_member_count-1];
                staff_member_count--;
            }
            deleted = true;
            break;
        }
    }
    if (deleted)
    {
        cout<<"MEMBER DELETED SUCESSFULLY! \n";
    }
    else
    {
        cout <<"NO MEMBER EXIST\n";
    }

}

bool Staff::assignDepartmentToEmployeeByID(int employeeID,Department* d)
{
    int em_index = searchForMember(employeeID);
    if (em_index == -1) return false;
     StaffMember* sm = staffMembers[em_index]; //pointer object refers to pointer to pointer object
     sm -> setDepartment(d);//To access the data that stored in department
}

void Staff::showAll()
{
    cout << "**********EMPLOYEES LIST**********" << endl;
    for(int i=0; i<= staff_member_count; ++i)
    {
        cout << (i+1) << " : "<< staffMembers[i]->print() << endl;
    }
}
Staff::~Staff()
{
    for(int i = 0; i <= staff_member_count; ++i)
        delete staffMembers[i];//BELONGS TO (new) ADDMEMBER
    //FOR EACH ITEM IN ARRAY DELETE IT POINTER

    delete []staffMembers;//BELONGS TO (new) of CONSTRUCTOR
    //DELETE ARRAY OF POINTERS
}
