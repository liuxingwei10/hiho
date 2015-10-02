// ObtainManorOnAHorse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
 
int main()
{
    int n, m, L, l, r, t, b;
    cin >> n >> m >> L;
    cin >> l >> r >> b >> t;
    if (L >= 2 * (m + n))
    {
        cout << m*n - (r - l)*(t - b) << endl;
        return 0;
    }
    int l1, r1, t1, b1;
    l1 = l;
    r1 = r;
    t1 = t;
    b1 = b;
    if (l + r <= m)   
    {
        l1 = m - r;
        r1 = m - l;
    }
    if (t + b <= n)
    {
        t1 = n - b;
        b1 = n - t;
    }
    int ans = 0,X = 0, Y = 0;
    for (int i = 1; i < L / 2 && i <= m; i++)
    {
        for (int j = 1; j <= L / 2 - i&&j <= n; j++)
        {
            if (i <= l1 || j <= b1)
			{
                ans = ans >i*j ? ans : i*j;
				X = i; Y = j;
			}
            else if (i > l1 && i <= r1 && j > b1 && j <= t1)
			{
                ans = ans > i*j - (i - l1)*(j - b1) ? ans : i*j - (i - l1)*(j - b1);
				X = i; Y = j;
			}
            else if (i >= r1&&j >= t1)
			{
                ans = ans > i*j - (r - l)*(t - b) ? ans : i*j - (r - l)*(t - b);
				X = i; Y = j;
			}
			else
                continue;
        }
    }
 
    cout << ans << endl;
	cout << X << endl << Y << endl;
    //system(pause);
 
    return 0;
}
