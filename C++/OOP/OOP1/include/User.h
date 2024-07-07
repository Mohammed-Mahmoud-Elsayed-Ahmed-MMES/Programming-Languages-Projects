#include <string>
#include <ctime>
#include <iostream>
using namespace std;

#include "phone.h"
#include "email.h"
#include "address.h"
#ifndef USER_H
#define USER_H


class User
{
    public:
        User();
        User(int i,string f_n,string l_n,int ag,int g,time_t add);
        virtual ~User();

        void setUserId (int i) ;
        void setFirstName(string f_n) ;
        void setLastName(string l_n) ;
        void setAge(int ag);
        void setGender (int g) ;
        void setAddedDate (time_t add) ;

        int getUserId();
        string getFirstName();
        string getLastName();
        int getAge();
        int getGender();
        time_t getAddedDate();
        void print () const;
        void readInput () ;


        bool findAny(string key) const;

    protected:

    private:
        int id;
        string first_name;
        string last_name;
        int age;
        int gender;
        time_t addedDate;

        Phone *phones;//pointer من نوع class
        Email *emails;
        Address *addresses;

        int phone_size;
        int address_size;
        int email_size;

        int phone_count;
        int address_count;
        int email_count;

};

#endif // USER_H
