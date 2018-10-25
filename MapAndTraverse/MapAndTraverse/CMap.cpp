#include "stdafx.h"
#include "CMap.h"
#include <iostream>
#include <vector>

using namespace std;

CMap::CMap(int capacity) : m_iCapacity(capacity){  //初始化const成员变量
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];

	m_pMatrix = new int* [m_iCapacity];  //二维数组动态申请空间，只能这样做
	for (int i = 0; i < m_iCapacity; i++) {
		m_pMatrix[i] = new int[m_iCapacity];
		memset(m_pMatrix[i], 0, m_iCapacity * sizeof(int));
	}

	m_pEdge = new Edge[m_iCapacity - 1];
}

CMap::~CMap()
{
	delete[] m_pNodeArray;

	for (int i = 0; i < m_iCapacity; i++) {  //注意这里的释放内存方法
		delete[] m_pMatrix[i];
	}
	delete[] m_pMatrix;
	delete[] m_pEdge;
}

bool CMap::addNode(Node * pNode)
{
	if (pNode != nullptr) {
		m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;  //以数组index给节点编号,添加节点的顺序就是在中index的顺序
		m_iNodeCount++;
		return true;
	}
	return false;
}

void CMap::resetNode()
{
	for (int i = 0; i < m_iNodeCount; i++) {
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	if (row < 0 || row >= m_iCapacity) {  //检测输入，越界的在前
		return false;
	}
	if (col < 0 || col >= m_iCapacity) {
		return false;
	}

	m_pMatrix[row][col] = val;
	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if (row < 0 || row >= m_iCapacity) {  
		return false;
	}
	if (col < 0 || col >= m_iCapacity) {
		return false;
	}

	m_pMatrix[row][col] = val;
	m_pMatrix[col][row] = val;  //对称都赋同值
	return true;
}

bool CMap::getValueFromMatrix(int row, int col, int & val)
{
	if (row < 0 || row >= m_iCapacity) {
		return false;
	}
	if (col < 0 || col >= m_iCapacity) {
		return false;
	}

	val = m_pMatrix[row][col];
	return true;
}

void CMap::printMatrix()
{
	for (int i = 0; i < m_iCapacity; i++) {
		for (int j = 0; j < m_iCapacity; j++) {
			cout << m_pMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

//深度优先遍历
void CMap::depthFirstTraverse(int nodeIndex)
{
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	for (int i=0; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i, value);  //nodeindex是行数，i是列数
		if (value != 0)
		{
			if (m_pNodeArray[i].m_bIsVisited)
			{
				continue;
			}
			else
			{
				depthFirstTraverse(i);
			}
		}
		else {
			continue;
		}
	}

}

//广度优先遍历
void CMap::breadthFirstTraverse(int nodeIndex)  //递归启动函数
{
	cout << "\nThis is the Breadth-First Traversal: " << endl;
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	vector<int> curVec;
	curVec.push_back(nodeIndex);

	breadthFirstTraverseImpl(curVec);
	cout << endl;
}

void CMap::breadthFirstTraverseImpl(vector<int> preVec)  //上一层的节点数组
{
	int value = 0;
	vector<int> curVec;  //每层的节点存放在一个数组中

	for (int i=0; i<(int)preVec.size(); i++)
	{
		for (int j=0; j<m_iCapacity; j++)  
		{
			getValueFromMatrix(preVec[i], j, value);  //看上一层的节点是否有与j列连接的边
			if (value != 0)
			{
				if (!m_pNodeArray[j].m_bIsVisited) {
					cout << m_pNodeArray[j].m_cData << " ";
					m_pNodeArray[j].m_bIsVisited = true;

					curVec.push_back(j);
				}
				else {
					continue;
				}
			}
		}
	}

	if (curVec.size() != 0)
	{
		breadthFirstTraverseImpl(curVec);
	}
	else {
		return;
	}

}

//Prim算法生成树
void CMap::primTree(int nodeIndex)
{
	int value = 0;
	int edgeCount = 0;
	vector<int> nodeVec;  //存储所有顶点索引
	vector<Edge> edgeVec;  //存储所有的备选边(包括新增顶点和老顶点的边都算)

	cout << "\nGenerate the smallest tree(Prim): " << endl;
	cout << m_pNodeArray[nodeIndex].m_cData << endl;

	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	while (edgeCount < m_iCapacity - 1)
	{
		int temp = nodeVec.back();
		for (int i=0; i<m_iCapacity; i++)
		{
			getValueFromMatrix(temp, i, value);
			if (value != 0) {
				if (!m_pNodeArray[i].m_bIsVisited)
				{
					Edge edge(temp, i, value);
					edgeVec.push_back(edge);  
				}
				else {
					continue;
				}
			}
		}

		//挑所有这些(已探测点的)可选边中最小的
		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;

		int nodeAIndex = edgeVec[edgeIndex].m_iNodeIndexA;
		int nodeBIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		cout << m_pNodeArray[nodeAIndex].m_cData << "---->" << m_pNodeArray[nodeBIndex].m_cData << " ";
		cout << edgeVec[edgeIndex].m_iWeightValue << endl;

		m_pEdge[edgeCount] = edgeVec[edgeIndex];
		edgeCount++;

		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
		cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}
}

//边集合中找最小边
int CMap::getMinEdge(vector<Edge> edgeVec)
{
	int minWeight = 0;
	int edgeIndex = 0;
	int count = 0;

	for (int i=0; i<edgeVec.size(); i++)
	{
		if (!edgeVec[i].m_bSelected) {
			if (count == 0)
			{
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
				count++;
			}
			if (minWeight > edgeVec[i].m_iWeightValue && count != 0)
			{
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
				count++;
			}
		}
	}
	return edgeIndex;
}

//Kruskal算法生成树
void CMap::KruskalTree()
{
	int value = 0;
	int edgeCount = 0;
	//定义存放节点集合的数组，逐渐合并为一个集合
	vector<vector<int>> nodeSets;
	vector<Edge> edgeVec;  //存放所有的边

	for (int row = 0; row < m_iCapacity; row++) {  
		for (int col = row + 1; col < m_iCapacity; col++) {  //取邻接矩阵中的上三角，全部转换为Edge类
			getValueFromMatrix(row, col, value);
			if (value != 0) {
				Edge edge(row, col, value);
				edgeVec.push_back(edge);
			}
		}
	}

	std::cout << "\nGenerate the smallest tree(Kruskal): " << endl;
	while (edgeCount < m_iCapacity - 1)
	{
		int minEdgeIndex = getMinEdge(edgeVec);
		edgeVec[minEdgeIndex].m_bSelected = true;

		//找出最小边连接的点
		int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

		bool nodeAInSet = false;
		bool nodeBInSet = false;

		int nodeAInSetLabel = -1;  //存放起始点的索引
		int nodeBInSetLabel = -1;

		//找出点所在的点集合
		for (vector<vector<int>>::iterator it = nodeSets.begin(); it != nodeSets.end(); ++it)
		{
			nodeAInSet = isInSet(*it, nodeAIndex);  //判断点是否在集合中
			nodeBInSet = isInSet(*it, nodeBIndex);
			if (nodeAInSet)
			{
				nodeAInSetLabel = it - nodeSets.begin();
			}
			if (nodeBInSet)
			{
				nodeBInSetLabel = it - nodeSets.begin();
			}
		}

		//根据点所在集合的不同做出不同处理
		if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
		{
			vector<int> vec;
			vec.push_back(nodeAIndex);
			vec.push_back(nodeBIndex);
			nodeSets.push_back(vec);
		}
		else if (nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
		{
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);  //A点放入有B点的集合中
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
		{
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBInSetLabel)
		{
			mergeNodeSet(nodeSets[nodeAInSetLabel], nodeSets[nodeBInSetLabel]);  //向前一个集合合并
			nodeSets[nodeBInSetLabel].clear();
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)
		{
			continue;   //形成回路
		}
		m_pEdge[edgeCount] = edgeVec[minEdgeIndex];
		edgeCount++;

		cout << m_pNodeArray[nodeAIndex].m_cData << "----->" << m_pNodeArray[nodeBIndex].m_cData << " ";
		cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;
	}
}

bool CMap::isInSet(vector<int> oneNodeSet, int nodeIndex)
{
	for (vector<int>::iterator it = oneNodeSet.begin(); it != oneNodeSet.end(); ++it)
	{
		if (*it == nodeIndex)
		{
			return true;
		}
	}
	return false;
}

void CMap::mergeNodeSet(vector<int>& nodeSetA, vector<int> nodeSetB)
{
	for (vector<int>::iterator it = nodeSetB.begin(); it != nodeSetB.end(); ++it)
	{
		nodeSetA.push_back(*it);
	}
}
