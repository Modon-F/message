#include <iostream>
using namespace std;

int main1(void)
{
	//引用基本语法
	//数据类型 &别名 = 原名

	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << a << endl;
	system("pause");
	return 0;
}