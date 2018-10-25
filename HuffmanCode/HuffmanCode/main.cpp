#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct tree
{
	char data;
	tree *left;
	tree *right;
};


class Btree
{
public:
	tree * root;
	Btree()
	{
		root = NULL;
	}
	void create_Btree(string A)
	{

		int  t = A.length();
		if (t == 1)
		{
			tree* newnode = new tree;
			newnode->data = A.at(0);
			newnode->right = newnode->left = NULL;
			root = newnode;
			return;
		}


		if (t == 4)
		{
			tree* newnode = new tree;
			newnode->data = A.at(0);
			newnode->right = newnode->left = NULL;
			Search4(root, newnode, A);
			return;
		}

		if (t == 5)
		{
			tree* newnode = new tree;
			newnode->data = A.at(0);
			newnode->right = newnode->left = NULL;
			Search5(root, newnode, A);
			return;
		}
	}

	void Btree::Search4(tree* temp, tree* node, string a)//�������ַ�������Ϊ4ʱ�����´����ڵ�ĸ��ڵ�,�����´����Ľڵ���Ϊ���ڵ�����ӻ�����
	{
		if (temp != NULL)
		{
			if (temp->data == a.at(2))
			{
				if (temp->left == NULL)
				{
					temp->left = node;
					return;
				}
				else
				{
					temp->right = node;
					return;
				}

			}
			Search4(temp->left, node, a);
			Search4(temp->right, node, a);
		}
	}

	void Btree::Search5(tree* temp, tree* node, string a)//�������ַ�������Ϊ5ʱ�����´����ڵ�ĸ��ڵ㣬�����´����Ľڵ���Ϊ���ڵ�����ӻ�����
	{
		if (temp != NULL)
		{
			if (temp->data == a.at(2))
			{
				if (a.at(3) == 'L')
				{
					temp->left = node;
					//node = temp->left;
					return;
				}
				if (a.at(3) == 'R')
					temp->right = node;
					//node = temp->right;
				return;
			}
			Search5(temp->left, node, a);
			Search5(temp->right, node, a);
		}
	}



	void Btree::Preorder(tree *temp)    //������������������������˵ݹ�ķ�����
	{
		if (temp != NULL)
		{
			cout << temp->data << " ";
			Preorder(temp->left);
			Preorder(temp->right);
		}
		cout << endl;
	}
	void Btree::Inorder(tree *temp)      //������������������������˵ݹ�ķ�����
	{
		if (temp != NULL)
		{
			Inorder(temp->left);
			cout << temp->data << " ";
			Inorder(temp->right);
		}
		cout << endl;
	}
	void Btree::Postorder(tree *temp)     //���Ǻ�������������������˵ݹ�ķ�����
	{
		if (temp != NULL)
		{
			Postorder(temp->left);
			Postorder(temp->right);
			cout << temp->data << " ";
		}
		cout << endl;
	}

};



int main()
{
	int n;
	cout << "Please input the number of node in the binary tree" << endl;
	cin >> n;
	string* a = new string[n];
	cout << "Please input the sequence of the node:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}


	Btree B;
	for (int k = 0; k < n; k++)
	{
		B.create_Btree(a[k]);
	}
	cout << "�����������ɹ���" << endl;
	cout << "���Ƕ��������������" << endl;
	B.Inorder(B.root);
	cout << "���Ƕ�������ǰ�����" << endl;
	B.Preorder(B.root);
	cout << "���Ƕ������ĺ������" << endl;
	B.Postorder(B.root);
	delete[] a;
	system("pause");
}







