#pragma once
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	//friend class ExtBinTree;   //����һ����Ϊ�Լ�����Ԫ�����������������������Լ���˽�г�Ա�ͱ�����Ա
	Node() = default;
	Node(char data, int key) {
		this->data = data;
		this->key = key;
	}

	char data;  //���е�Type������data�ľ���������
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
	ExtBinTree(ExtBinTree & tree1, ExtBinTree & tree2) {   //�������ĺϲ�
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
	int length;  //Ŀǰʵ��������ĳ���
	int maxSize;  //����ʱ���ڴ泤��

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

	void AdjustDown(int index) {	//index����Ҫ��������Ľڵ�����
		ExtBinTree temp = queue[index];
		int child = index * 2 + 1;
		while (child <= length-1)
		{
			if ((child < length - 1) && (queue[child].root->key > queue[child + 1].root->key)) {  //��������С��ѡ��������ǰnode�Ƚ�
				child++;
			}

			if (temp.root->key >= queue[child].root->key) {
				queue[(child - 1) / 2] = queue[child];
				//swap(queue[index], queue[child]);
				child = 2 * child + 1;
			}

			else {  //����ifһ��else����else��ѭ���Ͼͽ�ԭ���������ֻ���ڶ���if���෴���������(temp.root->key < queue[child].root->key)
;				break;
			}
		}
		queue[(child - 1) / 2] = temp;  //�˴��о������ϸ��ζ
	}

	void createHeap() {
		for (int i = (length-2) / 2; i >= 0; i--) {
			AdjustDown(i);  //�ӵ����ڶ���ķ�֧�ڵ��±꿪ʼ����
		}
		//printQueue();
	}

	ExtBinTree DeleteMin(int order) {
		if (order == 1) {	//��һ��ȡ��Сֵ
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

	void writeCode() {  //��������������
		if (length == 1) {  //ֻʣһ����ʱ�����б�������
			cout << "\nOne of the Huffman Code is:" << endl;
			Traversal(queue[0].root, "");
		}

	}

	void Traversal( Node* node,string str) {
		if (node->leftChild == NULL && node->rightChild == NULL) {
			cout << node->data <<": "<<str<<" "<<node->key <<endl;


			//��¼��ʱ��stringֵ???????
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

void HuffmanTree(char* data_array, double* key_array,int size) {   //���ݣ�Ȩ��
	char** hcode = new char*[size];
	ExtBinTree first, second;
	ExtBinTree* Forest = new ExtBinTree[size];  //����ExtBinTree����
	MinHeap heap(size);	//С����

	for (int i = 0; i < size; i++) {  //��ʼ������,���ݺ�Ȩֵ����
		Forest[i].root->data = data_array[i];
		Forest[i].root->key = key_array[i];
		Forest[i].root->leftChild = Forest[i].root->rightChild = NULL;

		heap.queue[i] = Forest[i];

		//hcode[i] = new char[size];
		//memset(hcode[i], NULL, sizeof(char)*size);
		//hcode[i][0] = data_array[i];  //��һ�б�ʾҪ������ַ�
	}

	heap.createHeap();

	for (int i = 0; i < size - 1; i++) {  //����n-1�β������ϲ���һ����
		first = heap.DeleteMin(1);
		second = heap.DeleteMin(2); 
		ExtBinTree newtree(first, second);
		heap.Insert(newtree);
	}

	heap.writeCode();



	//cout << "The final result is:" << endl;
	//for (int i = 0; i < size; i++) {  //�����ɾ��hcode
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
