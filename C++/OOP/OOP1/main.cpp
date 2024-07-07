#include <iostream>
#include "Contact.h"

using namespace std;
int main (){
    int c = -1;
    // create contact object
    Contact Contact (100) ;
    while (c != 0)
    {
        cout<< "***********************************************\n"
            << "1. Print All Users\n"
            << "2. Add New User\n"
            << "3. Search\n"
            << "4. Edit Existing User\n"
            << "5. Delete Existing User\n"
            << "0. Quit\n"
            << "Enter your choice: ";
        cin >> c;
        cout << "**********************************************\n";

        switch (c)
        {
        case 1:
            Contact. print();
            break;
        case 2:
            Contact. addNewUser();
            break;
        case 3:
            {
                string key;
                cout<<"Enter your keyword to find: ";
                cin. ignore () ;
                getline (cin, key) ;
                Contact .findAll (key) ;
            }
            break;
        case 4:
            {
                int edit_id=0;
                cout<<"Enter user Id to edit: ";
                cin>>edit_id;
                Contact  .editUser (edit_id) ;

            }
            break;
        case 5:
            {
                int del_id=0;
                cout<<"Enter user Id to delete: ";
                cin>>del_id;
                Contact  .deleteUser (del_id) ;

            }
            break;

        }
        cout<< "THANKS"<<endl;
        }
        return 0;
}
