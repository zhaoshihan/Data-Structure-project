#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node();
	Node(int index, int data=0);
	Node* SearchNode(int nodeIndex);
	void DeleteNode();

	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();

	int index;
	int data;
	Node * pLChild;
	Node * pRChild;
	Node * pParent;
};


#endif // !NODE_H
