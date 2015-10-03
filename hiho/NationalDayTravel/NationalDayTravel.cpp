// NationalDayTravel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
#include<iostream>  
#include<bitset>  
using namespace std;  
#define FFF 105  
int a[FFF],first[FFF],e,cnt = 0,num,Next[FFF*2],v[FFF*2];  
bitset<FFF> shao[FFF];//用bitset来存每个节点的子节点中能到达点的情况  
bool vis[FFF*2],ans;  
void addedge(int x,int y)  
{  
    v[e] = y; Next[e] = first[x];first[x] = e++;  
    v[e] = x; Next[e] = first[y];first[y] = e++;  
}  
  
void solve_can(int now,int fa)//处理出now节点的子树中能到达的点  
{  
    shao[now][now] = 1;//首先自身能到达自身位置  
    for(int k = first[now]; ~k;k = Next[k])  
    {  
        int val = v[k];  
        if(val == fa)  
            continue;  
        solve_can(val,now);//找出子节点的子树中能到达的点  
        shao[now] |= shao[val];//子节点能到达的点,当前点也能到,用bitset处理可以直接用或运算比较快捷  
    }  
    return;  
}  
  
void solve(int now,int fa)  
{  
    if(now == a[cnt])//访问到指定顺序的点,则准备访问下一个点  
    {  
        cnt++;  
    }  
    if(cnt == num)  
    {  
        ans = true;//所有点都访问完了,则说明最后可行  
        return;  
    }  
    while(cnt < num)  
    {  
        int tmp = cnt;  
        for(int k = first[now]; ~k;k = Next[k])  
        {  
            int val = v[k];  
            if(val == fa)  
                continue;  
            if(shao[val][a[cnt]] && !vis[k])//目标点可达且该条路没有访问过,则向下深搜  
            {  
                vis[k] = true;//标记路径已经访问过  
                solve(val,now);  
                break;  
            }  
        }  
        if(tmp == cnt)//假如当前节点无法到达指定顺序的点或者路径已访问过不能走则返回父节点继续深搜  
            break;  
    }  
    return;  
}  
  
int main()  
{  
    int keng;  
    scanf("%d",&keng);  
    while(keng--)  
    {  
        ans = false;  
        int x,y;  
        memset(first,-1,sizeof(first)); e = 0;  
        int n;  
        scanf("%d",&n);  
        for(int i = 1;i < n;i++)  
        {  
            scanf("%d%d",&x,&y);  
            addedge(x,y);  
        }  
  
        scanf("%d",&num);  
        for(int i = 0;i < num;i++)  
            scanf("%d",&a[i]);  
  
        for(int i = 1;i <= n;i++)  
            shao[i].reset();  
  
        solve_can(1,-1);//预处理每个点的子树能到达哪些点  
  
        memset(vis,false,sizeof(vis));  
        cnt = 0;//记录按顺序已经访问到第几个点  
        solve(1,-1);  
        if(ans)  
            printf("YES\n");  
        else  
            printf("NO\n");  
    }  
    return 0;  
}  
