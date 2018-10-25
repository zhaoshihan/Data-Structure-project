#pragma once
#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node(char data = 0);
	char m_cData;
	bool m_bIsVisited;  //记录该节点是否已被访问

};


#endif
