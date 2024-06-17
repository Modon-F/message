#include <iostream>
using namespace std;

/*
*	1.引用必须初始化
*	2.引用在初始化后,不可以改变
*/

int main2(void)
{
	int a = 10;
	//int& b; //错误,必须要初始化
	int& b = a;
	int c = 20;

	b = c;//赋值操作,而不是更改引用

	cout << a << endl;  //20
	cout << b << endl;  //20
	cout << c << endl;  //20
	return 0;
}