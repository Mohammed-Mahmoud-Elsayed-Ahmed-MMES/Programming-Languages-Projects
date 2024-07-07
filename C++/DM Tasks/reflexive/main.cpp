#include <iostream>

using namespace std;

void transpose(int A[][3],int B[][3],int n)
{
    cout << "Transpose : \n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            B[i][j] = A[j][i];
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
}

//bool isSymmetric(int m,int n,int A[m][n])
bool isReflexive(int A[][3],int n)
{
    cout << "If 1 It is SYMMETRIC , If 0 It is not SYMMETRIC \n";
    int temp[n][3];
    transpose(A,temp,n);
    cout << "--------------------------------\n";
    int j = 0;
    for(int i = 0; i < n && j < n; ++i)
    {
        if((A[i][j] != temp[i][j]) !=  )
            return false;
        ++j;
    }
    return true;
}


int main()
{
    int A[3][3] = {{1,2,3}
        ,{2,1,4}
        ,{3,4,1}
    };
    cout << isReflexive(A,3);
    return 0;
}
