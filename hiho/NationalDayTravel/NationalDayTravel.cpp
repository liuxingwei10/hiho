// NationalDayTravel.cpp : �������̨Ӧ�ó������ڵ㡣
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
bitset<FFF> shao[FFF];//��bitset����ÿ���ڵ���ӽڵ����ܵ��������  
bool vis[FFF*2],ans;  
void addedge(int x,int y)  
{  
    v[e] = y; Next[e] = first[x];first[x] = e++;  
    v[e] = x; Next[e] = first[y];first[y] = e++;  
}  
  
void solve_can(int now,int fa)//�����now�ڵ���������ܵ���ĵ�  
{  
    shao[now][now] = 1;//���������ܵ�������λ��  
    for(int k = first[now]; ~k;k = Next[k])  
    {  
        int val = v[k];  
        if(val == fa)  
            continue;  
        solve_can(val,now);//�ҳ��ӽڵ���������ܵ���ĵ�  
        shao[now] |= shao[val];//�ӽڵ��ܵ���ĵ�,��ǰ��Ҳ�ܵ�,��bitset�������ֱ���û�����ȽϿ��  
    }  
    return;  
}  
  
void solve(int now,int fa)  
{  
    if(now == a[cnt])//���ʵ�ָ��˳��ĵ�,��׼��������һ����  
    {  
        cnt++;  
    }  
    if(cnt == num)  
    {  
        ans = true;//���е㶼��������,��˵��������  
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
            if(shao[val][a[cnt]] && !vis[k])//Ŀ���ɴ��Ҹ���·û�з��ʹ�,����������  
            {  
                vis[k] = true;//���·���Ѿ����ʹ�  
                solve(val,now);  
                break;  
            }  
        }  
        if(tmp == cnt)//���統ǰ�ڵ��޷�����ָ��˳��ĵ����·���ѷ��ʹ��������򷵻ظ��ڵ��������  
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
  
        solve_can(1,-1);//Ԥ����ÿ����������ܵ�����Щ��  
  
        memset(vis,false,sizeof(vis));  
        cnt = 0;//��¼��˳���Ѿ����ʵ��ڼ�����  
        solve(1,-1);  
        if(ans)  
            printf("YES\n");  
        else  
            printf("NO\n");  
    }  
    return 0;  
}  
