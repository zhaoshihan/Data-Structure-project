#include "stdafx.h"
#include <iostream>

using namespace std;

void TopDownMergeSort(int A[], int B[], int n);
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[]);
void CopyArray(int A[], int iBegin, int iEnd, int B[]);

void showArray(int N, int array[])
{
	for (int i=0; i<N; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

//int main() {
//	const int N = 7;
//	int array[N] = { 10, 80, 30, 90, 40, 50, 70 };
//	int arrayCopy[N] = { 0 };
//
//	TopDownMergeSort(array, arrayCopy, N);
//	showArray(N, array);
//
//	system("pause");
//	return 0;
//}


// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int A[], int B[], int n)
{
	CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
	TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

// Sort the given run of array A[] using array B[] as a source.
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
	if (iEnd - iBegin < 2)                       // if run size == 1
		return;                                 //   consider it sorted
												// split the run longer than 1 item into halves
	int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
													// recursively sort both runs from array A[] into B[]
	TopDownSplitMerge(A, iBegin, iMiddle, B);  // sort the left  run
	TopDownSplitMerge(A, iMiddle, iEnd, B);  // sort the right run
											 // merge the resulting runs from array B[] into A[]
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i = iBegin;
	int j = iMiddle;

	// While there are elements in the left or right runs...
	for (int k = iBegin; k < iEnd; k++) {
		// If left run head exists and is <= existing right run head.
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
			B[k] = A[i];
			i = i + 1;
		}
		else {
			B[k] = A[j];
			j = j + 1;
		}
	}
}

//将A数组复制给B数组
void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
	for (int k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}