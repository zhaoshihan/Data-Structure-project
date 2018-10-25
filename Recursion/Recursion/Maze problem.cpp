#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

//全局定义N=4，可修改
#define N 4

bool isSafe(int maze[N][N], int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
	{
		return true;
	}
	return false;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	if ( x == N-1 && y == N-1)
	{
		sol[x][y] = 1;
		return true;
	}

	if (isSafe(maze,x,y))
	{
		sol[x][y] = 1;
		if (solveMazeUtil(maze, x+1, y, sol) == true)
		{
			return true;
		}

		if (solveMazeUtil(maze, x, y+1, sol) == true)
		{
			return true;
		}

		/* If none of the above movements work then BACKTRACK:
		unmark x,y as part of solution path */
		sol[x][y] = 0;
		return false;
	}
	return false;
}

void printSolution(int sol[N][N])
{
	for (int i=0; i<N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf(" %d ", sol[i][j]);
		}
		printf("\n");
	}
}



bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { 0 };
	if (solveMazeUtil(maze, 0, 0, sol)==false)
	{
		printf("Solution doesn't exist!!\n");
		//printSolution(sol);
		return false;
	}
	else{
		printSolution(sol);
		return true;
	}
}

//int main() {
//	int map[4][4] = { { 1,0,0,0 },{ 1,1,0,1 },{ 0,1,0,0 },{ 1,1,1,1 } };
//	solveMaze(map);
//	
//
//	system("pause");
//	return 0;
//}
