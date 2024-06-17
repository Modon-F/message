#include <iostream>
using namespace std;

//	交换函数

//	1.值传递
void my_swap01(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "swap01: a = " << a << endl;
	cout << "swap01: b = " << b << endl;
}

// 2.地址传递
void my_swap02(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	cout << "swap02: a = " << *a << endl;
	cout << "swap02: b = " << *b << endl;
}

// 3.引用传递
void my_swap03(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "swap03: a = " << a << endl;
	cout << "swap03: b = " << b << endl;
}

int main3(void)
{
	int a = 10;
	int b = 20;

	my_swap01(a, b);				//值传递,形参不会修饰实参
	cout << " a = " << a << endl;
	cout << " a = " << b << endl;

	my_swap02(&a, &b);				//地址传递,形参会修饰实参
	cout << " a = " << a << endl;
	cout << " a = " << b << endl;

	my_swap03(a, b);				//引用传递,形参会修饰实参
	cout << " a = " << a << endl;
	cout << " a = " << b << endl;
	
	return 0;
}