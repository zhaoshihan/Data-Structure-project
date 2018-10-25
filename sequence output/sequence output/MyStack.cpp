#include "stdafx.h"
#include "MyStack.h"
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;


//分割字符串的模板
template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}
std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}

MyStack::MyStack(int size) 
{
	m_iSize = size;
	m_pBuffer = new int[size];
	m_iTop = 0;

	array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = i + 1;
	}
	cur_number = array;
}

bool MyStack::stackEmpty()
{
	if (m_iTop == 0) {
		return true;
	}
	return false;
}

bool MyStack::stackFull()
{
	if (m_iTop >= m_iSize) {
		return true;
	}
	return false;
}

void MyStack::clearStack()
{
	m_iTop = 0;
}

int MyStack::stackLength()
{
	return m_iTop;
}

bool MyStack::push()
{
	if (!stackFull()) {
		m_pBuffer[m_iTop] = *cur_number;
	/*	cout << *cur_number<<" ";*/

		cur_number++;
		m_iTop++;
		return true;
	}
	return false;
}

int MyStack::pop()
{
	if (!stackEmpty()) {
		m_iTop--;  //指向栈顶实际元素
		cout<< m_pBuffer[m_iTop]<< " ";
		return m_pBuffer[m_iTop];
	}
	throw 1;
}

//从栈底向上遍历
void MyStack::stackTraverse()
{
	for (int i = 0; i < m_iTop; i++) {
		cout << m_pBuffer[i] << ",";
	}
}


void MyStack::printAll(int push_count, int pop_count, string s)
{
	if (push_count == m_iSize && pop_count == m_iSize) {
		vector<string> step = split(s, ',');  //以","分割字符串，返回vector
		for (vector<string>::iterator it = step.begin(); it != step.end(); ++it) {
			//cout << *it;
			if (it->compare("push") == 0) {
				this->push();

			}
			else if (it->compare("pop") == 0) {
				this->pop();
			}
		}
		cout << '\n';
		cur_number = array; //复位指针到数组起始元素
		return;
	}

	if (push_count < m_iSize) {
		/*
		 因为string里面，append()是直接对原字符串操作，+"xxx"返回的是字符串的副本，
		 因此这里用append()会造成冗余操作，多一个push

		 递归按顺序先后进行两个if判断
		*/
		//s.append("push ");
		//printAll(push_count + 1, pop_count, s);
		printAll(push_count+1, pop_count, s + "push,");
	}
	if (pop_count < m_iSize && push_count>pop_count) {
		//s.append("pop ");
		//printAll(push_count, pop_count + 1, s);
		printAll(push_count, pop_count+1, s + "pop,");
	}
}

MyStack::~MyStack() 
{
	delete[] m_pBuffer;
	m_pBuffer = nullptr;
	delete[] array;
	array = nullptr;
	cur_number = nullptr;
}