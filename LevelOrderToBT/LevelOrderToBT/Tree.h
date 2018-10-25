#pragma once
#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree
{
public:
	Tree();
	Tree(char data);
	~Tree();
	Node * SearchNode(char data);  //�����ڵ�
	bool AddNode(char data, Node * pNode, int direction=0);  //��ӽڵ�
	bool DeleteNode(char data, Node * pNode);  //ɾ���ڵ�
	void PreorderTraversal();
	void InorderTraversal();

	void PostorderTraversal();

private:
	Node * m_pRoot;

};

#endif // !TREE_H
