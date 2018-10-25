#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node();
	Node(char data);
	Node* SearchNode(char data);
	void DeleteNode();

	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();

	char data;
	Node * pLChild;
	Node * pRChild;
	Node * pParent;
};


#endif // !NODE_H
