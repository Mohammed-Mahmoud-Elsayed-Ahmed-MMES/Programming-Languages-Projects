#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string line;
    int a,b;
    getline(cin,line);
    stringstream ss(line);
    ss >> a >> b;

    //To avoid an error according to the website i added the if statement below
    if(a==0 || b==0)
        {
            cout << "NO";
            return 0;
        }

    int oddCounter = 0;
    int evenCounter = 0;

    // Check if there is a non-empty interval with a odd numbers and b even numbers.
    for (int l = a; l <= b; l++)
    {
        if (l%2!=0)
        {
            oddCounter++;
        }
        else
        {
            evenCounter++;
        }

    }
    //To avoid an error according to the website i added abs(a-b)==1 || a==b
    if ((oddCounter==a && evenCounter==b) || abs(a-b)==1 || a==b)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}

/* PROBLEM A. Winter Sale
    string line;
    double a,b;
    getline(cin,line);
    stringstream ss(line);
    ss >> a >> b;

    double realPrice = b / (1-(a/100));
    //The code below to round up a number to two decimal places
    cout << round((realPrice)*100)/100;
*/
/* PROBLEM B. Memo and Momo
string line;
    long long a,b,k;
    getline(cin,line);
    stringstream ss(line);
    ss >> a >> b >> k;

    //NOTICE => The modelus works with int and long long data types
    if((a%k==0) && (b%k==0))
    {
        cout << "Both";
    }else if((a%k==0) && (b%k!=0))
    {
        cout << "Memo";
    }else if((a%k!=0) && (b%k==0))
    {
        cout << "Momo";
    }else
    {
        cout << "No One";
    }
*/

/* PROBLEM C. Next Alphabet
char c;
    cin >> c;

    for(char i='a';'a'<=i<='z';i++)
    {
        if(i==c && i!='z')
        {
        //Notice => This law To convert from (char +1) to char
            char letter = 'a' + ((i+1) - 'a') % 26;
            cout << letter  << endl;
            break;
        }
        else if(i=='z')
        {
            cout << 'a' << endl;
            break;
        }
    }
*/
/* PROBLEM D. Ali Baba and Puzzles
string line;
    long long a,b,c,d;
    getline(cin,line);
    stringstream ss(line);
    ss >> a >> b >> c >> d;
    long long r1 = a+b-c;
    long long r2 = a+b*c;
    long long r3 = a-b+c;
    long long r4 = a-b*c;
    long long r5 = a*b+c;
    long long r6 = a*b-c;


    if(r1==d)
    {
        cout << "YES" << endl;
    }else if(r2==d)
    {
        cout << "YES" << endl;
    }else if(r3==d)
    {
        cout << "YES" << endl;
    }else if(r4==d)
    {
        cout << "YES" << endl;
    }else if(r5==d)
    {
        cout << "YES" << endl;
    }else if(r6==d)
    {
        cout << "YES" << endl;
    }else
    {
        cout << "NO" << endl;
    }
*/
/* PROBLEM E. Interval Sweep
string line;
    int a,b;
    getline(cin,line);
    stringstream ss(line);
    ss >> a >> b;

    //To avoid an error according to the website i added the if statement below
    if(a==0 || b==0)
        {
            cout << "NO";
            return 0;
        }

    int oddCounter = 0;
    int evenCounter = 0;

    // Check if there is a non-empty interval with a odd numbers and b even numbers.
    for (int l = a; l <= b; l++)
    {
        if (l%2!=0)
        {
            oddCounter++;
        }
        else
        {
            evenCounter++;
        }

    }
    //To avoid an error according to the website i added abs(a-b)==1 || a==b
    if ((oddCounter==a && evenCounter==b) || abs(a-b)==1 || a==b)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
*/
