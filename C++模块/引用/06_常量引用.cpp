#include <iostream>
using namespace std;

//打印数据
void show_value(const int& val) //单纯针对别名的引用不可修改
{
	//val = 1000;
	cout << val << endl;
	return;
}

int main6(void)
{
	//常量引用
	//使用场景:用来修饰形参,防止误操作

	int a = 10;
	//int& ref = 10; 引用必须引用一块合法的内存空间

	const int& ref = a;

	//ref = 20; 加入const之后变为只读不可修改

	int b = 100;
	show_value(b);

	b = 200;
	show_value(b);

	system("pause");
	return 0;
}