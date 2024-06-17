#include <iostream>
using namespace std;

//1.不要返回局部变量的引用
int& test01()
{
	int a = 10;
	return a;
}
//2.函数的调用可以作为左值
int& test02()
{
	static int b = 100;  //静态变量,存放在全局去,全局区上的数据在程序结束后系统释放
	return b;
}

int main4(void)
{
	//1.不要返回局部变量的引用
	int& ref1 = test01();
	cout << ref1 << endl;  //这里体现不出来是因为编译器做出了优化,替我们保留了这个值 不然属于非法操作

	//2.函数的调用可以作为左值
	int& ref2 = test02();
	cout << ref2 << endl;
	test02() = 1000;		//这里体现函数的调用可以作为左值
	cout << ref2 << endl;
	
	return 0;
}