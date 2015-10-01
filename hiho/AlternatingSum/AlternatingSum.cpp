// AlternatingSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>  
#include<string>  
#include <cstring>
  
using namespace std;  
  
const int M=1000000007;  
struct my  
{  
    long long s,n;  
}dp[22][222];  
int bit[22],bt;  
long long base[22];  
int y;  
  
my dfs(long long pos,int target,bool limit)  
{  
    //cout<<pos<<' '<<target<<' '<<limit<<endl;  
    my t;  
    t.n=t.s=0;  
    if (pos==0)  
    {  
        if (target==100) t.n=1;  
        return t;  
    }  
    if (!limit && dp[pos][target].n!=-1) return dp[pos][target];  
    int tail=limit?bit[pos]:9;  
    int head= y==pos?1:0;  
    int sgn=((y-pos)&1)?-1:1;  
    for (int i=head;i<=tail;i++)  
    {  
        my cur=dfs(pos-1,target-sgn*i,limit&&i==bit[pos]);  
        if (cur.n)  
        {  
            t.n+=cur.n;  
            long long p=((((cur.n%M)*i)%M)*base[pos])%M;  
            t.s+=p;  
            t.s%=M;  
            t.s+=cur.s;  
            t.s%=M;  
        }  
    }  
    if (!limit) dp[pos][target]=t;  
    return t;  
}  
  
long long make(long long x,int k)  
{  
    if (x<=0) return 0;  
    long long ans=0;  
    bt=0;  
    while (x)  
    {  
        bit[++bt]=x%10;  
        x/=10;  
    }  
    for (y=1;y<=bt;y++)  
    {  
        memset(dp,-1,sizeof(dp));  
        ans+=dfs(y,k+100,y==bt).s;  
        ans%=M;  
    }  
    return ans;  
}  
  
int main()  
{  
    //freopen("in","r",stdin);  
    long long l,r;  
    int k;  
    base[1]=1;  
    for (int i=2;i<22;i++)   base[i]=(base[i-1]*10)%M;  
    while (cin>>l>>r>>k)  
    {  
         cout<<(make(r,k)-make(l-1,k)+M)%M<<endl;  
    }  
}  