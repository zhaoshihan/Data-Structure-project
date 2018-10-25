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
	Node * SearchNode(int nodeIndex);  //搜索节点
	bool AddNode(int nodeIndex, int direction, Node * pNode);  //添加节点
	bool DeleteNode(int nodeIndex, Node * pNode);  //删除节点
	void PreorderTraversal();
	void InorderTraversal();
	void TraversalInSpecialLevel(Node* node,int level);
	Node* getRoot();

private:
	Node * m_pRoot;

};

#endif // !TREE_H
