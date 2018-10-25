#include "stdafx.h"
#include<iostream>
using namespace std;

const int num[] = { 1,2,3,4};
const int N =sizeof num>>1;  //右移一位，相当于除以2. N=8
void dfs(int x, int depth, int co) {
	if (co <<1 == N) {
		int*stack = new int[ N>>1 ], sn = 0, *ans = new int[N <<1], ansn = 0;
		const int*now = num;
		for (int i = 0; i<N; ++i)
			x & 1 << i ? stack[sn++] = *now++ : ans[ansn++] = stack[--sn];
		for (int i = 0; i<ansn; ++i)
			cout<<ans[i];  //ans表示出栈顺序
		cout << endl;

		delete[]stack;
		delete[]ans;
		return;
	}
	if (depth == N)return;
	else {
		dfs(x | 1 << depth, depth + 1, co + 1);  //x前位添1
		if (co << 1 != depth)dfs(x, depth + 1, co);
	}
}
int main() {

	dfs(1, 1, 1);
}
