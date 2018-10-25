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
	Node * SearchNode(char data);  //搜索节点
	bool AddNode(char data, Node * pNode, int direction=0);  //添加节点
	bool DeleteNode(char data, Node * pNode);  //删除节点
	void PreorderTraversal();
	void InorderTraversal();

	void PostorderTraversal();

private:
	Node * m_pRoot;

};

#endif // !TREE_H
