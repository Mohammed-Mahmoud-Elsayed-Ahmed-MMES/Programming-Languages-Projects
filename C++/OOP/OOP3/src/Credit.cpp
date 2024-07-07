#include "Credit.h"

Credit::Credit()
{
    //ctor
}
Credit::Credit(string cr_nu,string ex_da,string cr_ty)
{
    creditNumber = cr_nu;
    expireDate = ex_da;
    creditType = cr_ty;
}
void Credit::getData()
{
    cin.ignore();
    cout<<"Enter your Credit number : ";
    getline(cin,creditNumber);
    cout<<"Enter The Expire date : ";
    getline(cin,expireDate);
    cout<<"Enter The Credit type : ";
    getline(cin,creditType);
}
string Credit::print()
{
    return "\nCredit Number : " + creditNumber +
           "\nExpire Date : " + expireDate +
           "\nCredit Type : " + creditType ;
}
Credit::~Credit()
{
    //dtor
}
