#include "stdafx.h"
#include "Tree.h"
#include <stack>
#include <iostream>

Tree::Tree()
{
	m_pRoot = new Node();

}

Tree::Tree(char data)
{
	m_pRoot = new Node(data);
}

Tree::~Tree()
{
	m_pRoot->DeleteNode();  //����������
}

Node * Tree::SearchNode(char data)
{
	return m_pRoot->SearchNode(data);
}

// �����ڴ����Ҳ㼶�������ݻ��ع��������ʱdirection��ʾ���뷽��
bool Tree::AddNode(char data, Node * pNode, int direction)  //pNode��Ҫ��ӵĽڵ�
{
	Node* temp = SearchNode(data); //��ʱ�洢�������Ľڵ�
	if (temp == nullptr) {
		return false; //���ؽڵ㲻����
	}

	Node* node = new Node();  //��ӽڵ�
	if (node == nullptr) {  //��̬�����ڴ�ʧ��
		return false;
	}
	node->data = pNode->data;
	node->pParent = temp;  //˵������ڵ�ĸ��ڵ�

	if (direction == 0) {
		if (temp->pLChild == nullptr) {
			temp->pLChild = node;
			return true;
		}
		else if (temp->pRChild == nullptr) {
			temp->pRChild = node;
			return true;
		}
		else {
			return false;
		}
	}

	else if (direction == 1) {
		if (temp->pRChild == nullptr) {
			temp->pRChild = node;
			return true;
		}
		else {
			return false;
		}
	}
	return false;

}

bool Tree::DeleteNode(char data, Node * pNode)  //������
{
	Node* temp = SearchNode(data);
	if (temp == nullptr) {
		return false;
	}
	
	if(pNode != nullptr){
		pNode->data = temp->data;
	}

	temp->DeleteNode();
	return true;
}

// �ݹ������
//void Tree::PreorderTraversal()
//{
//	m_pRoot->PreorderTraversal();
//}
//
//void Tree::InorderTraversal()
//{
//	m_pRoot->InorderTraversal();
//}
//
//void Tree::PostorderTraversal()
//{
//	m_pRoot->PostorderTraversal();
//}

void Tree::PreorderTraversal()
{
	std::stack<Node*> mystack;
	Node* temp = m_pRoot;
	std::cout << "\nThis is the pre-oreder of the whole tree: \n";
	do {
		while (temp != nullptr) {
			std::cout << temp->data << "  ";
			mystack.push(temp);  //ǰ�������ÿ��Ԫ����ջǰ��ӡ���
			temp = temp->pLChild;
		}
		if (!mystack.empty()) {
			temp = mystack.top();
			mystack.pop();
			temp = temp->pRChild;
		}
	} while (temp != nullptr || !mystack.empty());
}

void Tree::InorderTraversal()
{
	std::stack<Node*> mystack;
	Node* temp = m_pRoot;
	std::cout << "\nThis is the in-oreder of the whole tree: \n";
	do {
		while (temp != nullptr) {
			mystack.push(temp);
			temp = temp->pLChild;
		}
		if (!mystack.empty()) {
			temp = mystack.top();
			mystack.pop();
			std::cout << temp->data << "  ";
			temp = temp->pRChild;
		}
	} while (temp != nullptr || !mystack.empty());
}

