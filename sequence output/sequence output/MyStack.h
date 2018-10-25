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
	int * cur_number; //��Ҫ��ջ��ָ��
	int * m_pBuffer;  //ջָ��
	int m_iSize;  //ջ����
	int m_iTop;  //ջ����ջ��Ԫ�ظ���

public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();  //���ջ
	int stackLength();  //��ȡ��ǰջ��Ԫ�ظ���
	bool push();
	int pop();
	//bool pop(char &elem);
	void stackTraverse();  //ջ�ı���
	void printAll(int=0,int=0,string="");
};

#endif
