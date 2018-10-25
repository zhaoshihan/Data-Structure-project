// ArrayToCompleteBT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

//分割字符串的模板
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
		char data = it->front();  //因为只输入一个char，所以每个string取第一个字符

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

