// BinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
	Node* node1 = new Node(1, 5);
	Node* node2 = new Node(2, 8);
	Node* node3 = new Node(3, 2);
	Node* node4 = new Node(4, 6);
	Node* node5 = new Node(5, 9);
	Node* node6 = new Node(6, 7);

	Tree* tree = new Tree();

	tree->AddNode(0, 0, node1); //0表示左孩子；1表示右孩子
	tree->AddNode(0, 1, node2);
	tree->AddNode(1, 0, node3);
	tree->AddNode(1, 1, node4);
	tree->AddNode(2, 0, node5);
	tree->AddNode(2, 1, node6);

	//tree->DeleteNode(2, nullptr);

	tree->PreorderTraversal();
	//tree->InorderTraversal();
	//tree->PostorderTraversal();

	delete tree;
	system("pause");
    return 0;
}

