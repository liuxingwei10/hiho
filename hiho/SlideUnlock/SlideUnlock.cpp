// SlideUnlock.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int test[10][10],vis[10],depth,aim_depth,n,res,es[10][10];


int valid(int x,int y)
{
	if((test[x][y]||test[y][x])&&!vis[(x+y)/2])
	{
		return 0;
	}
	return 1;
}

void dfs(int x,int depth,int e)
{
	vis[x]=1;
	if(depth==aim_depth&&e==n)
	{
		++res;
		return;
	}

	for(int i=1;i<10;++i)
	{
		if(!vis[i])
		{
			if(!valid(x,i))
			{
				continue;
			}
			if(es[x][i])
			{
				dfs(i,depth+1,e+1);
			}
			else
			{
				dfs(i,depth+1,e);
			}
			vis[i]=0;
		}
	}    
}

int main()
{
	memset(test,0,sizeof(test));
	test[1][3]=test[3][1]=test[1][7]=test[7][1]=1;
	test[2][8]=test[8][2]=test[4][6]=test[6][4]=1;
	test[1][9]=test[9][1]=test[3][7]=test[7][3]=1;
	test[9][3]=test[3][9]=test[9][7]=test[7][9]=1;

	int k,m,i,j;
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		res=0;
		memset(vis,0,sizeof(vis));
		memset(es,0,sizeof(es));

		cin>>n;

		if(n==0)
		{
			cout<<389112<<endl;
			continue;
		}

		for(j=0;j<n;++j)
		{
			int a,b;
			cin>>a>>b;
			es[a][b]=es[b][a]=1;
		}

		aim_depth=max(4,n+1);

		for(;aim_depth<10;++aim_depth)
		{
			for(j=1;j<10;++j)
			{
				dfs(j,1,0);
				vis[j]=0;
			}            
		}
		cout<<res<<endl;

	}
	return 0;
}