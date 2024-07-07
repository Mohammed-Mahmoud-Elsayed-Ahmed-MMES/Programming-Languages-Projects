#include "Department.h"

Department::Department()
{
    departID = 0;
    departName = " ";

}
Department::Department(int de_id,string de_na)
{
    departID = de_id;
    departName = de_na;

}
void Department::setDepartID(int de_id)
{
    departID = de_id;
}
int Department::getDepartID()
{
    return departID;
}
void Department::setDepartName(string de_na)
{
    departName = de_na;
}
string Department::getDepartName()
{
    return departName;
}
void Department::getData()
{
    cout << "Enter Depart ID : ";
    cin >> departID;
    cout << "Enter Depart Name : ";
    cin >> departName ;

}
void Department::print()
{
    cout << "Depart ID : " << departID << endl;
    cout << "Depart Name : " << departName << endl;

}
Department::~Department()
{
    //dtor
}
