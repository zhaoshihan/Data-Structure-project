#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<iostream>
#include<vector>

using namespace std;
class Sequence
{
private:
	int size;  //一共2n个数的那个n值
	static vector<int> number;
	int* array;
	int* current;

public:
	Sequence(int);
	void printAll(vector<int> = number);
	~Sequence();
};


#endif // !SEQUENCE_H
