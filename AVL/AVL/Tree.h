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
	unordered_map<BtNode*, int> height;  //����Ҫ�����õ���ӳ���

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
		if (node == nullptr) {  //���ж��Լ��Ƿ�Ϊ��(�����������)
			height[node] = -1;
			return true;
		}
		if (!isBalanced(node->leftchild)) { return false; }  //���ж����ҽڵ��Ƿ�ƽ��
		if (!isBalanced(node->rightchild)) { return false; }

		height[node] = max(height[node->leftchild], height[node->rightchild]) + 1;  //���������Ĳ���

		if (abs(height[node->leftchild] - height[node->rightchild]) <= 1) {  //�Լ��ж������Ƿ�����ƽ������
			return true;
		}
		else { return false; }
	}

};



#endif