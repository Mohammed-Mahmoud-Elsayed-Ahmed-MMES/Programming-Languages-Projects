#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);//make a=b and b=(r=a%b)
}

int lcd(int a,int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int a, b;
    cout << "Enter A : " ;
    cin >> a;
    cout << "Enter B : " ;
    cin >> b;
    cout << "GCD : " << gcd(a,b)<<endl;
    cout << "LCD : " << lcd(a,b) << endl;
    return 0;
}
