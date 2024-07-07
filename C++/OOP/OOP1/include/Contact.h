#include "User.h"
#include <string>

using namespace std;
#ifndef CONTACT_H
#define CONTACT_H


class Contact
{
    public:
        Contact();
        Contact(int);
        void addNewUser();
        void deleteUser (int) ;
        void editUser (int) ;
        void print () const;
        void findAll (string key) const;
        virtual ~Contact();

    protected:

    private:
        int m_count;
        int m_size;
        User * users; //composition class
};

#endif // CONTACT_H
