#pragma once
#ifndef POLYNOMIALARRAY_H_
#define POLYNOMIALARRAY_H_

#include "stdafx.h"
#include <iostream>
#include <string>
class PolynomialArray
{
private:
	int length = 0;
	int* cof_pointer = nullptr; //ϵ��ָ�� coefficient
	int* exp_pointer = nullptr; //ָ��ָ�� exponent
public:
	PolynomialArray() = default;
	PolynomialArray(int);
	PolynomialArray(PolynomialArray &);
	void sorted();
	void inputPoly();
	void outputPoly();
	PolynomialArray operator*(PolynomialArray&);
	PolynomialArray &operator=(PolynomialArray &);
	~PolynomialArray();
};




#endif /* NODE_H_ */