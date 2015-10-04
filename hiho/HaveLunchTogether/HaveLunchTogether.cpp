// HaveLunchTogether.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
const int MAX = 99999999;
using namespace std;
void bfs(vector<string>&input, int si, int sj,vector<vector<int>>& dis)
{
	queue<pair<int, int>> myqueue;
	int m = input.size(), n = input[0].size();
	vector<vector<int>> vis(m, vector<int>(n, 0));
	int curi = si, curj = sj;
	int step = 0;
	while(1)
	{
		if(curi - 1 >= 0 && input[curi - 1][curj] == '.' && vis[curi - 1][curj] == 0)
		{
			myqueue.push(make_pair(curi - 1, curj));
			dis[curi - 1][curj] = step + 1;
			vis[curi - 1][curj] = 1;
		}
		if(curi + 1 < m && input[curi + 1][curj] == '.' && vis[curi + 1][curj] == 0)
		{
			myqueue.push(make_pair(curi + 1, curj));
			dis[curi + 1][curj] = step + 1;
			vis[curi + 1][curj] = 1;
		}
		if(curj - 1 >= 0 && input[curi][curj - 1] == '.' && vis[curi][curj - 1] == 0)
		{
			myqueue.push(make_pair(curi, curj - 1));
			dis[curi][curj - 1] = step + 1;
			vis[curi][curj - 1] = 1;
		}
		if(curj + 1 < n && input[curi][curj + 1] == '.' && vis[curi][curj + 1] == 0)
		{
			myqueue.push(make_pair(curi, curj + 1));
			dis[curi][curj + 1] = step + 1;
			vis[curi][curj + 1] = 1;
		}
		if(curi - 1 >= 0 && input[curi - 1][curj] == 'S' && vis[curi - 1][curj] == 0)
		{
			dis[curi - 1][curj] = step + 1;
			vis[curi - 1][curj] = 1;
		}
		if(curi + 1 < m && input[curi + 1][curj] == 'S' && vis[curi + 1][curj] == 0)
		{
			dis[curi + 1][curj] = step + 1;
			vis[curi + 1][curj] = 1;
		}
		if(curj - 1 >= 0 && input[curi][curj - 1] == 'S' && vis[curi][curj - 1] == 0)
		{
			dis[curi][curj - 1] = step + 1;
			vis[curi][curj - 1] = 1;
		}
		if(curj + 1 < n && input[curi][curj + 1] == 'S' && vis[curi][curj + 1] == 0)
		{
			dis[curi][curj + 1] = step + 1;
			vis[curi][curj + 1] = 1;
		}
		if(myqueue.empty()) break;
		curi = myqueue.front().first; curj = myqueue.front().second;
		step = dis[curi][curj];
		myqueue.pop();
	}
	/*for(int i = 0; i < m; i ++)
	{
		for(int j = 0; j < n; j ++)
			cout << res[si][sj][i][j] << " ";
		cout << endl;
	}*/
}
int main()
{
	int m = 10, n = 10;
	cin >> m >> n;
	vector<string> input(m);
	for(int i = 0; i < m; i ++)
		cin >> input[i];
	vector<pair<pair<int, int>,pair<int, int>>> targets;
	pair<int, int> start;
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < n; j ++)
		{
			if(input[i][j] == 'S' && i > 0 && input[i - 1][j] == 'S')
				targets.push_back(make_pair(make_pair(i - 1, j), make_pair(i, j)));
			if(input[i][j] == 'S' && j > 0 && input[i][j - 1] == 'S')
				targets.push_back(make_pair(make_pair(i, j - 1), make_pair(i, j)));
			if(input[i][j] == 'H')
				start = make_pair(i, j);
		}
	int targets_num = targets.size();
	if(targets_num == 0) cout << "Hi and Ho will not have lunch." << endl;
	else
	{
		vector<vector<int>> dis(m, vector<int>(n, 0));
		bfs(input, start.first, start.second, dis);
		vector<int>length(targets_num,MAX);
		int minlength = MAX;
		int length1 = 0, length2 = 0;
		for(int i = 0; i < targets_num; i ++)
		{
			length1 = dis[targets[i].first.first][targets[i].first.second];
			length2 = dis[targets[i].second.first][targets[i].second.second];
			if(length1 != 0 && length2 != 0)
				length[i] = length1 + length2;
			if(minlength > length[i]) minlength = length[i];
		}
		if(minlength < MAX)
			cout << minlength << endl;
		else
			cout << "Hi and Ho will not have lunch." << endl;
	}
	return 0;
}

