#include <iostream>
using namespace std;

/*
* 函数重载:
*	作用:函数名可以相同,提高复用性
* 
*	函数重载满足条件:
*		同一个作用域下
*		函数名称相同
*		函数参数类型不同 或者 个数不同 或者 顺序不同
* 
*	注意:
*		函数的返回值不可以作为函数重载的条件
*/

int func()
{
	cout << "func的调用" << endl;
	return 0;
}

//个数不同
int func(int a)
{
	cout << "func(int a) 的调用" << endl;
	return 0;
}

//类型不同
int func(double a)
{
	cout << "func(double a) 的调用" << endl;
	return 0;
}

//顺序不同
int func(double a, int b)
{
	cout << "func(double a, int b) 的调用" << endl;
	return 0;
}

//顺序不同
int func(int b, double a)
{
	cout << "func(int b, double a) 的调用" << endl;
	return 0;
}

int main(void)
{
	func();
	func(10);
	func(8.1);
	func(3, 3.1);
	func(3.1, 3);

	return 0;
}