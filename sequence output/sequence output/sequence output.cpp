// sequence output.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "MyStack.h"
using namespace std;

int main()
{
	int num;
	cout << "The in-stack order are 1,2,3,......,n. \nplease input n's value: ";
	cin >> num;

	MyStack * pStack = new MyStack(num);

	cout << "\nAll the possible out-stack order: \n";
	pStack->printAll();

	system("pause");
    return 0;
}



