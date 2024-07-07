#include "Phone.h"

Phone::Phone()
{

}

Phone::~Phone()
{

}
Phone::Phone(string p,string t,string d)
{
    phone = p;
    type = t;
    description = d;
}
void Phone::setPhone(string p)
{
    phone = p;
}
void Phone::setType(string t)
{
    type = t;
}
void Phone::setDescription(string d)
{
    description = d;
}
string Phone::getPhone()
{
    return phone;
}
string Phone::getType()
{
    return type;
}
string Phone::getDescription()
{
    return description;
}
bool Phone::isMatched(string key) const
{
    return (phone.compare(key)==0);
}
void Phone::print() const
{
    cout << "Phone : "<< phone << "\t && " << type << "\t && "<<description<< endl;
}



