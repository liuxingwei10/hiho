// UnionFindSet.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int rep[100005];
int represent(int X)
{
	int temp = X;
	while(rep[X] != X)
	{
		temp = X;
		X = rep[X];
		rep[temp] = rep[X];
	}
	return X;
}
bool merge(int x, int y, int flag)
{
	int X = represent(x);
	int Y = represent(y);
	if(flag == 1 && X == Y) return true;
	else if(flag == 1) return false;
	else 
	{
		rep[Y] = X;
		return true;
	}
}
int main()
{
	int n = 0, c = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
		rep[i] = i;
	unordered_map<string, int> mymap;
	int count = 0;
	while(n--)
	{
		string s1, s2;
		cin >> c >> s1 >> s2;
		if(c == 1)
		{
			if(mymap.find(s1) == mymap.end() || mymap.find(s2) == mymap.end())
				cout << "no" << endl;
			else if(merge(mymap[s1], mymap[s2], c)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else 
		{
			if(mymap.find(s1) == mymap.end())
				mymap[s1] = count ++;
			if(mymap.find(s2) == mymap.end())
				mymap[s2] = count ++;
			merge(mymap[s1], mymap[s2], c);
		}
	}
	return 0;
}

