#include "stdafx.h"
#include <iostream>

using namespace std;


int Fibonacci(int n, int array[])
{
	if (n == 0)
	{
		array[0] = 0;
		return array[0];
	}
	else if (n == 1)
	{
		array[1] = 1;
		return array[1];
	}
	else {
		if (array[n] == -1)
		{
			array[n] = Fibonacci(n - 1, array) + Fibonacci(n - 2, array);
		}
		return array[n];
	}
}

void printAll(int n, int array[])
{
	for (int i = 0; i < n+1; i++)
	{
		printf("%d,  ", array[i]);
	}
	printf("\n");
}

//int main() {
//	const int N = 30;
//	int array[N+1];
//	for (int i = 0; i < N+1; i++)
//	{
//		array[i] = -1;
//	}
//	Fibonacci(N, array);
//	printAll(N, array);
//
//	//cout << Fibonacci(N, array)<<endl;
//	system("pause");
//	return 0;
//}