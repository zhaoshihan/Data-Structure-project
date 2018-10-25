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
	void resetNode();  //重置所有节点至未访问
	bool setValueToMatrixForDirectedGraph(int row, int col, int val=1);
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val=1);
	

	void printMatrix();  //输出整个邻接矩阵
	
	void depthFirstTraverse(int nodeIndex);
	void breadthFirstTraverse(int nodeIndex);


	void primTree(int nodeIndex);  //Prim算法生成树
	void KruskalTree();  //Kruskal算法生成树

private:
	bool getValueFromMatrix(int row, int col, int& val);  //将权值赋给传入的变量val
	void breadthFirstTraverseImpl(vector<int> currentVector);
	int getMinEdge(vector<Edge> edgeVec);

	bool isInSet(vector<int> oneNodeSet, int nodeIndex);
	void mergeNodeSet(vector<int> &nodeSetA, vector<int>nodeSetB);  //B向A集合合并

private:
	const int m_iCapacity;  //图的最大顶点容量
	int m_iNodeCount;  //已经添加的顶点（节点）个数
	Node* m_pNodeArray;  //存放顶点的数组
	int** m_pMatrix;  //用邻接矩阵表示图

	Edge* m_pEdge;  //Edge类的数组，存储生成树中的n-1条边
};


#endif