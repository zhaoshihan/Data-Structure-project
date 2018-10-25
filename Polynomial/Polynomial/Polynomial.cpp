//============================================================================
// Name        : Polynomial.cpp
// Author      : zsh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stdafx.h"
#include "Polynomial.h"
using namespace std;

//int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//
//	//Polynomial ah, bh, ch;
//	//ah.inputPoly();      //input polynomial a
//	//ah.outputPoly();
//	//bh.inputPoly();      //input polynomial b
//	//bh.outputPoly();
//	//ch = ah*bh;
//	//ch.outputPoly();    //output the result
//	//return 0;
//}

//Polynomial & operator*(Polynomial &ah, Polynomial &bh)
//{
//	//Node<Term> *pa, *pb, *pc, *p;
//
//	//ListIterator<Term> Aiter(ah.poly);
//	//ListIterator<Term> Biter(bh.poly);
//
//	//pa = pc = Aiter.First();
//	//pb = p = Biter.First();
//	//pa = Aiter.Next(); pb = Biter.Next();
//	//delete p;
//	// TODO: 在此处插入 return 语句
//}

//void polynomial_add(struct node **n1, int coefficient, int exponent) {
//	struct node *x = NULL, *temp = *n1;
//	if (*n1 == NULL || (*n1)->exponent < exponent) {
//		/* adding at the front */
//		*n1 = x = buildNode(coefficient, exponent);
//		(*n1)->next = temp;
//	}
//	else {
//		while (temp) {
//			if (temp->exponent == exponent) {
//				/* updating the co-efficient value  alone */
//				temp->coefficient = temp->coefficient + coefficient;
//				return;
//			}
//			if (temp->exponent > exponent && (!temp->next || temp->next->exponent < exponent)) {
//				/* inserting in the middle or end */
//				x = buildNode(coefficient, exponent);
//				x->next = temp->next;
//				temp->next = x;
//				return;
//			}
//			temp = temp->next;
//		}
//		x->next = NULL;
//		temp->next = x;
//	}
//}

void Polynomial::polynomial_add(Polynomial * n1, int exp, int cof)
{
	//struct Polynomial* temp = n1;
}
