#include <iostream>
#include "stdafx.h"
#include "PolynomialArray.h"

PolynomialArray::PolynomialArray(int num) {
	this->length = num;
	this->cof_pointer = new int[num];
	this->exp_pointer = new int[num];
}

PolynomialArray::PolynomialArray(PolynomialArray & other) {
	std::swap(this->length, other.length);
	std::swap(this->cof_pointer, other.cof_pointer);
	std::swap(this->exp_pointer, other.exp_pointer);
	std::cout << "***Polynomial Constructor Lvalue is called.***" << std::endl;
}

void PolynomialArray::sorted() 
{
	for (int i = 0; i < length - 1; i++) {
		for(int j=0; j < length - 1; j++){
			if (exp_pointer[j] < exp_pointer[j + 1]) {
				std::swap(exp_pointer[j], exp_pointer[j + 1]);
				std::swap(cof_pointer[j], cof_pointer[j + 1]);
			}
			else if (exp_pointer[j] == exp_pointer[j + 1]) {
				exp_pointer[j + 1] = 0;
				cof_pointer[j] += cof_pointer[j + 1];
				cof_pointer[j + 1] = 0;
			}
		}
	}
}

void PolynomialArray::inputPoly() 
{
	using namespace std;
	int num;
	cout << "Please input the length of the Polynomial: " << endl;
	cin >> num;

	cof_pointer = new int[num];
	exp_pointer = new int[num];
	length = num;

	for (int i= 0; i < length; i++) {
		int cof, exp;
		cout << "input the coefficient and exponent for item: " << endl;
		cin >> cof >> exp;
		cof_pointer[i] = cof;
		exp_pointer[i] = exp;
	}
	sorted();
	cout << "This Polynomial is done! \n" << endl;
}

void PolynomialArray::outputPoly() {
	using namespace std;
	cout << "The whole Polynomial is: " << endl;
	int cof, exp;
	for (int i = 0; i < length; i++) {
		cof = cof_pointer[i];
		exp = exp_pointer[i];
		if (cof != 0) {
			cout << ((cof > 0) ? "+" : "") << cof;
			if (exp != 0) {
				cout << "*X^" << exp;
			}
		}
		
	}
	cout << endl;
}

//有关operator的重载，一般写在类内部
PolynomialArray& PolynomialArray::operator=(PolynomialArray & other) {
	std::swap(this->length, other.length);
	std::swap(this->cof_pointer, other.cof_pointer);
	std::swap(this->exp_pointer, other.exp_pointer);
	std::cout << "***Polynomial Operator = Lvalue is called.***" << std::endl;

	return *this;
}

PolynomialArray PolynomialArray::operator*(PolynomialArray& p2) {
	int new_length = this->length * p2.length;
	int new_cof, new_exp;
	PolynomialArray p(new_length);
	int index = 0;
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < p2.length; j++) {
			new_cof = this->cof_pointer[i] * p2.cof_pointer[j];
			new_exp = this->exp_pointer[i] + p2.exp_pointer[j];

			p.cof_pointer[index] = new_cof;
			p.exp_pointer[index] = new_exp;
			index++;
		}
	}
	p.sorted();
	return p;  //在此处调用拷贝构造函数
}

PolynomialArray::~PolynomialArray() {
	delete cof_pointer;
	delete exp_pointer;
}


//int main() {
//	using namespace std;
//	PolynomialArray ah, bh, ch;
//
//	ah.inputPoly();      //input polynomial a
//	ah.outputPoly();
//	bh.inputPoly();      //input polynomial b
//	bh.outputPoly();
//	ch = ah*bh;
//
//	cout << "\nThis result for multiply the two Polynomial is: " << endl;
//	ch.outputPoly();    //output the result
//
//	system("pause");
//	return 0;
//}