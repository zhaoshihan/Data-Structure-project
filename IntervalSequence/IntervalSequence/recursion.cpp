#include "stdafx.h"
#include <iostream>

using namespace std;

int Fibonacci(int x) {
	if (x == 0) {
		return 0;
	}
	else if(x == 1) {
		return 1;
	}
	else {
		return Fibonacci(x - 1) + Fibonacci(x-2);
	}
}

int main() {
	int size;

	cout << "Please input the Fibonacci size: ";
	cin >> size;
	for (int i = 0; i <= size; i++) {
		cout << Fibonacci(i) << ", ";
	}


	system("pause");
	return 0;
}
