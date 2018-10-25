/*
 * Polynomial.h
 *
 *  Created on: 2017��10��18��
 *      Author: Administrator
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include "Node.h"

struct Term{
	int coef;
	int exp;
	Term(int c, int e){
		coef = c;
		exp = e;
	}
};

class Polynomial{
	public:
		void polynomial_add(Polynomial *, int, int);
		friend Polynomial & operator *(Polynomial &, Polynomial &);
	private:
		Node<Term> poly;
};



#endif /* POLYNOMIAL_H_ */
