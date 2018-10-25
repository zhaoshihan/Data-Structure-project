#pragma once
#ifndef MYSTACK_H_
#define MYSTACK_H_

#include<iostream>
#include<string>
using namespace std;

class MyStack
{
private:
	int * array;
	int * cur_number; //将要入栈的指针
	int * m_pBuffer;  //栈指针
	int m_iSize;  //栈容量
	int m_iTop;  //栈顶，栈中元素个数

public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();  //清空栈
	int stackLength();  //获取当前栈中元素个数
	bool push();
	int pop();
	//bool pop(char &elem);
	void stackTraverse();  //栈的遍历
	void printAll(int=0,int=0,string="");
};

#endif
