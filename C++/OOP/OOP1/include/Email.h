#include <string>
#include <iostream>

using namespace std;
#ifndef EMAIL_H
#define EMAIL_H


class Email
{
    public:
        Email();
        Email(string e,string t,string d);
        virtual ~Email();

        void setEmail(string e);
        void setType(string t);
        void setDescription(string d);

        bool isMatched(string key) const;

        void print() const;

        string getEmail();
        string getType();
        string getDescription();

    protected:

    private:
        string email;
        string type;
        string description;

};

#endif // EMAIL_H
