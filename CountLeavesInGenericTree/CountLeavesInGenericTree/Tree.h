#pragma once
#ifndef TREE_H
#define TREE_H

#include <stack>
#include <iostream>
using namespace std;

struct Node
{
	int times;
	int data;
	Node* leftchild;
	Node* rightsibling;

	Node() = default;
	Node(int data) {
		this->data = data;
		this->times = 0;
		leftchild = nullptr;
		rightsibling = nullptr;
	}
};


class Tree
{
public:
	Node* m_root;
	Tree();
	Tree(int data);
	~Tree();
	int countLeaves();

private:
	stack<Node*> mystack;
};

Tree::Tree()
{
	m_root = new Node();

}

inline Tree::Tree(int data)
{
	m_root = new Node(data);
}



Tree::~Tree()
{
	delete m_root;
}

inline int Tree::countLeaves()
{
	int count = 0;
	mystack.push(m_root);

	do 
	{
		Node* temp = mystack.top();
		mystack.pop();
		temp->times++;
		if (temp->times == 1) {
			mystack.push(temp);
			if (temp->leftchild != nullptr)
			{
				mystack.push(temp->leftchild);
			}
			else {
				cout << temp->data << " ";
				count++;
			}
		}
		else if (temp->times == 2) {
			mystack.push(temp);
			if (temp->rightsibling != nullptr)
			{
				mystack.push(temp->rightsibling);
			}
		}
	} while (!mystack.empty());  

	return count;

}


#endif

