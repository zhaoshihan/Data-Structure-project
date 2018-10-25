// Queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyQueue.h"
#include <iostream>
#include <string>

using namespace std;

struct Customer
{
public:
	Customer(string name, int age) {
		this->name = name;
		this->age = age;
	};
	Customer() {};  //�������������ڴ�ռ�
	void printinfo() const {
		cout << "This name is: " << name << "\tThis age is: " << age << endl;

	};
private:
	string name;
	int age;
};


int main()
{
	MyQueue<Customer>* queue = new MyQueue<Customer>(4);
	queue->EnQueue(Customer("zhangsan", 12));
	queue->EnQueue(Customer("lisi", 20));
	queue->EnQueue(Customer("wangwu", 18));
	queue->EnQueue(Customer("zhaoliu", 22));
	queue->QueueTraverse();


	delete queue;
	queue = nullptr;

	system("pause");
    return 0;
}

