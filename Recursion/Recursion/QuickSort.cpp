#include "stdafx.h"
#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/*
	取最后一个为分割点pivot
	j起到遍历的作用，寻找所有比pivot小的数与i交换
	i保证的是：i之前所有的数都比pivot小
	最后放置分割点到i+1位置
	返回的是分割点的位置
*/
int partition(int array[], int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSort(int array[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		//对分割点左右两边再次排序
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

//void printArray(int array[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf(" %d ", array[i]);
//	}
//	printf("\n");
//}

//int main() {
//	int array[] = { 10,7,8,9,1,5 };
//	int n = sizeof(array) / sizeof(array[0]);
//
//	quickSort(array, 0, n - 1);
//	printf("Sorted array is: \n");
//	printArray(array, n);
//
//
//	system("pause");
//	return 0;
//}