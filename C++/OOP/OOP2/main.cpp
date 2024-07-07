#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "Staff.h"
#include "Department.h"
#include "StaffMember.h"
#include "Employee.h"
#include "Volunteer.h"
#include "Salaried Employee.h"
#include "Hourly Employee.h"
#include "Commision Employee.h"
#include "Excutive Employee.h"
#include "Budget.h"
#include "Project.h"

using namespace std;

//DEPARTMENT DATA
int department_size = 5;
int department_count = 0;
Department* departments = new Department[department_size];//To point to the data that ENTERED , store and To print it in order
void handle_department()
{
    Department d;
    system("cls");
    int c = 1;
    while(c!=0)
    {
        cout<< "----------------------------------------------------------------------\n"
            << "\t 1. Add New Department\n"
            << "\t 2. Print All Department\n"
            << "\t 3. Return to main menu\n"
            << "----------------------------------------------------------------------\n";
        cout << "\t Choose in Department : ";
        cin >> c;
        cout << "\t    #############\n";

        switch(c)
        {
        case 1:
            cout << "Add New Department........" << endl;
            if(department_count < department_size)
            {
                departments[department_count++].getData();
            }else{
                cout << "No more room for department! \n";
            }
            break;
        case 2:
            cout << "**********DEPARTMENT LIST**********" << endl;
            for (int i = 0 ; i < department_count; ++i)
            {
                cout << (i+1) << " : " ;
                departments[i].print();
                cout << endl;
            }
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice, try again!"<< endl;
            Sleep(3000);
        }
    }
}
Staff s(100);
void handle_staff ()
{
    system("cls");

    int c = 1;
    while(c!=0)
    {

        cout<< "-----------------------------------------------------------------------------\n"
            << "\t 1. Add New Member\n"
            << "\t 2. Print All Members\n"
            << "\t 3. Calculate Payroll\n"
            << "\t 4. Assign Member To Department\n"
            << "\t 5. Delete Member\n"
            << "\t 6. Return to main menu\n"
            << "-----------------------------------------------------------------------------\n";
        cout << "\t Choose in Staff : ";
        cin >> c;
        cout << "\t  ##########\n";

        switch(c)
        {
        case 1:
            s.addMember();
            break;
        case 2:
            s.showAll();
            break;
        case 3:
            s.caclPayroll();
            break;
        case 4:
            {
                int depart_ID = -1;
                cout << "Enter Department ID : ";
                cin >> depart_ID;

                //Search For ID Inside Array Of Department
                int depart_index = -1;
                for (int i = 0; i < department_count;++i)
                {
                    if (departments[i].getDepartID() == depart_ID)
                    {
                        depart_index = i;
                        break;
                    }
                }
                if (depart_index == -1)
                {
                    cout << "Department not Found ,TRY AGAIN!!! "<< endl;
                    break;
                }else{
                    int employeeID = -1;
                    cout << "Enter Employee ID : ";
                    cin >> employeeID;

                    bool assignedSuccess = s.assignDepartmentToEmployeeByID(employeeID,departments+depart_index);
                    if (assignedSuccess)
                    {
                        cout << "Successfully Assign Employee To Department" << endl;
                    }else{
                        cout << "Employee ID not Found,TRY AGAIN!!!" << endl;
                    }
                }
            }
            break;
        case 5:
            s.delMember();
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice, try again!"<< endl;
            Sleep(3000);
        }
    }
}
//PROJECT DATA
int project_size = 5;
int project_count = 0;
Project* projects = new Project[project_size];
void  handle_project ()
{
    system("cls");
    Project p;
    Budget b;
    int c = 1;
    while(c!=0)
    {

        cout<< "-----------------------------------------------------------------------------\n"
            << "\t 1. Add New Project\n"
            << "\t 2. Print All Project\n"
            << "\t 3. Add Budget To Existing Project\n"
            << "\t 4. Increase Budget to Existing Project\n"
            << "\t 5. Return to main menu\n"
            << "-----------------------------------------------------------------------------\n";
        cout << "\t Choose in project : ";
        cin >> c;
        cout << "\t   ############\n";

        switch(c)
        {
        case 1:
            if(project_count < project_size)
            {
                projects[project_count++].getData();
            }else{
                cout << "No more room for projects!! \n";
            }
            break;
        case 2:
            cout << "**********PROJECTS LIST**********" << endl;
            for (int i = 0 ; i < project_count; ++i)
            {
                cout << (i+1) << " : " ;
                projects[i].print();
                cout << endl;
            }

            break;
        case 3:
            {
            int projectId = -1;
            cout << "Enter Project ID : ";
            cin >> projectId;

            //Search For ID Inside Array Of Department
            int project_index = -1;
            for (int i = 0; i < project_count; ++i)
            {
                if (projects[i].getProjectID() == projectId)
                    {
                        project_index = i;
                        break;
                    }
            }
            if (project_index == -1)
            {
                cout << "Project not Found ,TRY AGAIN!!! "<< endl;
                break;
            }
            else
            {
                p.addBudget();
                break;
            }
            }
        case 4:
        {
            int projectId = -1;
            cout << "Enter Project ID : ";
            cin >> projectId;

            //Search For ID Inside Array Of Department
            int project_index = -1;
            for (int i = 0; i < project_count; ++i)
            {
                if (projects[i].getProjectID() == projectId)
                    {
                        project_index = i;
                        break;
                    }
            }
            if (project_index == -1)
            {
                cout << "Project not Found ,TRY AGAIN!!! "<< endl;
                break;
            }
            else
            {
                int amount = 0;
                cout<<"Enter Amount to increase : ";
                cin>>amount;
                break;
            }
        }
        case 5:
            return;
        default:
            cout << "Invalid choice, try again!"<< endl;
            Sleep(3000);

        }
    }
}
int main ()
{
    int c = 1;
    while (c!=0)
    {
        cout <<"Where you want to go......." << endl ;
        cout <<"\t 1. Department File" << endl;
        cout <<"\t 2. Staff File" << endl;
        cout <<"\t 3. Project File"<< endl;
        cout <<"\t 0. Exit Application"<< endl ;
        cout <<"Enter Selection: "<< endl ;
        cin >> c;
        switch (c)
        {
        case 1:
            handle_department () ;
            break;
        case 2:
            handle_staff () ;

            break;
        case 3:
            handle_project () ;
            break;
        case 0:
            //Exit application
            cout <<  "\n\n\t\t\tThanks .......:) \n\n" << endl ;
            return 0;
        default:
            cout << "Invalid choice, try again!"<< endl;
            Sleep(3000);
        }
    }
    return 0;
}

