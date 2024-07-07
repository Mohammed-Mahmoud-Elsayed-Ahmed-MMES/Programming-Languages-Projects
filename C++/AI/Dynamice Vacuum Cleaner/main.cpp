#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
using namespace std;

enum Status
{
    Clean,Dirty
};

enum Actions
{
    Nothing,MOVE_LEFT,MOVE_RIGHT,SUCK
};

class Environment
{
private :
    vector<int> locations ;
    int numberOfLocations;


public:
    Environment(int n)

    {
        locations.resize(n);//Do resize to the vector
        numberOfLocations = n;
        SetEnvr();
    }

    void SetEnvr()
    {
        int ran;
        for(int i = 0; i < numberOfLocations; i++)
        {
            ran = rand() % 10;
            if (ran<5)
            {
                locations [i]  = Clean;
            }
            else
            {
                locations[i] = Dirty;
            }

        }
    }

    int GetStatus(int location)
    {
        return locations[location];
    }

    void SetStatus(int location,int status )
    {
        locations[location] = status;
    }

    void PrintStatus(int agentLoaction)
    {

        cout<<"==========Environment Status========="<<endl;
        for(int i = 0; i < numberOfLocations; i++)
        {
            if (GetStatus(i)==Dirty)
            {
                cout<<"Status of location " << i+1 << " is Dirty"<<endl;
            }
            else
            {
                cout<<"Status of location "<< i+1 <<" is Clean"<<endl;
            }
        }
        cout << "Vacuum in location " << agentLoaction+1 << endl;
    }


};

class Agent
{
private:
    int numOfLoction;
public :
    Agent(int n)
    {
        numOfLoction = n;
    }
    int ReflexiveVacuum(int location, int status)
    {
        if (status == Dirty)
            return SUCK;
        else if (location == 0 )
            return  MOVE_RIGHT;
        else if(location == (numOfLoction-1))
            return MOVE_LEFT;
        else
        {
            int ran = rand() % 2;
            if(ran == 1)
            {
                return MOVE_RIGHT;
            }
            else
            {
                return MOVE_LEFT;
            }
        }

    }
};
int main()
{
    int numOfLoction;
    cout << "Enter number of location : " ;
    cin >> numOfLoction;
    Environment e(numOfLoction) ;
    Agent a(numOfLoction);

    int currentLocation = 0;
    int agentAction;

    for (int counter=0; counter<30; counter++) //while (true)
    {
        e.PrintStatus (currentLocation);
        bool flag = true;
        for(int i = 0; i < numOfLoction; i++)
        {
            if (e.GetStatus(i) == Clean)
            {
                flag = false;
            }
            else
            {
                flag = true;
            }

        }
        if(flag == false)
        {
            cout << "Next action is Nothing " << endl;
            e.SetEnvr();//To create new environment
        }
        else
        {
            agentAction = a.ReflexiveVacuum ( currentLocation,e.GetStatus (currentLocation) );

            if ( agentAction == SUCK )
            {
                cout << " Next action is SUCK " << endl;
                e.SetStatus (currentLocation,Clean);
            }
            else if ( agentAction == MOVE_RIGHT )
            {
                cout << "Next action is MOVE_RIGHT " << endl;
                currentLocation++;
            }
            else
            {
                cout << "Next action is MOVE_LEFT " << endl;
                currentLocation--;
            }

        }
        cout << endl << endl;

        //getch();

    }
    _sleep(500);
    cout << endl;
}
