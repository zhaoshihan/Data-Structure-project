# include "stdafx.h"
# include <iostream>
using namespace std;

class CExample
{
private:
	int a;

public:
	//���캯��  
	CExample(int b){
		a = b;
		cout << "creat: " << a << endl;
	}

	//��������  
	CExample(const CExample& C){
		a = C.a;
		cout << "copy" << endl;
	}

	//��������  
	~CExample(){
		cout << "delete: " << a << endl;
	}

	void Show(){
		cout << a << endl;
	}
};

//ȫ�ֺ�����������Ƕ���  
void g_Fun(CExample C)
{
	cout << "test" << endl;
}

int main()
{
	CExample test(1);
	//�������  
	g_Fun(test);

	system("pause");
	return 0;
}