// RectangularJudgement.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class line{
public:
	int x, y;
	int x1, y1, x2, y2;
	line(int xx1, int yy1, int xx2, int yy2):x1(xx1), y1(yy1), x2(xx2), y2(yy2)
	{
		y = y2 - y1;
		x = x2 - x1;
	}
	~line(){}

};
int point_multiplication(line l1,line l2)
{
	return l1.y * l2.y + l1.x * l2.x;
}
bool notzerolengthline(line l)
{
	if (l.x != 0 || l.y != 0)
		return true;
	else return false;
}
int line_connected(line l1, line l2)
{
	if(l1.x1 == l2.x1 && l1.y1 == l2.y1) return true;
	if(l1.x1 == l2.x2 && l1.y1 == l2.y2) return true;
	if(l1.x2 == l2.x1 && l1.y2 == l2.y1) return true;
	if(l1.x2 == l2.x2 && l1.y2 == l2.y2) return true;
	return false;
}
bool lines_closed(line l1, line l2, line l3, line l4)
{
	if(line_connected(l1,l2) + line_connected(l1, l3) + line_connected(l1, l4) == 2
		&& line_connected(l2,l1) + line_connected(l2, l3) + line_connected(l2, l4) == 2
		&& line_connected(l3,l1) + line_connected(l3, l2) + line_connected(l3, l4) == 2
		&& line_connected(l4,l1) + line_connected(l4, l2) + line_connected(l4, l3) == 2)
		return true;
	else return false;
}
bool isvertical(line l1, line l2, line l3, line l4)
{
	if(!line_connected(l1, l2)) return isvertical(l1, l3, l4, l2);
	if(!line_connected(l1, l3)) return isvertical(l1, l2, l4, l3);
	if(point_multiplication(l1,l2) == 0 && point_multiplication(l1, l3) == 0 && point_multiplication(l2, l4) == 0)
		return true;
	else 
	{
		//cout << point_multiplication(l1,l2) << point_multiplication(l1,l3) << point_multiplication(l2,l4) << endl;
		return false;
	}
}
int main(void)
{
	int n = 0;
	cin >> n;
	int x1,y1,x2,y2;
	for(int i = 0; i < n; i ++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		line l1(x1, y1, x2, y2);
		cin >> x1 >> y1 >> x2 >> y2;
		line l2(x1, y1, x2, y2);
		cin >> x1 >> y1 >> x2 >> y2;
		line l3(x1, y1, x2, y2);
		cin >> x1 >> y1 >> x2 >> y2;
		line l4(x1, y1, x2, y2);
		if(!(notzerolengthline(l1) && notzerolengthline(l2) && notzerolengthline(l3) && notzerolengthline(l4)))
			cout << "NO" <<endl;
		else 
		{
			if(!lines_closed(l1,l2,l3,l4))
				cout << "NO" << endl;
			else if(isvertical(l1,l2,l3,l4))
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}