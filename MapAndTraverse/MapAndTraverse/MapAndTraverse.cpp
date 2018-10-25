// MapAndTraverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CMap.h"
#include <iostream>

using namespace std;

int main()
{
	//CMap* pMap = new CMap(8);
	CMap* pMap = new CMap(6);

	Node* pNodeA = new Node('A');
	Node* pNodeB = new Node('B');
	Node* pNodeC = new Node('C');
	Node* pNodeD = new Node('D');
	Node* pNodeE = new Node('E');
	Node* pNodeF = new Node('F');
	//Node* pNodeG = new Node('G');
	//Node* pNodeH = new Node('H');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	//pMap->addNode(pNodeG);
	//pMap->addNode(pNodeH);

	//生成一个无向图
	//pMap->setValueToMatrixForUndirectedGraph(0, 1);
	//pMap->setValueToMatrixForUndirectedGraph(0, 3);
	//pMap->setValueToMatrixForUndirectedGraph(1, 2);
	//pMap->setValueToMatrixForUndirectedGraph(1, 5);
	//pMap->setValueToMatrixForUndirectedGraph(3, 6);
	//pMap->setValueToMatrixForUndirectedGraph(3, 7);
	//pMap->setValueToMatrixForUndirectedGraph(6, 7);
	//pMap->setValueToMatrixForUndirectedGraph(2, 4);
	//pMap->setValueToMatrixForUndirectedGraph(5, 4);
	
	//构造星型图
	pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);
	pMap->setValueToMatrixForUndirectedGraph(0, 4, 5);
	pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);
	pMap->setValueToMatrixForUndirectedGraph(1, 2, 3);
	pMap->setValueToMatrixForUndirectedGraph(1, 5, 2);
	pMap->setValueToMatrixForUndirectedGraph(2, 3, 7);
	pMap->setValueToMatrixForUndirectedGraph(2, 5, 8);
	pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);
	pMap->setValueToMatrixForUndirectedGraph(3, 5, 4);
	pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);


	pMap->printMatrix();

	//cout << endl;
	//cout << "\nThis is the Depth-First Traversal: " << endl;
	//pMap->depthFirstTraverse(0);  //从A点（index=0）开始

	//cout << endl;
	//pMap->resetNode();
	//pMap->breadthFirstTraverse(0);

	pMap->resetNode();
	pMap->primTree(0);  //从A点（index=0）开始

	//pMap->resetNode();
	//pMap->KruskalTree();
	system("pause");
    return 0;
}

