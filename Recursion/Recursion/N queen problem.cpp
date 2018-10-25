#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;
#define N 5


//�����·���Queen������
bool isSafe(int row, int col, int result[N][N])
{

	for (int i =1; i<= col; i++)
	{
		//��������
		int find_col = col - i;
		int find_row = row;
		if (result[find_row][find_col] == 1)
		{
			return false;
		}

		//������϶Խ���
		find_row = row - i;
		if (find_row>=0 && result[find_row][find_col]==1)
		{
			return false;
		}
		//������¶Խ���
		find_row = row + i;
		if (find_row<N && result[find_row][find_col] == 1)
		{
			return false;
		}
	}
	return true;
}

void printResult(int result[N][N])
{
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			printf(" %d ", result[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//��ÿһ��loop����
bool solveQueenUtil(int col, int result[N][N])
{
	if (col==N)
	{
		printResult(result);
		return true;
	}

	for (int row=0; row<N; row++)
	{
		if (isSafe(row, col, result))
		{
			result[row][col] = 1;

			solveQueenUtil(col + 1, result);

			result[row][col] = 0;
			//if (solveQueenUtil(col + 1, result) == true)
			//{
			//	return true;
			//}
			//else
			//{
			//	result[row][col] = 0;
			//}
		}
	}
	return false;
}

//�ݹ���������
void solveQueen()
{
	int result[N][N] = { 0 };
	bool final = false;

	if (solveQueenUtil(0, result) == true)
	{
		/*printf("One of the result is: \n");
		printResult(result);*/
		printf("Here are all possibility");
	}
	else
	{
		printf("There is no solution!!");
	}

}


int main()
{
	solveQueen();

	system("pause");
	return 0;
}