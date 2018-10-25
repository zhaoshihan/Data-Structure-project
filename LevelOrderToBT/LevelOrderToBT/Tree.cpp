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
	m_pRoot->DeleteNode();  //销毁整棵树
}

Node * Tree::SearchNode(char data)
{
	return m_pRoot->SearchNode(data);
}

// 适用于从左到右层级遍历的溯回重构情况（此时direction表示插入方向）
bool Tree::AddNode(char data, Node * pNode, int direction)  //pNode是要添加的节点
{
	Node* temp = SearchNode(data); //临时存储搜索到的节点
	if (temp == nullptr) {
		return false; //挂载节点不存在
	}

	Node* node = new Node();  //添加节点
	if (node == nullptr) {  //动态申请内存失败
		return false;
	}
	node->data = pNode->data;
	node->pParent = temp;  //说明插入节点的父节点

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

bool Tree::DeleteNode(char data, Node * pNode)  //？？？
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
	std::cout << "\nThis is the pre-oreder of the whole tree: \n";
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

