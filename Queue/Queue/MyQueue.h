#pragma once
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

template<typename Type>
class MyQueue
{
public:
	MyQueue(int queueCapacity);  //�������ζ���
	virtual ~MyQueue();
	void ClearQueue();  //��ն���
	bool QueueEmpty() const;  //�ж϶����Ƿ�Ϊ��
	bool QueueFull() const;
	int QueueLength() const;  //���г��������޸Ĳ�������˼�const
	bool EnQueue(Type element);  //��Ԫ�����
	bool DeQueue(Type &element);  //��Ԫ�س���
	void QueueTraverse();

private:
	Type* m_pQueue;  //��������ָ��
	int m_iQueueLen;  //����Ԫ�ظ���
	int m_iQueueCapacity;  //������������

	int m_iHead;  //��ͷindex
	int m_iTail;  //��βindex��ָ��ǰ��β����һ����λ��
};

//ģ�������д�������ͬһ���ļ��У�������һ���������ֳ�.h��.cpp����
template<typename Type>
MyQueue<Type>::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	ClearQueue();
	m_pQueue = new Type[m_iQueueCapacity];  //������Ҫ����Ĭ�Ϲ��캯��Comstomer(){}

	//char array1[3] = { 'a','b','c' };
	//char array2[3];
	//memcpy(array2, array1, 3);
	//for (int i = 0; i < 3; i++) {
	//	std::cout << array2[i] << " ";
	//}

}

template<typename Type>
MyQueue<Type>::~MyQueue()
{
	delete[] m_pQueue;
	m_pQueue = nullptr;
}

template<typename Type>
void MyQueue<Type>::ClearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}

template<typename Type>
bool MyQueue<Type>::QueueEmpty() const
{
	if (m_iQueueLen == 0) {
		return true;
	}
	return false;
}

template<typename Type>
bool MyQueue<Type>::QueueFull() const
{
	if (m_iQueueLen == m_iQueueCapacity) {
		return true;
	}
	return false;
}

template<typename Type>
int MyQueue<Type>::QueueLength() const
{
	return m_iQueueLen;
}

template<typename Type>
bool MyQueue<Type>::EnQueue(Type element)
{
	if (!QueueFull()) {
		m_pQueue[m_iTail] = element;
		m_iTail = (m_iTail + 1) % m_iQueueCapacity;
		m_iQueueLen++;
		return true;
	}
	else {
		return false;
	}
}


template <typename Type>
bool MyQueue<Type>::DeQueue(Type & element)  //element����нӶ�ͷ����Ԫ�ص�ֵ
{
	if (!QueueEmpty()) {
		element = m_pQueue[m_iHead];
		m_iHead = (m_iHead + 1) % m_iQueueCapacity;
		m_iQueueLen--;
		return true;
	}
	else {
		return false;
	}

}

template<typename Type>
void MyQueue<Type>::QueueTraverse()
{
	cout << "\nThis is the whole Traverse:\n";
	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
	{
		m_pQueue[i % m_iQueueCapacity].printinfo();
	}
	cout << endl;
}



#endif
