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
	m_pRoot->DeleteNode();  //销毁整棵树
}

Node * Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction, Node * pNode)  //pNode是要添加的节点
{
	Node* temp = SearchNode(nodeIndex); //临时存储搜索到的节点
	if (temp == nullptr) {
		return false; //挂载节点不存在
	}

	Node* node = new Node();  //添加节点
	if (node == nullptr) {  //动态申请内存失败
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;

	if (direction == 0)
	{
		temp->pLChild = node;  //把node添加到搜索到的节点的左孩子上
		return true;
	}
	else if (direction == 1)
	{
		temp->pRChild = node;
		return true;
	}
	return false;
}

bool Tree::DeleteNode(int nodeIndex, Node * pNode)  //？？？
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

// 递归遍历法
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
			mystack.push(temp);  //前序遍历，每个元素入栈前打印输出
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

