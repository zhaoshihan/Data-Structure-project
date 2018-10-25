// ArrayToCompleteBT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

//�ָ��ַ�����ģ��
template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}
std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}

int main()
{
	cout << "Please input the whole complete binary tree array sequence.Seperate each item by one space." << endl;
	cout << "Such as 'A B C D E F G'" << endl;

	string input;
	getline(cin, input);
	
	vector<string> items = split(input, ' ');

	Tree* tree = nullptr;
	int arrayIndex = 0;
	for (vector<string>::iterator it = items.begin(); it != items.end(); ++it) {
		char data = it->front();  //��Ϊֻ����һ��char������ÿ��stringȡ��һ���ַ�

		int nodeIndex = (arrayIndex - 1) / 2;
		int direction = (arrayIndex - 1) % 2;

		if (arrayIndex == 0) {
			tree = new Tree(data);
		}
		else {
			Node* node = new Node(arrayIndex, data);
			tree->AddNode(nodeIndex, direction, node);
		}

		arrayIndex++;
	}

	tree->PreorderTraversal();
	tree->InorderTraversal();

	//tree->DeleteNode(1, nullptr);
	//tree->PreorderTraversal();

	system("pause");
    return 0;
}

