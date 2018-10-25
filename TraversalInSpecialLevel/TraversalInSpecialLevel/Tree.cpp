#include "stdafx.h"
#include "Tree.h"
#include <stack>
#include <iostream>

using namespace std;
Tree::Tree()
{
	m_pRoot = new Node();

}

Tree::Tree(char data)
{
	m_pRoot = new Node(0, data);
}

Tree::~Tree()
{
	m_pRoot->DeleteNode();  //����������
}

Node * Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction, Node * pNode)  //pNode��Ҫ��ӵĽڵ�
{
	Node* temp = SearchNode(nodeIndex); //��ʱ�洢�������Ľڵ�
	if (temp == nullptr) {
		return false; //���ؽڵ㲻����
	}

	Node* node = new Node();  //��ӽڵ�
	if (node == nullptr) {  //��̬�����ڴ�ʧ��
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;

	if (direction == 0)
	{
		temp->pLChild = node;  //��node��ӵ��������Ľڵ��������
		return true;
	}
	else if (direction == 1)
	{
		temp->pRChild = node;
		return true;
	}
	return false;
}

bool Tree::DeleteNode(int nodeIndex, Node * pNode)  //������
{
	Node* temp = SearchNode(nodeIndex);
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
	std::cout << "\nThe pre-order of the whole tree is: \n";
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
	std::cout << "\nThe in-order of the whole tree is: \n";
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

void Tree::TraversalInSpecialLevel(Node* temp, int level)
{
	if (level == 1) {
		cout << temp->data << "  ";
	}
	else {
		if (temp->pRChild != nullptr) {
			TraversalInSpecialLevel(temp->pRChild, level - 1);
		}
		if (temp->pLChild != nullptr) {
			TraversalInSpecialLevel(temp->pLChild, level - 1);
		}

	}
}

Node * Tree::getRoot()
{
	return this->m_pRoot;
}

