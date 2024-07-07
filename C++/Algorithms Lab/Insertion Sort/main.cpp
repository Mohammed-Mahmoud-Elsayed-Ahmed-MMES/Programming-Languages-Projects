// C++ program for insertion sort

#include <bits/stdc++.h>
using namespace std;

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
	int m1, m2, temp;
	for (m1 = 1; i < n; i++)
	{
		temp = arr[m1];
		j = i - 1;

		while (m2 >= 0 && arr[m2] > temp)
		{
			arr[m2 + 1] = arr[m2];
			m2--;
		}
		arr[m2 + 1] = temp;
	}
}

// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 }; //O(n^2)
	//int arr[] = { 5, 6, 11, 12, 13 }; //O(n)
	//int arr[] = { 13, 12, 11, 6, 5 }; //O(n^2)
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);

	return 0;
}
// This is code is contributed by rathbhupendra
