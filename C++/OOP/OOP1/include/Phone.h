#include <string>
#include <iostream>

using namespace std;
#ifndef PHONE_H
#define PHONE_H


class Phone
{
    private:
        string phone;
        string type;
        string description;

    public:
        Phone();
        Phone(string p,string t,string d);
        virtual ~Phone();

        void setPhone(string p);
        void setType(string t);
        void setDescription(string d);

        bool isMatched(string key) const;

        void print() const;

        string getPhone();
        string getType();
        string getDescription();

};

#endif // PHONE_H
