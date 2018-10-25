#include "Tree.h"
#include <stack>
#include <iostream>

Tree::Tree()
{
	m_pRoot = new Node();

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
	node->pParent = temp;  //˵������ڵ�ĸ��ڵ�

	if (direction == 0)
	{
		temp->pLChild = node;  //��node��ӵ��������Ľڵ��������
	}
	if (direction == 1)
	{
		temp->pRChild = node;
	}
	return true;
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
	do {
		while (temp != nullptr) {
			std::cout << temp->index << "  ";
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
	do {
		while (temp != nullptr) {
			mystack.push(temp);
			temp = temp->pLChild;
		}
		if (!mystack.empty()) {
			temp = mystack.top();
			mystack.pop();
			std::cout << temp->index << "  ";
			temp = temp->pRChild;
		}
	} while (temp != nullptr || !mystack.empty());
}

