// BeautifulString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <utility>
//大量数据输入，如果用cin实现，会占用大量时间，用scanf可以节约时间
char s[10000005];
using namespace std;
int main()
{

	int m = 0; cin >> m;
	for(int i = 0; i < m; i ++)
	{
		pair<char, int>beauty[3];
		for(int i = 0; i < 3; i ++)
		{
			beauty[i].first = 200;
			beauty[i].second = 0;
		}
		int n = 0; cin >> n;
		scanf("%s",s);
		int flag = 0;
		for(int j = 0, k = 0; j < n; j ++)
		{
			if(beauty[k].first == s[j]) 
			{
				beauty[k].second ++;
			}
			else if(beauty[k].first == s[j] - 1 && k < 2) 
			{
				k ++; 
				beauty[k].first = s[j]; beauty[k].second = 1;
			}
			else if(beauty[k].first == s[j] - 1)
			{
				beauty[0] = beauty[1]; 
				beauty[1] = beauty[2];
				beauty[2].first = s[j]; beauty[2].second = 1;
			}
			else 
			{
				k = 0;beauty[k].first = s[j]; beauty[k].second  = 1;
				beauty[1].second = 0; beauty[2].second = 0;
			}
			if(k == 1 && beauty[1].second > beauty[0].second) 
			{
				beauty[0] = beauty[1]; 
				k = 0;
			}
			else if(k == 2 && beauty[2].second == beauty[1].second )
			{
				cout << "YES" << endl;
				flag = 1;
				break;
			}
		}
		if(!flag) cout << "NO" << endl;
	}
	return 0;
}


// BeautifulString.cpp : 定义控制台应用程序的入口点。
//
/*
#include "stdafx.h"
#include <iostream>
#include <string>
#include <utility>


using namespace std;
char s[10000005];
int main()
{

	int m = 0; cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int beauty[3][255];
		for(int j = 0; j < 3; j ++)
			for(int k = 0; k < 255; k ++)
				beauty[j][k] = 0;
		int n = 0; cin >> n;
			scanf("%s",s);
		int flag = 0;
		char cur = 200;
		for(int j = 0, k = 0; j < n; j ++)
		{
			if(cur == s[j])
				beauty[k][cur] ++;
			else if(cur == s[j] - 1 && k < 2)
				beauty[++k][++cur] = 1;
			else if(cur == s[j] - 1)
			{
				beauty[k - 2][cur - 1] = beauty[k - 1][cur - 1];
				beauty[k - 1][cur] = beauty[k][cur];
				cur ++;
				beauty[k][cur] = 1;
			}
			else
			{
				for(;k >=0;)
				{
					beauty[k --][cur --] = 0;
				}
				k = 0; cur = s[j];
				beauty[0][cur] = 1;
			}
			if(k == 1 && beauty[1][cur] > beauty[0][cur-1]) 
			{
				beauty[0][cur] = beauty[1][cur]; 
				k = 0;
			}
			else if(k == 2 && beauty[2][cur] == beauty[1][cur-1] )
			{
				cout << "YES" << endl;
				flag = 1;
				break;
			}
		}
		if(!flag) cout << "NO" << endl;
	}
	return 0;
}

*/