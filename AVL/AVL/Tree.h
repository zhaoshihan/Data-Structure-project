#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct BtNode
{
	char data;
	BtNode* leftchild;
	BtNode* rightchild;

	BtNode() = default;
	BtNode(char data) {
		this->data = data;
		leftchild = nullptr;
		rightchild = nullptr;
	}
};

class Tree {
public:
	BtNode* m_root;
	unordered_map<BtNode*, int> height;  //最重要的是用到了映射表

	Tree(char data) {
		m_root = new BtNode(data);
	}

	void Preorder(BtNode* node) {
		if (node == nullptr) {
			return;
		}
		cout << node->data<< " ";
		this->Preorder(node->leftchild);
		this->Preorder(node->rightchild);

	}
	
	void Inorder(BtNode* node) {
		if (node == nullptr) {
			return;
		}
		this->Preorder(node->leftchild);
		cout << node->data << " ";
		this->Preorder(node->rightchild);

	}


	bool isBalanced(BtNode* node) {
		if (node == nullptr) {  //先判断自己是否为空(特殊情况处理)
			height[node] = -1;
			return true;
		}
		if (!isBalanced(node->leftchild)) { return false; }  //再判断左右节点是否平衡
		if (!isBalanced(node->rightchild)) { return false; }

		height[node] = max(height[node->leftchild], height[node->rightchild]) + 1;  //最后是自身的操作

		if (abs(height[node->leftchild] - height[node->rightchild]) <= 1) {  //以及判断自身是否满足平衡因子
			return true;
		}
		else { return false; }
	}

};



#endif