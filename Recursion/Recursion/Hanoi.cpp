#include "stdafx.h"
#include <iostream>

using namespace std;
void Hanoi(int number, char start, char medial, char destination)
{
	if (number == 1)
	{
		cout << "1st from " << start << " move the disk to " << destination <<endl;
	}
	else
	{
		Hanoi(number - 1, start, destination, medial);
		cout << number << "th from " << start << " move the disk to " << destination<<endl;
		Hanoi(number - 1, medial, start, destination);
	}

}

//int main() {
//	Hanoi(4, 'A', 'B', 'C');
//
//
//	system("pause");
//	return 0;
//}
