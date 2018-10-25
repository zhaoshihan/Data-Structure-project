// CommonAncestor.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>

using namespace std;

template<class Type>
class BTNode
{
public:
	Type data;
	BTNode* leftChild;
	BTNode*	rightChild;

	BTNode() = default;
	BTNode(Type data) {
		this->data = data;
	}
	bool findNode(BTNode* current);
};

template <class Type>
bool BTNode<Type>::findNode(BTNode* current)
{
	if (this == nullptr)
	{
		return false;
	}
	if (this == current)
	{
		return true;
	}
	if (this->leftChild != nullptr)
	{
		if (this->leftChild->findNode(current)) {
			return true;
		}
	}
	if (this->rightChild != nullptr)
	{
		if (this->rightChild->findNode(current)) {
			return true;
		}
	}
	return false;
}


template <class Type>
BTNode<Type>* nearestAncestor(BTNode<Type>* tree, BTNode<Type> *p, BTNode<Type>* q)
{
	if (tree->findNode(p) && tree->findNode(q))
	{
		BTNode<Type>* left_temp = nearestAncestor(tree->leftChild, p, q);
		if (left_temp != nullptr) {
			return left_temp;
		}

		BTNode<Type>* right_temp = nearestAncestor(tree->rightChild, p, q);
		if (right_temp != nullptr) {
			return right_temp;
		}

		if (left_temp == nullptr && right_temp == nullptr)
		{
			return tree;
		}
	}
	return nullptr;

}


int main()
{
	BTNode<char>* root = new BTNode<char>('A');
	BTNode<char>* node1 = new BTNode<char>('B');
	BTNode<char>* node2 = new BTNode<char>('C');
	BTNode<char>* node3 = new BTNode<char>('D');
	BTNode<char>* node4 = new BTNode<char>('E');
	BTNode<char>* node5 = new BTNode<char>('F');
	BTNode<char>* node6 = new BTNode<char>('G');
	BTNode<char>* node7 = new BTNode<char>('H');

	root->leftChild = node1;
	root->rightChild = node2;
	node1->leftChild = node3;
	node1->rightChild = node4;
	node2->rightChild = node5;
	node5->leftChild = node6;
	node5->rightChild = node7;

	BTNode<char>* result = nearestAncestor(root, node6, node7);
	cout << "The result is:  " << result->data;
	

	system("pause");
    return 0;
}
