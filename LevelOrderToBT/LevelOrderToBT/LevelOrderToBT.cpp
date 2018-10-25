// LevelOrderToBT.cpp : 定义控制台应用程序的入口点。
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
	cout << "Please input the whole level-order sequence. Seperate items by one space" << endl;
	cout << "Such as 'A B(A) C(A) D(BR) E(C) F(C) G(E) H(E)'" << endl;
	
	string input;
	getline(cin, input);


	Tree* tree = nullptr;
	vector<string> step = split(input, ' ');  //以空格符分割字符串，返回vector 

	for (vector<string>::iterator it = step.begin(); it != step.end(); ++it) {
		cout << *it << ";";
		// 将命令解析为三个变量：
		char content = it->front();
		char destionation;

		if (it->size() == 1) {
			tree = new Tree(content);
		}
		else if (it->size() == 4) {
			destionation = it->at(2);
			Node* node = new Node(content);
			tree->AddNode(destionation, node);
		}
		else if (it->size() == 5) {  //这里使用的弱判断，并没有考察'R'的输入是否符合语法规范
			destionation = it->at(2);
			Node* node = new Node(content);
			tree->AddNode(destionation, node, 1);
		}
		else {
			cout << "\nYour input format has error!!!" << endl;
			break;
		}
	}
	cout << endl;


	tree->PreorderTraversal();
	std::system("pause");
    return 0;
}

