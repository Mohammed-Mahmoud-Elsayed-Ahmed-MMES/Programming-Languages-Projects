#include "User.h"

User::User()
{
    phone_size = 5;
    email_size = 5;
    address_size = 5;

    phones = new Phone[phone_size];
    emails = new Email[email_size];
    addresses = new Address[address_size];

    phone_count = 0;
    email_count = 0;
    address_count = 0;

    addedDate = time(0);
    age = 0;
    gender = 0;
}

User::~User()
{
    delete [] phones;
    delete [] addresses;
    delete [] emails;
}
void User::setUserId (int i)
{
    id = i;
}
void User::setFirstName(string f_n)
{
    first_name = f_n;
}
void User::setLastName(string l_n)
{
    last_name = l_n;
}
void User::setAge(int ag)
{
    age = ag;
}
void User::setGender (int g)
{
    gender = g;
}
void User::setAddedDate (time_t add)
{
    addedDate = add;
}

int User::getUserId()
{
    return id;
}
string User::getFirstName()
{
    return first_name;
}
string User::getLastName()
{
    return last_name;
}
int User::getAge()
{
    return age;
}
int User::getGender()
{
    return gender;
}
time_t User::getAddedDate()
{
    return addedDate;
}
void User::print () const
{
    cout << "--------------------------------------------------\n";
    cout << "ID : " << id << "\tNAME : " << first_name << " " << last_name << "\t";
    if (age > 0)
        cout << "AGE : " << age << "\t";
    cout << (gender==0? "MALE": "FEMALE");
    cout << endl;
    if (phone_count>0)
        cout << "\tPHONE LIST : \n";
        for (int i = 0;i < phone_count;++i)
        {
            cout << "\t" << i+1 << "-";
            phones[i].print();
        }
    if (email_count>0)
        cout << "\tEMAIL LIST : \n";
        for (int i = 0;i < email_count;++i)
        {
            cout << "\t" << i+1 << "-";
            emails[i].print();
        }
    if (address_count>0)
        cout << "\t ADDRESSES LIST : \n";
        for (int i = 0;i < address_count;++i)
        {
            cout << "\t" << i+1 << "-";
            addresses[i].print();
        }
    cout << endl;
}
void User::readInput ()
{
    cout<< "Enter User Information:-\n";
    cout<<"First Name: ";
    cin. ignore () ;
    getline (cin , first_name) ;

    cout<<"Last Name: ";
    cin. ignore () ;
    getline (cin, last_name) ;

    cout << "Age: ";
    cin >> age;

    cout << "Gender (0-Male, 1-Female) :";
    cin >> gender;

    int n=0;
    cout<< "How many Phones (0-"<< phone_size <<") ?";
    cin >> n;
    cin. ignore () ;
    for (int i=0; i<n;++i)
    {
        cout << "-----------------"<<endl;
        string data, type, desc;
        cout << "PHONE NUMBER (" << i+1 << ") : ";
        getline (cin, data);
        cout <<"Type :";
        getline (cin, type);
        cout<<"Description :";
        getline (cin, desc) ;

        //create new phone object
        Phone  *new_phone = new Phone (data, type, desc);

        //store to phone array
        phones [phone_count++]= *new_phone;
   }

   cout<< "How many Emails (0-"<< email_size <<") ?";
   cin >> n;
   cin. ignore () ;
   for (int i=0; i<n;++i)
    {
        cout << "-----------------"<<endl;
        string data, type, desc;
        cout << "EMAIL (" << i+1 << ") : ";
        getline (cin, data);
        cout <<"Type :";
        getline (cin, type);
        cout<<"Description :";
        getline (cin, desc) ;

        //create new Eail object
        Email  *new_email = new Email (data, type, desc);

        //store to Email array
        emails [email_count++]= *new_email;
    }


    cout<< "How many Adresses (0-"<< address_size <<") ?";
    cin >> n;
    cin. ignore () ;
    for (int i=0; i<n;++i)
    {
        cout << "-----------------"<<endl;
        string data, type, desc;
        cout << "ADDRESS (" << i+1 << ") : ";
        getline (cin, data);
        cout <<"Type :";
        getline (cin, type);
        cout<<"Description :";
        getline (cin, desc) ;

        //create new phone object
        Address  *new_address = new Address (data, type, desc);

        //store to phone array
        addresses [address_count++]= *new_address;
    }

}

bool User::findAny(string key) const
{
    if (first_name.compare(key) == 0 || last_name.compare(key) == 0)
    {
        return true;
    }
    if (phone_count > 0)
    {
        for (int i = 0;i < phone_count;++i)
        {
            if (phones[i].isMatched(key))
                return true;
        }
    }
    if (email_count > 0)
    {
        for (int i = 0;i < email_count;++i)
        {
            if (emails[i].isMatched(key))
                return true;
        }
    }
    if (address_count > 0)
    {
        for (int i = 0;i < address_count;++i)
        {
            if (addresses[i].isMatched(key))
                return true;
        }
    }
    return false;

}



