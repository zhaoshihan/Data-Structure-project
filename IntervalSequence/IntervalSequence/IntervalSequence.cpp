// IntervalSequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void printAll(int* array, int insertNum, int endNum)
{
/*	bool signal = false;*/  //��signal��Ϊbooleanֵ���أ����Ʒ�֧�ж�
	// ѭ������index�����ﵱע���Ե��⣬ֱ�ӿ���ѭ������������length - insertNum - 1.
	for (int i = 0; i < endNum * 2 - insertNum - 1; i++) {  //��ÿ���������죬��Ӧ����ô���루�鳢���п��ܣ�
		if (array[i] == 0 && array[i + insertNum + 1] == 0) {
			array[i] = insertNum;
			array[i + insertNum + 1] = insertNum;
			if (insertNum == endNum) {  // �Ѿ������������һ����
				for (int i = 0; i < endNum * 2; i++) {
					cout << array[i] << " ";
				}
				cout << endl;
				//signal = true;
			}else {
				printAll(array, insertNum + 1, endNum);
				//if (!printAll(array, insertNum + 1, endNum)) {
				//	signal = false;
				//}
				//else {
				//	signal = true;
				//}
			}
			array[i] = 0;
			array[i + insertNum + 1] = 0;  //���ܳɹ����������㣨������һ��ѭ�����ԣ���ֻ�����������
		}
	}

	//return signal;
}

int main()
{
	int size=0;
	cout << "Please input the size: ";
	cin >> size;

	int* array = new int[size * 2]{0};

	printAll(array, 1, size);
	cout << "\nAbove are all the possible output." << endl;
	system("pause");
    return 0;
}

