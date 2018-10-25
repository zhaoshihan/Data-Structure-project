// IntervalSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void printAll(int* array, int insertNum, int endNum)
{
/*	bool signal = false;*/  //用signal作为boolean值返回，控制分支判断
	// 循环的是index，这里当注意边缘检测，直接控制循环次数不超过length - insertNum - 1.
	for (int i = 0; i < endNum * 2 - insertNum - 1; i++) {  //对每个数来考察，看应该怎么插入（遍尝所有可能）
		if (array[i] == 0 && array[i + insertNum + 1] == 0) {
			array[i] = insertNum;
			array[i + insertNum + 1] = insertNum;
			if (insertNum == endNum) {  // 已经遍历到了最后一个数
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
			array[i + insertNum + 1] = 0;  //不管成功与否，最后都清零（方便下一次循环尝试），只求输出不保存
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

