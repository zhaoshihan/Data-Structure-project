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

		//iterator����Ĳ���������
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

		// �ж�iterator�Ƿ񵽴�ĩβ
		bool end() const {
			return this->cur == nullptr;
		}

		// Dereference operator
		Term *operator*() const {
			return this->cur;
		}
	};

	// iterator�ص�Polynomial��ʼ����ߴ��
	Iterator iterate() const {
		return{ this->head };
	}

	// Default ctor
	Polynomial() = default;

	// Copy ctor  �������캯�����ڡ��������ֵ���ݴ��뺯������/��Ϊ����ֵ/��ʼ����һͬ�����ʱʹ��
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
		ͨ�׵���ֵ�Ķ�����Ƿ���ʱ������Щ�����ڶ��������ʹ�õĶ���,
		���еı���������������壬�ڶ��������ж�����ʹ�ã�������ֵ��
		��ֵ��ָ��ʱ�Ķ�������ֻ�ڵ�ǰ���������Ч
	*/

	/*
		��ֵ��ת�Ʋ�����move�����Ա��⿽��������û���������Դ������ͷŵĲ�����
		���������Զ���������ֵ����ֵ������ֵ������ת�ƹ��캯����ת�Ƹ�ֵ����������ʡ����Դ������˳������е�Ч�ʡ�
	}
	*/
	// Move ctor ��ֵ���á�&�����Ƕ�����/��������ֵ���á�&&�����Ƕ����ֵ
	// Yeah! it's movable. ת�ƹ��캯��
	//Polynomial(Polynomial && other) {
	//	std::swap(this->head, other.head);
	//	std::cout << "***Polynomial Constructor Rvalue is called.***" << std::endl;
	//}

	// Move assignment ת�Ƹ�ֵ������
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
		int num;  // int���ͱ�����ֹ��������
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

	//������addTerm�����Ĵ���
	void addTerm(int cof, int exp) {
		auto it = iterate();

		if (cof == 0) {
			// ϵ��Ϊ��ֱ�ӷ���
			return;
		}

		if (it.end()) {
			// ��linked listΪ��
			this->head = new Term{ cof, exp, nullptr };

		}
		else if ((*it)->exp < exp) {
			// ������������ʱ���ŵ���ǰ����Զ��֤�������У�
			this->head = new Term{ cof, exp, this->head };

		}
		else {
			// �м��������
			// �Ƚ���ѭ������Υ������ʱ�����֧�ж�
			while ((*it)->exp > exp && !(it + 1).end() && (*(it + 1))->exp >= exp) {
				it++;
			}

			if ((*it)->exp == exp) { // �պô���ָ�����������ͬ��ϵ�����
				(*it)->cof += cof;

			}
			else if ((it + 1).end()) { // ����linked list��󣬼�������ϵ����С,�ŵ����
				(*it)->next = new Term{ cof, exp, nullptr };

			}
			else { // ǰ��ָ�����󣬺��ָ����С������������м�
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