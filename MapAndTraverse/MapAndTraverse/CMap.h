#pragma once
#ifndef CMAP_H
#define CMAP_H

#include "Node.h"
#include "Edge.h"
#include <vector>

using namespace std;

class CMap 
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node* pNode);
	void resetNode();  //�������нڵ���δ����
	bool setValueToMatrixForDirectedGraph(int row, int col, int val=1);
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val=1);
	

	void printMatrix();  //��������ڽӾ���
	
	void depthFirstTraverse(int nodeIndex);
	void breadthFirstTraverse(int nodeIndex);


	void primTree(int nodeIndex);  //Prim�㷨������
	void KruskalTree();  //Kruskal�㷨������

private:
	bool getValueFromMatrix(int row, int col, int& val);  //��Ȩֵ��������ı���val
	void breadthFirstTraverseImpl(vector<int> currentVector);
	int getMinEdge(vector<Edge> edgeVec);

	bool isInSet(vector<int> oneNodeSet, int nodeIndex);
	void mergeNodeSet(vector<int> &nodeSetA, vector<int>nodeSetB);  //B��A���Ϻϲ�

private:
	const int m_iCapacity;  //ͼ����󶥵�����
	int m_iNodeCount;  //�Ѿ���ӵĶ��㣨�ڵ㣩����
	Node* m_pNodeArray;  //��Ŷ��������
	int** m_pMatrix;  //���ڽӾ����ʾͼ

	Edge* m_pEdge;  //Edge������飬�洢�������е�n-1����
};


#endif