#pragma once
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	//friend class ExtBinTree;   //声明一个类为自己的友元，即能让这个声明的类调用自己的私有成员和保护成员
	Node() = default;
	Node(char data, int key) {
		this->data = data;
		this->key = key;
	}

	char data;  //所有的Type都落在data的具体类型上
	double key;
	Node* leftChild;
	Node* rightChild;

};


class ExtBinTree {
public:
	Node* root;

	ExtBinTree() {
		root = new Node();
	}
	ExtBinTree(ExtBinTree & tree1, ExtBinTree & tree2) {   //两颗树的合并
		root = new Node();
		root->leftChild = tree1.root;
		root->rightChild = tree2.root;
		root->key = tree1.root->key + tree2.root->key;
	}
};


class MinHeap {
public:
	ExtBinTree* queue;
	vector<string> string_code;
	int length;  //目前实际有意义的长度
	int maxSize;  //申请时的内存长度

	MinHeap(int mSize = 20) {
		maxSize = length = mSize;
		queue = new ExtBinTree[length];
	}

	~MinHeap() {
		delete[] queue;
		queue = NULL;
	}
	//bool isEmpty() const { return length == 0; }
	//bool isFull() const { return length == maxSize; }

	void AdjustDown(int index) {	//index是需要向下排序的节点索引
		ExtBinTree temp = queue[index];
		int child = index * 2 + 1;
		while (child <= length-1)
		{
			if ((child < length - 1) && (queue[child].root->key > queue[child + 1].root->key)) {  //右子树更小，选它来跟当前node比较
				child++;
			}

			if (temp.root->key >= queue[child].root->key) {
				queue[(child - 1) / 2] = queue[child];
				//swap(queue[index], queue[child]);
				child = 2 * child + 1;
			}

			else {  //两个if一个else，则else遵循向上就近原则，这里就是只跟第二个if的相反情况，即：(temp.root->key < queue[child].root->key)
;				break;
			}
		}
		queue[(child - 1) / 2] = temp;  //此处有精妙，需仔细体味
	}

	void createHeap() {
		for (int i = (length-2) / 2; i >= 0; i--) {
			AdjustDown(i);  //从倒数第二层的分支节点下标开始调整
		}
		//printQueue();
	}

	ExtBinTree DeleteMin(int order) {
		if (order == 1) {	//第一次取最小值
			ExtBinTree root = queue[0];
			queue[0] = queue[length - 1];
			length--;
			AdjustDown(0);
			return root;
		}
		if (order == 2) {
			return queue[0];
		}

	}

	void Insert(ExtBinTree newtree) {
		queue[0] = newtree;
		AdjustDown(0);
	}

	void writeCode() {  //遍历的启动函数
		if (length == 1) {  //只剩一棵树时，进行遍历操作
			cout << "\nOne of the Huffman Code is:" << endl;
			Traversal(queue[0].root, "");
		}

	}

	void Traversal( Node* node,string str) {
		if (node->leftChild == NULL && node->rightChild == NULL) {
			cout << node->data <<": "<<str<<" "<<node->key <<endl;


			//记录此时的string值???????
		}
		else {
			if (node->leftChild != NULL) {
				this->Traversal(node->leftChild, str + "0");
			}
			if (node->rightChild != NULL) {
				this->Traversal(node->rightChild, str + "1");
			}
		}
	}

	void printQueue() {
		cout << "This is the queue status now: ";
		for (int i = 0; i < length; i++) {
			cout << queue[i].root->key << " ";
		}
		cout << endl;
	}

};

void HuffmanTree(char* data_array, double* key_array,int size) {   //数据，权重
	char** hcode = new char*[size];
	ExtBinTree first, second;
	ExtBinTree* Forest = new ExtBinTree[size];  //声明ExtBinTree数组
	MinHeap heap(size);	//小根堆

	for (int i = 0; i < size; i++) {  //初始化工作,数据和权值数组
		Forest[i].root->data = data_array[i];
		Forest[i].root->key = key_array[i];
		Forest[i].root->leftChild = Forest[i].root->rightChild = NULL;

		heap.queue[i] = Forest[i];

		//hcode[i] = new char[size];
		//memset(hcode[i], NULL, sizeof(char)*size);
		//hcode[i][0] = data_array[i];  //第一列表示要编码的字符
	}

	heap.createHeap();

	for (int i = 0; i < size - 1; i++) {  //进行n-1次操作，合并成一棵树
		first = heap.DeleteMin(1);
		second = heap.DeleteMin(2); 
		ExtBinTree newtree(first, second);
		heap.Insert(newtree);
	}

	heap.writeCode();



	//cout << "The final result is:" << endl;
	//for (int i = 0; i < size; i++) {  //输出并删除hcode
	//	cout << hcode[i][0] << ": ";
	//	for (int j = 1; j < size; j++) {
	//		cout << *(*(hcode + i) + j);
	//	}
	//	cout << endl;
	//	delete[] hcode[i];
	//}
	//delete[] hcode;

}

#endif
