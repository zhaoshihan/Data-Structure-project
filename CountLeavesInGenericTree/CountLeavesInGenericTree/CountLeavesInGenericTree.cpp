// CountLeavesInGenericTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>

int main()
{
	Tree* tree = new Tree(11);
	tree->m_root->leftchild = new Node(5);
	tree->m_root->leftchild->leftchild = new Node(7);
	tree->m_root->leftchild->rightsibling = new Node(3);
	tree->m_root->leftchild->leftchild->rightsibling = new Node(8);
	tree->m_root->leftchild->leftchild->rightsibling->leftchild = new Node(4);
	tree->m_root->leftchild->leftchild->rightsibling->rightsibling = new Node(2);

	tree->m_root->rightsibling = new Node(9);
	tree->m_root->rightsibling->leftchild = new Node(10);
	tree->m_root->rightsibling->leftchild->rightsibling = new Node(12);

	tree->m_root->rightsibling->rightsibling = new Node(17);
	tree->m_root->rightsibling->rightsibling->leftchild = new Node(14);
	tree->m_root->rightsibling->rightsibling->leftchild->leftchild = new Node(16);



	cout << "\nThe numbers of leaves in the whole generic tree is: " << tree->countLeaves();

	system("pause");
    return 0;
}

