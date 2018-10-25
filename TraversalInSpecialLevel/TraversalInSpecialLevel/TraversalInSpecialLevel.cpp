// TraversalInSpecialLevel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "This is a normal binary tree for test. It has 3 level" << endl;
	cout << "Please input the level number(from 1 to 3): ";

	int level;
	cin >> level;

	Tree* tree = new Tree('A');
	tree->AddNode(0, 0, new Node(1, 'B'));
	tree->AddNode(0, 1, new Node(2, 'C'));
	tree->AddNode(1, 0, new Node(3, 'D'));
	tree->AddNode(2, 0, new Node(4, 'E'));
	tree->AddNode(2, 1, new Node(5, 'F'));

	tree->TraversalInSpecialLevel(tree->getRoot(),level);

	tree->PreorderTraversal();
	tree->InorderTraversal();

	system("pause");
    return 0;
}

