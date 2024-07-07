#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;  // target not found in arr
}

int main()
{
    vector<int> arr = { 1, 3, 5, 7, 9 }; //O(logn)
    int target = 5;
    int index = binary_search(arr, target);
    if (index == -1)
    {
        cout << "Target not found in array" << endl;
    }
    else
    {
        cout << "Target found at index " << index << endl;
    }
    return 0;
}
