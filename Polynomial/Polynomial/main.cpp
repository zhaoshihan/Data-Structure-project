#include "stdafx.h"
#include <iostream>

struct Term {
	int cof;
	int exp;
	Term *next;
};

class Polynomial {

	Term *head = nullptr;

public:

	// Iterator for this class
	struct Iterator {
		Term *cur;

		//iterator里面的操作符重载
		Iterator operator+=(size_t step) {
			for (; step > 0; step--) {
				this->cur = this->cur->next;
			}
			return{ this->cur };
		}

		Iterator operator+(size_t step) const {
			Term *cur = this->cur;
			for (; step > 0; step--) {
				cur = cur->next;
			}
			return{ cur };
		}

		// Prefix ++
		Iterator &operator++() {
			(*this) += 1;
			return *this;
		}

		// Postfix ++
		Iterator operator++(int) {
			Iterator it = *this;
			++(*this);
			return it;
		}

		// 判断iterator是否到达末尾
		bool end() const {
			return this->cur == nullptr;
		}

		// Dereference operator
		Term *operator*() const {
			return this->cur;
		}
	};

	// iterator回到Polynomial起始（最高次项）
	Iterator iterate() const {
		return{ this->head };
	}

	// Default ctor
	Polynomial() = default;

	// Copy ctor  拷贝构造函数，在“类对象以值传递传入函数参数/作为返回值/初始化另一同类对象”时使用
	// Oops! our polynomial isn't copyable yet.
	Polynomial(Polynomial & other) {
		std::swap(this->head, other.head);
		std::cout << "***Polynomial Constructor Lvalue is called.***" << std::endl;
	}

	// Copy assignment
	Polynomial &operator=(Polynomial & other) {
		std::swap(this->head, other.head);
		std::cout << "***Operator = Constructor Lvalue is called.***" << std::endl;
		return *this;
	}

	/*
		通俗的左值的定义就是非临时对象，那些可以在多条语句中使用的对象,
		所有的变量都满足这个定义，在多条代码中都可以使用，都是左值。
		右值是指临时的对象，它们只在当前的语句中有效
	*/

	/*
		右值的转移操作（move）可以避免拷贝操作中没有意义的资源申请和释放的操作。
		编译器会自动区分了左值和右值，对右值调用了转移构造函数和转移赋值操作符。节省了资源，提高了程序运行的效率。
	}
	*/
	// Move ctor 左值引用“&”的是对象本身/变量，右值引用“&&”的是对象的值
	// Yeah! it's movable. 转移构造函数
	//Polynomial(Polynomial && other) {
	//	std::swap(this->head, other.head);
	//	std::cout << "***Polynomial Constructor Rvalue is called.***" << std::endl;
	//}

	// Move assignment 转移赋值操作符
	//Polynomial &operator=(Polynomial && other) {
	//	std::swap(this->head, other.head);
	//	std::cout << "***Operator = Constructor Rvalue is called.***" << std::endl;
	//	return *this;
	//}

	// Dtor
	~Polynomial() {
		auto it = iterate();
		while (!it.end())
		{
			auto term = *it;
			it++;
			delete term;
		} 
	}

	void inputPoly() {
		using namespace std;
		int num;  // int类型变量防止恶意输入
		cout << "This is for inputing one Polynomial." << endl;
		cout << "How many terms do you want to add?" << endl;
		cin >> num;

		for (num; num > 0; num--) {
			int cof, exp;
			cout << "Enter coefficient and exponent." << endl;
			cin >> cof >> exp;
			this->addTerm(cof, exp);
		}
	}

	void outputPoly(const char variable = 'x') {
		using namespace std;

		for (auto it = iterate(); !it.end(); it++) {
			cout << ((*it)->cof > 0 ? "+" : "") << (*it)->cof;
			if ((*it)->exp != 0)
				cout << variable << "^" << (*it)->exp;
		}
		cout << endl;
	}

	//核心是addTerm函数的处理
	void addTerm(int cof, int exp) {
		auto it = iterate();

		if (cof == 0) {
			// 系数为空直接返回
			return;
		}

		if (it.end()) {
			// 本linked list为空
			this->head = new Term{ cof, exp, nullptr };

		}
		else if ((*it)->exp < exp) {
			// 插入项次数最高时，放到最前（永远保证降序排列）
			this->head = new Term{ cof, exp, this->head };

		}
		else {
			// 中间插入的情况
			// 先进行循环，当违反条件时进入分支判断
			while ((*it)->exp > exp && !(it + 1).end() && (*(it + 1))->exp >= exp) {
				it++;
			}

			if ((*it)->exp == exp) { // 刚好存在指数与插入项相同，系数相加
				(*it)->cof += cof;

			}
			else if ((it + 1).end()) { // 到达linked list最后，即插入项系数最小,放到最后
				(*it)->next = new Term{ cof, exp, nullptr };

			}
			else { // 前驱指数更大，后继指数更小，插入项放在中间
				(*it)->next = new Term{ cof, exp, *(it + 1) };
			}
		}
	}




};

Polynomial operator*(const Polynomial &p1, const Polynomial &p2) {
	Polynomial p;

	for (auto it1 = p1.iterate(); !it1.end(); it1++) {
		for (auto it2 = p2.iterate(); !it2.end(); it2++) {
			p.addTerm((*it1)->cof * (*it2)->cof, (*it1)->exp + (*it2)->exp);
		}
	}
	return p;
}

int main() {
	using namespace std;
	Polynomial ah, bh, ch;

	ah.inputPoly();      //input polynomial a
	ah.outputPoly();
	bh.inputPoly();      //input polynomial b
	bh.outputPoly();
	ch = ah*bh;

	cout << "\nThis result for multiply the two Polynomial is: " << endl;
	ch.outputPoly();    //output the result

	system("pause");
	return 0;
}