#include "Contact.h"

Contact:: Contact(int contact_size)
{
    m_size = contact_size;
    users = new User [m_size] ;
    m_count = 0;
}
Contact::~Contact ()
{
    delete [] users;
}
void Contact:: addNewUser ()
{
    User *new_user = new User () ;
    new_user->setUserId (m_count+1) ;
    new_user->readInput () ;
    users [m_count++] = * new_user;
}
void Contact:: deleteUser (int user_id)
{
    if (m_count==0) {
            cout<<"NO USER EXIST~!\n";
            return;
    }
    bool deleted = false;
    for (int i=0; i<m_count; ++i){
            if (users [i] . getUserId ()== user_id){
                    //delete from array
                    if (i==m_count-1) {
                            m_count--;
                    }else{
                        //replace deleted with last user
                        users [i]= users [m_count-1];
                        m_count--;
                    }
                    deleted = true;
                    break;
            }
    }
    if (deleted){
        cout<<"USER DELETED SUCESSFULLY! \n";
    }else{
        cout <<"NO USER EXIST\n";
    }
}
void Contact::editUser (int user_id)
{
        if (m_count==0) {
            cout<<"NO USER EXIST~!\n";
            return;
    }
    bool edited = false;
    for (int i=0; i<m_count; ++i){
            if (users [i] . getUserId ()== user_id){
                //some process or
                users[i].readInput();
                edited = true;
                break;
            }
    }
    if (edited){
        cout<<"USER EDITED SUCESSFULLY! \n";
    }else{
        cout <<"NO USER EXIST\n";
    }
}
void Contact::print () const
{
    if (m_count ==0) {
            cout << "NO USER FOUND! \n";
            return;
    }
    for (int i=0; i< m_count; ++i) {
            users [i] . print () ;
    }
}
void Contact:: findAll (string key) const
{
    int found_counter=0;
    for (int i=0; i<m_count;++i){
            if (users [i] . findAny (key) ){
                    users [i] .print () ;
                    found_counter++;
            }
    }
    if (found_counter == 0) {
            cout<<"NO USER FOUNDED! \n";
    }else{
        cout<< found_counter << " FOUNDED-\n";
    }

}
