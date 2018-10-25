#include "Node.h"
#include <iostream>

using namespace std;
Node::Node()
{
	index = 0;
	data = 0;
	pLChild = nullptr;
	pRChild = nullptr;
	pParent = nullptr;

}

Node::Node(int index, int data)
{
	this->index = index;
	this->data = data;
	pLChild = nullptr;
	pRChild = nullptr;
	pParent = nullptr;
}

Node * Node::SearchNode(int nodeIndex)
{
	if (this->index == nodeIndex) {  //���ڵ�������
		return this;
	}

	Node* temp = nullptr;
	if (this->pLChild != nullptr) {  //���ڵ������������
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
		�Ȱѵ�ǰ�ڵ��������������գ�
		���жϽڵ����Ը��ڵ㣬�����������ң���ն�Ӧ�ĸ��ڵ�ָ�룻
		�����������.
	*/
	if (this->pLChild != nullptr) 
	{
		this->pLChild->DeleteNode();  //�ݹ��������������������нڵ�
	}
	if (this->pRChild != nullptr)
	{
		this->pRChild->DeleteNode();
	}

	if (this->pParent != nullptr)
	{
		if (this->pParent->pLChild == this)  //�Ǹ��ڵ������
		{
			this->pParent->pLChild = nullptr;  //���ڵ������ָ�����
		}
		if (this->pParent->pRChild == this)
		{
			this->pParent->pRChild = nullptr;
		}
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
