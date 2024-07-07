#include <string>
#include <iostream>

using namespace std;
#ifndef ADDRESS_H
#define ADDRESS_H


class Address
{
    public:
        Address();
        Address(string a,string t,string d);
        void setAddress(string a);
        void setType(string t);
        void setDescription(string d);

        string getAddress();
        string getType();
        string getDescription();

        bool isMatched(string key) const;
        void print() const;

        virtual ~Address();

    protected:

    private:
        string address;
        string type;
        string description;
};

#endif // ADDRESS_H
