// LongestPalindromicSubstring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	int m = 0;
	cin >> m;
	for(; m > 0; m --)
	{
		string s; cin >> s;
		string pres;
        pres += "$#";
        for(int i = 0; i < s.size(); i++)
        {
            pres += s[i];
            pres += "#";
        }
		vector<int> v(pres.size(),0);
        int id,mx;
        mx = 0; id = 0;
        int max = 0;
        int posi = 0;
        for(int i = 0; i < pres.size(); i++)
        {
            if(mx > i)
                v[i] = v[2*id - i] < mx - i ? v[2*id - i] : mx - i;
            else v[i] = 1;
			while(i - v[i] >= 0 && i + v[i] < pres.size() && pres[i - v[i]] == pres[i + v[i]])
            {
                v[i] ++;
            }
            if(i + v[i] > mx)
            {
                mx = i + v[i];
                id = i;
            }
            if(max < v[i]) { max = v[i]; posi = i;}
        }
		cout << max - 1 << endl;
	}
	return 0;
}

