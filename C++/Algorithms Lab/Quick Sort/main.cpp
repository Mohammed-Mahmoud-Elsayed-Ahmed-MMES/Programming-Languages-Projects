#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main()
{
    vector<int> arr = { 5, 2, 9, 1, 5, 6 }; //O(n^2)
    //vector<int> arr = { 1, 2, 5, 5, 6, 9 }; O(nlogn)
    //vector<int> arr = { 9, 6, 5, 5, 2, 1 }; O(nlogn)
    quick_sort(arr, 0, arr.size() - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
