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
	Node * SearchNode(int nodeIndex);  //�����ڵ�
	bool AddNode(int nodeIndex, int direction, Node * pNode);  //��ӽڵ�
	bool DeleteNode(int nodeIndex, Node * pNode);  //ɾ���ڵ�
	void PreorderTraversal();
	void InorderTraversal();
	void TraversalInSpecialLevel(Node* node,int level);
	Node* getRoot();

private:
	Node * m_pRoot;

};

#endif // !TREE_H
