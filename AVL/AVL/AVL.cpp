// AVL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Tree.h"

int main()
{
	Tree* tree = new Tree('A');
	tree->m_root->leftchild = new BtNode('B');
	tree->m_root->leftchild->leftchild = new BtNode('D');
	tree->m_root->leftchild->rightchild = new BtNode('H');
	tree->m_root->leftchild->leftchild->rightchild = new BtNode('G');
	tree->m_root->rightchild= new BtNode('C');
	tree->m_root->rightchild->leftchild = new BtNode('E');
	tree->m_root->rightchild->rightchild = new BtNode('F');

	cout << "The Preorder is: " << endl;
	tree->Preorder(tree->m_root);
	cout << "\nThe Inorder is: " << endl;
	tree->Inorder(tree->m_root);

	cout << "\nIs it a balanced tree? : " << tree->isBalanced(tree->m_root) << endl;

	system("pause");
    return 0;
}

