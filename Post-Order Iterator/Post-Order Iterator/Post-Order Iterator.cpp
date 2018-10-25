// Post-Order Iterator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <stack>

using namespace std;

template <class Type> 
struct BTNode {
	BTNode *left;
	Type data;
	BTNode *right;
	BTNode(Type x) {
		data = x;
		left = right = NULL;
	}
};

template <class Type> class PostOrder;

template <class Type> 
class BinaryTree {
private:
	BTNode<Type> *root;
	friend class PostOrder<Type>;
public:
	BinaryTree(BTNode<Type>*t) { root = t; }

};

//Base class for BT Iterator
template <class Type> 
class TreeIterator {
protected:
	const BinaryTree <Type> & T; //BT
	BTNode<Type> *current;
public:
	TreeIterator(const BinaryTree <Type> & BT)
		: T(BT), current(NULL) { }

	virtual ~TreeIterator() { }
	virtual void First() = 0;
	virtual void operator ++ () = 0;
	operator bool() { return current != NULL; }
	const Type operator()()const {  //重载括号，打印结果
		if (current)
			return current->data;
		return (Type)0;
	}
};



template <class Type> 
struct StkNode {
	//Stack node definition
	BTNode <Type> *Node;  //Node Address
	int PopTime;   //Counter
	StkNode(BTNode <Type> *N = NULL) : Node(N), PopTime(0) { }
};


template <class Type> 
class PostOrder : public TreeIterator <Type> {
	bool renew;
public:
	PostOrder(const BinaryTree <Type> & BT) :TreeIterator(BT) { 
		renew = false; 
	}
	~PostOrder() { }
	void First();
	//Seek to the first node in postorder traversal
	void operator ++ ();
	//Seek to the successor
protected:
	stack<StkNode<Type>> st;     //Active record stack
};

template <class Type>
void PostOrder<Type>::First() {
	current = T.root;
	stack<StkNode<Type>>().swap(st);
	renew = true;
	
	st.push(StkNode<Type>(current));  //放入root指针
	operator++();
}


template <class Type>
void PostOrder<Type>::operator ++() {
	if (!renew && current == T.root && st.empty()) {  //结束时的操作
		current = NULL;
		return;
	}
	renew = false;
	const BTNode<Type> *p = current;
	StkNode<Type> w;
	do {
		w = st.top();
		st.pop();
		w.PopTime++;
		if (w.PopTime == 2) {
			current = w.Node;  //第二次出栈：直接将值返回给current指针
			break;
		}
		else {
			st.push(w);  //第一次出栈：自己先入栈,再带左右孩子(先右后左)
			if (w.Node->right != NULL) {
				st.push(StkNode<Type>(w.Node->right));
			}
			if (w.Node->left != NULL) {
				st.push(StkNode<Type>(w.Node->left));
			}
		}

			// Here, you must add necessary statements to set pointer current to the right posotion

	} while (p != NULL || !st.empty());
}

int main() {
	BTNode<int> *p = new BTNode<int>(6);
	p->left = new BTNode<int>(4);
	p->right = new BTNode<int>(10);
	p->left->left = new BTNode<int>(2);
	p->right->left = new BTNode<int>(8);
	p->right->right = new BTNode<int>(12);
	BinaryTree<int> T(p);
	PostOrder<int> it(T);
	for (it.First(); it; ++it) {
		std::cout << it() << std::endl;
	}

	system("pause");
	return 0;
}
