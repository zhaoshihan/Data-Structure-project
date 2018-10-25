// TreeIterator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using namespace std;

template <class Type>
class Node {
public:
	Type data;
	Node* leftchild;
	Node* rightchild;

	Node() = default;
	Node(Type data) {
		this->data = data;
		leftchild = rightchild = nullptr;
	}
};

template <class Type>
class Tree {
public:
	Node<Type>* m_root;

	Tree() = default;
	Tree(Type data) {
		m_root = new Node(data);
	}
};

template<class Type>
class StaNode {
public:
	Node<Type>* node;
	int popTime;

	StaNode() = default;
	StaNode(Node<Type>* node) {
		this->node = node;
		popTime = 0;
	}
};


template<class Type>
class TreeIterator {
public:
	virtual void First();
	virtual void operator++();
	virtual void printCurrent();

	TreeIterator(const Tree<Type> & BT):tree(BT),current(nullptr)  {}
protected:
	const Tree<Type> & tree;
	Node<Type>* current;

};

template<class Type>
class PreOrder: public TreeIterator {
	bool renew;
public:
	PreOrder() = default;
	PreOrder(const Tree<Type> &BT) :TreeIterator(BT) {
		renew = false;
	}
	void First();
	void operator++();
	void printCurrent();
private:
	stack<StaNode<Type>> mystack;
};

template<class Type>
void PreOrder<Type>::First() {
	current = tree.m_root;
	renew = true;

	mystack.push(StaNode<Type>(tree->m_root));
	operator++();
}

template<class Type>
void PreOrder<Type>::operator++()
{
	if (!renew && mystack.empty())
	{
		current = nullptr;
		return;
	}
	renew = false;
	StaNode<Type> temp;
	do 
	{
		temp = mystack.top();
		mystack.pop();

		current = temp.node;
		if (temp.node->rightchild != nullptr)
		{
			mystack.push(StaNode(temp.node->rightchild));
		}
		if (temp.node->leftchild != nullptr)
		{
			mystack.push(StaNode(temp.node->leftchild));
		}

	} while (current != nullptr || !mystack.empty());
}

template<class Type>
void PreOrder<Type>::printCurrent()
{

}



int main()
{
	Tree<char>* tree = new Tree<char>('A');
	tree->m_root->leftchild = new Node<char>('B');
	tree->m_root->rightchild = new Node<char>('C');
	tree->m_root->leftchild->leftchild = new Node<char>('D');
	tree->m_root->leftchild->rightchild = new Node<char>('E');
	tree->m_root->rightchild->rightchild = new Node<char>('F');



    return 0;
}

