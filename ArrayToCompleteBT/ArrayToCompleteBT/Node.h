#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node();
	Node(int index, char data);
	Node* SearchNode(int nodeIndex);
	void DeleteNode();

	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();

	int index;
	char data;
	Node * pLChild;
	Node * pRChild;
};


#endif // !NODE_H
