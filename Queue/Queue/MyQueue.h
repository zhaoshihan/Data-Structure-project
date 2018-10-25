#pragma once
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

template<typename Type>
class MyQueue
{
public:
	MyQueue(int queueCapacity);  //创建环形队列
	virtual ~MyQueue();
	void ClearQueue();  //清空队列
	bool QueueEmpty() const;  //判断队列是否为空
	bool QueueFull() const;
	int QueueLength() const;  //队列长度无需修改操作，因此加const
	bool EnQueue(Type element);  //新元素入队
	bool DeQueue(Type &element);  //首元素出队
	void QueueTraverse();

private:
	Type* m_pQueue;  //队列数组指针
	int m_iQueueLen;  //队列元素个数
	int m_iQueueCapacity;  //队列数组容量

	int m_iHead;  //队头index
	int m_iTail;  //队尾index，指向当前队尾的下一个空位置
};

//模板类的书写必须放在同一个文件中，不能像一般类那样分成.h和.cpp两个
template<typename Type>
MyQueue<Type>::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	ClearQueue();
	m_pQueue = new Type[m_iQueueCapacity];  //这里需要调用默认构造函数Comstomer(){}

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
	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
	{
		m_pQueue[i % m_iQueueCapacity].printinfo();
	}
	cout << endl;
}



#endif
