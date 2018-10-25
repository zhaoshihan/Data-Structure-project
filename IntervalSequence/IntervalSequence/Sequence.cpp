#include "stdafx.h"
#include "Sequence.h"


Sequence::Sequence(int size)
{
	array = new int[size * 2];
	current = array;
	for (int i = 1; i <= size; i++) {
		number.push_back(i);
	}
}

void Sequence::printAll(vector<int> number)
{
	if (number.size() == 0) {
		for (int i = 0; i < size * 2; i++) {
			cout << array[i] << " ";
		}
	}

	else {
		for (vector<int>::iterator it = number.begin(); it != number.end(); ++it) {
			*current = *it;
			*(current + *it + 1) = *it;

			
			number.erase(it);
			printAll(number);
		}
	}
}

Sequence::~Sequence()
{
	delete[] array;
	array = nullptr;
	current = nullptr;
	number.clear();
}
