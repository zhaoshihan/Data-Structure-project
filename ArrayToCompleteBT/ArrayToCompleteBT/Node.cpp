#include "stdafx.h"
#include "Node.h"
#include <iostream>

using namespace std;
Node::Node()
{
	index = 0;
	data = 0;
	pLChild = nullptr;
	pRChild = nullptr;
}

Node::Node(int index, char data)
{
	this->index = index;
	this->data = data;
	pLChild = nullptr;
	pRChild = nullptr;
}

Node * Node::SearchNode(int nodeIndex)
{
	if (this->index == nodeIndex) {  //本节点是所找
		return this;
	}

	Node* temp = nullptr;
	if (this->pLChild != nullptr) {  //本节点的左孩子是所找
		if (this->pLChild->index == nodeIndex) {
			return this->pLChild;
		}
		else {
			temp = this->pLChild->SearchNode(nodeIndex);
			if (temp != nullptr) {
				return temp;
			}
		}
	}
	if (this->pRChild != nullptr) {
		if (this->pRChild->index == nodeIndex) {
			return this->pRChild;
		}
		else {
			temp = this->pRChild->SearchNode(nodeIndex);
			if (temp != nullptr) {
				return temp;
			}
		}
	}

	return nullptr;

}

void Node::DeleteNode()
{
	/*
		先把当前节点的左右子树都清空；
		再判断节点所对父节点，是在左还是在右，清空对应的父节点指针；
		最后自我销毁.
	*/
	if (this->pLChild != nullptr) 
	{
		this->pLChild->DeleteNode();  //递归操作，清除左子树的所有节点
	}
	if (this->pRChild != nullptr)
	{
		this->pRChild->DeleteNode();
	}

	delete this;
}

void Node::PreorderTraversal()
{
	cout << this->index << "  " << this->data << endl;

	if (this->pLChild != nullptr) {
		this->pLChild->PreorderTraversal();
	}

	if (this->pRChild != nullptr) {
		this->pRChild->PreorderTraversal();
	}
}

void Node::InorderTraversal()
{
	if (this->pLChild != nullptr) {
		this->pLChild->InorderTraversal();
	}

	cout << this->index << "  " << this->data << endl;

	if (this->pRChild != nullptr) {
		this->pRChild->InorderTraversal();
	}
}

void Node::PostorderTraversal()
{
	if (this->pLChild != nullptr) {
		this->pLChild->PostorderTraversal();
	}

	if (this->pRChild != nullptr) {
		this->pRChild->PostorderTraversal();
	}

	cout << this->index << "  " << this->data << endl;
}
