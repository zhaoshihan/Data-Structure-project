#include "stdafx.h"
#include <iostream>

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int array[], int start1, int end1, int end2)
{
	int first, second, merged;
	int length1 = end1 - start1 + 1;
	int length2 = end2 - end1;

	/* create temp arrays */
	int* left_array = new int[length1];
	int* right_array = new int[length2];

	/* Copy data to temp arrays L[] and R[] */
	for (first = 0; first < length1; first++)
		left_array[first] = array[start1 + first];
	for (second = 0; second < length2; second++)
		right_array[second] = array[end1 + 1 + second];

	/* Merge the temp arrays back into arr[l..r]*/
	first = 0; // Initial index of first subarray
	second = 0; // Initial index of second subarray
	merged = start1; // Initial index of merged subarray
	while (first < length1 && second < length2)
	{
		if (left_array[first] <= right_array[second])
		{
			//进行array数据的重新copy back写入
			array[merged] = left_array[first];
			first++;
		}
		else
		{
			array[merged] = right_array[second];
			second++;
		}
		merged++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (first < length1)
	{
		//继续写入尾部
		array[merged] = left_array[first];
		first++;
		merged++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (second < length2)
	{
		array[merged] = right_array[second];
		second++;
		merged++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves 这是左右分割，直到分割到最小单元
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);


		//这是左右合并
		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf(" %d ", array[i]);
	}
	printf("\n");
}

/* Driver program to test above functions */
//int main()
//{
//	int arr[] = { 12, 11, 13, 5, 6, 7 };
//	int arr_size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("Given array is \n");
//	printArray(arr, arr_size);
//
//	mergeSort(arr, 0, arr_size - 1);
//
//	printf("\nSorted array is \n");
//	printArray(arr, arr_size);
//
//	system("pause");
//	return 0;
//}