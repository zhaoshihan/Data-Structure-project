#include "stdafx.h"
#include "Node.h"
#include <iostream>

using namespace std;
Node::Node()
{
	data = NULL;
	pLChild = nullptr;
	pRChild = nullptr;
	pParent = nullptr;

}

Node::Node(char data)
{
	this->data = data;
	pLChild = nullptr;
	pRChild = nullptr;
	pParent = nullptr;
}

Node * Node::SearchNode(char data)
{
	if (this->data == data) {  //���ڵ�������
		return this;
	}

	Node* temp = nullptr;
	if (this->pLChild != nullptr) {  //���ڵ������������
		if (this->pLChild->data == data) {
			return this->pLChild;
		}
		else {
			temp = this->pLChild->SearchNode(data);
			if (temp != nullptr) {
				return temp;
			}
		}
	}
	if (this->pRChild != nullptr) {
		if (this->pRChild->data == data) {
			return this->pRChild;
		}
		else {
			temp = this->pRChild->SearchNode(data);
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
	cout << this->data << "  " << this->data << endl;

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

	cout << this->data << "  " << this->data << endl;

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

	cout << this->data << "  " << this->data << endl;
}
