// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	auto const n1 = mid - left + 1; //The reason behind +1 that the n1 is the size of the left array
	//EX : number of indexes in n1 (3-0)=3 so n1(size) = 3+1 = 4 .(0->3)
	auto const n2 = right - mid;
	//EX : number of indexes in n2 (5-3)=2 so n2(size) = 2 .(4->5)

	// Create temp arrays
	auto *leftArray = new int[n1],
		*rightArray = new int[n2];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < n1; i++)
		leftArray[i] = array[left + i]; //For each iteration we will add i to left becuase left is always zero
	for (auto j = 0; j < n2; j++)
		rightArray[j] = array[mid + 1 + j]; //For each iteration we will add j to (mid + 1) becuase (mid + 1) is always keep its index number

	auto i = 0 // Initial index of first sub-array
		,j = 0; // Initial index of second sub-array
	int k = left; // Initial index of merged array

	// Merge and sort descending the temp arrays back into array[left..right]
	while (i < n1 && j < n2) {
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (i < n1) {
		array[k] = leftArray[i];
		i++;
		k++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (j < n2) {
		array[k] = rightArray[j];
		j++;
		k++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid); //We will keep call this function untill dividing can't be continued
	//And then go to next call that under it
	mergeSort(array, mid + 1, end); //We will keep call this function untill dividing can't be continued
	//And then go to next call that under it
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 }; //O(nlogn)
	//int arr[] = { 12, 11, 13, 5, 6, 7 }; O(nlogn)
	//int arr[] = { 12, 11, 13, 5, 6, 7 }; O(nlogn)
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
