// CompletePack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
int dp(vector<int>& need,vector<int> value, int M, int N)
{
	vector<vector<int>> res(M + 1, vector<int>(N + 1, 0));
	for(int i = 1; i < M + 1; i ++)
	{
		for(int j = 0; j < N + 1;j ++)
		{
			if(j >= need[i])
				res[i][j] = max((res[i][j - need[i]] + value[i]),res[i - 1][j]);
			else res[i][j] = res[i - 1][j];
		}
	}
	return res[M][N];
}
int main(void)
{
	int M = 0, N = 0;
	while(cin >> M >> N)
	{
		vector<int> need(M + 1, 0);
		vector<int> value(M + 1, 0);
		for(int i = 0; i < M ; i ++)
		{
			cin >> need[i+1] >> value[i+1];
		}
		cout << dp(need, value, M, N) << endl;
	}
	
	return 0;
}

