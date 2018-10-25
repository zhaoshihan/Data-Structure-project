// template.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
template <typename T>
void display(T a) {
	cout << a << endl;
}

template <typename Type, int size>
void display(Type element) {
	for (int i = 0; i < size; i++) {
		std::cout << element << endl;
	}
}

template <typename T, class S>
void display(T name, S age) {
	cout << name << " " << age << endl;
}


template <typename T>
void swapping(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}



int main()
{
	//display<char>('B');
	//display<char, 5>('A');
	//display<string, int>("zhangsan", 18);
	int x = 10;
	int y = 20;
	// ����ģ�庯��
	swapping<int>(x, y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	system("pause");
	return 0;
}

