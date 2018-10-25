#include "stdafx.h"
#include "MyQueue.h"
#include <iostream>

using namespace std;

template<typename Type>
MyQueue<Type>::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	ClearQueue();
	m_pQueue = new int[m_iQueueCapacity];
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
bool MyQueue<Type>::DeQueue(Type & element)  //element负责承接队头出队元素的值
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
	for (int i = m_iHead; i < m_iQueueLen+m_iHead; i++) 
	{
		m_pQueue[i % m_iQueueCapacity].printinfo();
	}
	cout << endl;
}