/*int main()
{
    int c = -1;
    Department d;
    Staff s(100);
    Project p;
    Budget b;
    while (c != 0)
    {
        cout<< "-------------------------------------\n"
            << "1. Department\n"
            << "2. Staff\n"
            << "3. Project\n"
            << "0. Quiet\n"
            << "Enter your choice: ";
        cin >> c;
        cout << "-------------------------------------\n";
        if(c == 1)
        {
            int a;
            cout<< "-------------------------------------\n"
                << "1. Add New Department\n"
                << "2. Print All Department\n"
                << "----------------------------------------\n";
            cout << "\t Choose in Department : ";
            cin >> a;
            switch(a)
            {
            case 1:
                 cout << "Add New Department........" << endl;
                 if(department_count < department_size)
                    {
                        departments[department_count++].getData();
                        }else{
                            cout << "No more room for department! \n";
                            }
                break;
            case 2:
                cout << "**********DEPARTMENT LIST**********" << endl;
                for (int i = 0 ; i < department_count; ++i)
                    {
                        cout << (i+1) << " : " ;
                        departments[i].print();
                        cout << endl;
                    }
        }
    }
        else if(c == 2)
        {
            int b;
             cout<< "-----------------------------------------------------------------------------\n"
            << "\t 1. Add New Member\n"
            << "\t 2. Print All Members\n"
            << "\t 3. Calculate Payroll\n"
            << "\t 4. Assign Member To Department\n"
            << "\t 5. Delete Member\n"
            << "\t 6. Return to main menu\n"
            << "-----------------------------------------------------------------------------\n";
            cout << "\t Choose in Staff : ";
            cin >> b;
            cout << "\t  ##########\n";

            switch(b)
            {
            case 1:
                s.addMember();
                break;
            case 2:
                //cout << "\t EMPLOYEES LIST " << endl;
                s.showAll();
                break;
            case 3:
                s.caclPayroll();
                break;
            case 4:
            {
                int depart_ID = -1;
                cout << "Enter Department ID : ";
                cin >> depart_ID;

                int depart_index = -1;
                for (int i = 0; i < department_count;++i)
                {
                    if (departments[i].getDepartID() == depart_ID)
                    {
                        depart_index = i;
                        break;
                    }
                    if (depart_index == -1)
                    {
                        cout << "Department not Found ,TRY AGAIN!!! "<< endl;
                        break;
                    }else{
                        int employeeID = -1;
                        cout << "Enter Employee ID : ";
                        cin >> employeeID;

                        bool assignedSuccess = s.assignDepartmentToEmployeeByID(employeeID,departments+depart_index);
                        if (assignedSuccess)
                        {
                            cout << "Successfully Assign Employee To Department" << endl;
                        }else{
                            cout << "Employee ID not Found,TRY AGAIN!!!" << endl;
                        }
                    }
                }

            }
            case 5:
                s.delMember();
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice, try again!"<< endl;
                Sleep(3000);
            }
        }
        else if(c == 3)
        {
            int d;
            cout<< "-------------------------------------\n"
                << "1. Add New Project\n"
                << "2. Print All Project\n"
                << "3. Add Budget To Existing Project\n"
                << "4. Increase Budget to Existing Project\n"
                << "----------------------------------------\n";
            cout << "\t Choose in project : ";
            cin >> d;
            switch(d)
            {
            case 1:
                if(project_count < project_size)
            {
                projects[project_count++].getData();
            }else{
                cout << "No more room for projects!! \n";
            }
            break;
        case 2:
            cout << "**********PROJECTS LIST**********" << endl;
            for (int i = 0 ; i < project_count; ++i)
            {
                cout << (i+1) << " : " ;
                projects[i].print();
                cout << endl;
            }
            break;
            case 3:
                p.addBudget();
                break;
            case 4:
                int amount = 0;
                cout<<"Enter Amount to increase : "<<endl;
                cin>>amount;
                break;

            }
        }
        else if(c == 0)
        {
            cout << "BYE \n";
        }
    }

    return 0;
}*/

