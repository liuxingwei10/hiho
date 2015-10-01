// DeleteCharacter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include<vector>  

using namespace std;  
string GetString(const string& str)  
{  
    int len=str.size();  
    if(len<=1)  
        return str;  
    vector<char> v;  
      
    for(int i=0;i+1<len;++i)  
    {  
        if(str[i]==str[i+1])  
        {  
            while(i+1<len&&str[i]==str[i+1])  
                ++i;  
        }  
        else  
            v.push_back(str[i]);  
    }  
    //最后一个元素  
    if(str[len-2]!=str[len-1])  
        v.push_back(str[len-1]);  
  
  
        return string(v.begin(),v.end());  
}  
int GetLongestPalindromicSubstring(const string& s)
{
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
	return max - 1;

}
//最开始的思路是，先消除，后添加再消除，然而这种做法的正确性无法证明，事实证明是错的。所以还是应该遍历，算法时间复杂度应该很高

int main()  
{  
    int n;  
    string s;  
    cin>>n;  
	string spre;
	string Insert = "ABC";
    while(n--)  
    {  
        cin>>s;  
		spre = GetString(s);
		
		int len = spre.size();
		while(len>(spre=GetString(spre)).size())  
		{  
			len=spre.size();  
		} 
		cout << spre << endl;
		cout<< s.size() - spre.size() + GetLongestPalindromicSubstring(spre) + 1 <<endl;  
		int max=s.size();  
        //s=GetString(s);  
        int min=s.size();  
        /* 
        while(min>GetString(s).size()) 
        { 
            s=GetString(s); 
            min=s.size(); 
        } 
        */  
        string test;  
        for(int i=0;i<s.size();++i)  
        {  
            for(int j=0;j<3;++j)  
            {  
                string str=s.substr(0,i+1)+Insert[j]+s.substr(i+1);  
                int len=str.size();  
                while(len>(str=GetString(str)).size())  
                {  
                    len=str.size();  
            
                }  
                if(min>str.size())  
				{
                    min=str.size();
					test = str;
				}
            }  
        }  
        cout << test << endl; 
        cout<<max-min+1<<endl;  
    }     
        return 0;  
}  


