#include "Address.h"

Address::Address()
{

}

Address::~Address()
{

}
Address::Address(string a,string t,string d)
{
    address = a;
    type =t;
    description = d;
}
void Address::setAddress(string a)
{
    address = a;
}
void Address::setType(string t)
{
    type = t;
}
void Address::setDescription(string d)
{
    description = d;
}

string Address::getAddress()
{
    return address;
}
string Address::getType()
{
    return type;
}
string Address::getDescription()
{
    return description;
}

bool Address::isMatched(string key) const
{
    return (address.compare(key)==0);
}
void Address::print() const
{
    cout << "Address : "<< address << "\t && " << type << "\t && "<<description<< endl;
}






