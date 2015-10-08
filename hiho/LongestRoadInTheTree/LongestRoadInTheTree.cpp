// LongestRoadInTheTree.cpp : 定义控制台应用程序的入口点。
//

//第一种，非常聪明的做法，从任意节点出发，找到最长路径，并把最长路径上的节点标记出来
//然后从最长路径上得终点出发，找最长路径，这样就找到了整体的最长路径
/*#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h> 
using namespace std;
vector<int> a[100001];
bool visit[100001];
int MAX, flag;

void find(int u, int num)
{
	visit[u] = 1;
	if(a[u].size() == 1 && num > MAX)
	{
		MAX = num;
		flag = u;
	}
	for(int i = 0; i < a[u].size(); i++)
	{
		if(!visit[a[u][i]])
			find(a[u][i], num + 1);
	}
}

int main(void)
{
	int i, n, x, y;
	cin >> n;
	for(i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	find(1, 0);
	MAX = 0;
	memset(visit, 0, sizeof(visit));
	find(flag, 0);
	cout << MAX << endl;
}*/
//第二种方法，将树做后序遍历，找出每个节点的longest和second longest，同时更新max length
#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>

using namespace std;
vector<int> a[100001];
bool visit[100001];
vector<int> longest(100001,0);
vector<int> second_longest(100001,0);
int MAX;

void DFS(int root)
{
	stack<int> mystack;
	
	while(1)
	{
		if(!visit[root])
		{
			visit[root] = true;
			if(a[root].size() == 1 && visit[a[root][0]])
			{
				longest[root] = 0; second_longest[root] = 0;
				MAX = longest[root] + second_longest[root] > MAX ? longest[root] + second_longest[root] : MAX;
			}
			else
			{
				mystack.push(root);
				for(int i = a[root].size() - 1; i >= 0; i --)
				{
					if(!visit[a[root][i]])
						mystack.push(a[root][i]);
				}
			}
		}
		else
		{
			for(int i = 0; i < a[root].size(); i ++)
			{
				if(longest[a[root][i]] + 1 > longest[root])
				{
					second_longest[root] = longest[root];
					longest[root] = longest[a[root][i]] + 1;
				}
				else if(longest[a[root][i]] + 1 > second_longest[root])
				{
					second_longest[root] = longest[a[root][i]] + 1;
				}
			}
			MAX = longest[root] + second_longest[root] > MAX ? longest[root] + second_longest[root] : MAX;
		}
		if(mystack.empty()) break;
		root = mystack.top(); mystack.pop();
	}
}
int main(void)
{
	int i, n, x, y;
	cin >> n;
	for(i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS(1);
	cout << MAX << endl;
}

/*
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <queue>
#define N 100000+5

using namespace std;
int n, tail; //用tail来标记第一次bfs找到的叶子节点
bool vis[N];
int fa[N]; //用来记录路径长度的数组
vector<int>q[N];

void BFS_root(int s)
{
    int i, j;
    int len;
    queue<int>p;
    while(!p.empty())
        p.pop();
    p.push(s);
    vis[s]=true;
    while(!p.empty())
    {
        int dd=p.front();
        p.pop();
        len=q[dd].size();
        for(i=0; i<len; i++)
        {
            if(vis[q[dd][i]]==false )
            {
                fa[q[dd][i]]=fa[dd]+1;
                vis[q[dd][i]]=true;
                p.push(q[dd][i]);
            }
        }
    }
    //
    tail=1;
    int ff=fa[1];
    for(j=2; j<=n; j++)
    {
        if(fa[j]>ff)
        {
            ff=fa[j]; tail=j;
        }
    }
}
void BFS_len_tree(int s)
{
    int i, j;
    int len;
    queue<int>p;
    while(!p.empty())
        p.pop();
    vis[s]=true;
    p.push(s);
    while(!p.empty())
    {
        int dd=p.front();
        p.pop();
        len=q[dd].size();
        for(i=0; i<len; i++)
        {
            if(vis[q[dd][i]]==false )
            {
                fa[q[dd][i]]=fa[dd]+1;
                vis[q[dd][i]]=true;
                p.push(q[dd][i]);
            }
        }
    }
    int ans=fa[s];
    for(j=1; j<=n; j++)
    {
        if(fa[j]>ans)
            ans=fa[j];
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &n);
    int i, j;
    int u, v;
    for(i=0; i<=n; i++)
        q[i].clear();
    for(i=0; i<n-1; i++)
    {
        scanf("%d %d", &u, &v);
        q[u].push_back(v);
        q[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(fa, 0, sizeof(fa));
    BFS_root(1);

    memset(vis, false, sizeof(vis));
    memset(fa, 0, sizeof(fa));
    BFS_len_tree(tail);

    return 0;
}*/

