// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include "stdafx.h"
#include<iostream>
#include<list>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
	int verticeCount;    // No. of vertices

			  // Pointer to an array containing
			  // adjacency lists
	list<int> *adjList;

	// A recursive function used by DFS
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);   // Constructor

					// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

Graph::Graph(int verticeCount)
{
	this->verticeCount = verticeCount;

	//adjList指向一个长度为verticeCount的数组，数组中每个元素又都是一个List表
	//感觉List类似于vector
	adjList = new list<int>[verticeCount];
}

//这个是一个有向图
void Graph::addEdge(int v, int w)
{
	adjList[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int verticeIndex, bool visited[])
{
	// Mark the current node as visited and
	// print it 正常情况下是在入栈前先输出结果
	visited[verticeIndex] = true;
	cout << verticeIndex << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adjList[verticeIndex].begin(); i != adjList[verticeIndex].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int verticeIndex)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[verticeCount];
	for (int i = 0; i < verticeCount; i++)
		visited[i] = false;

	// Call the recursive helper function
	// to print DFS traversal
	DFSUtil(verticeIndex, visited);
}

int main()
{
	// Create a graph given in the above diagram  
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
		" (starting from vertex 2) \n";
	g.DFS(2);

	system("pause");
	return 0;
}