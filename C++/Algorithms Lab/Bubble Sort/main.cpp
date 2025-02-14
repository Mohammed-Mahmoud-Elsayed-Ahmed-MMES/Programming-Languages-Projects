#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j,c;
    bool swapped;
    for (i = 0; i <= n-1; i++)
    {
        swapped = false;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            c++;
        }

        // IF no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
    cout << "Counter: " << c << endl;
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout <<" "<< arr[i];
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; //O(n^2)
    //int arr[] = {11, 12, 22, 25, 34, 64, 90}; O(n)
    //int arr[] = {90, 64, 34, 25, 22, 12, 11}; O(n^2)
    int N = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, N);
    cout <<"Sorted array: \n";
    printArray(arr, N);
    return 0;
}
