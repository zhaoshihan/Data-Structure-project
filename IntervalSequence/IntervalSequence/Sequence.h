#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<iostream>
#include<vector>

using namespace std;
class Sequence
{
private:
	int size;  //һ��2n�������Ǹ�nֵ
	static vector<int> number;
	int* array;
	int* current;

public:
	Sequence(int);
	void printAll(vector<int> = number);
	~Sequence();
};


#endif // !SEQUENCE_H
