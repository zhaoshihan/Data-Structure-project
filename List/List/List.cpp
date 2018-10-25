// List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	Node* array = new Node[3];
	array[0].setLink(1);
	array[1].setData(10);
	array[1].setLink(2);
	array[2].setData(20);
	array[2].setLink(0);

	int nextIndex = array[0].getLink();
	while (nextIndex != 0)
	{
		printf("next array is: %d \n", array[nextIndex].getData());
		nextIndex = array[nextIndex].getLink();
	}

	system("pause");
    return 0;
}

