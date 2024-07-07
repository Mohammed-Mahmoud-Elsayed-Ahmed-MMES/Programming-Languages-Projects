#include "Email.h"

Email::Email()
{

}

Email::~Email()
{

}
Email::Email(string e,string t,string d)
{
    email = e;
    type = t;
    description = d;
}
void Email::setEmail(string e)
{
    email = e;
}
void Email::setType(string t)
{
    type = t;
}
void Email::setDescription(string d)
{
    description = d;
}
string Email::getEmail()
{
    return email;
}
string Email::getType()
{
    return type;
}
string Email::getDescription()
{
    return description;
}
bool Email::isMatched(string key) const
{
    return (email.compare(key)==0);
}
void Email::print() const
{
    cout << "Email : "<< email << "\t && " << type << "\t && "<<description<< endl;
}
