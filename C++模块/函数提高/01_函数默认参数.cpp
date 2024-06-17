#include <iostream>
using namespace std;

int func(int a, int b = 20, int c = 30) //以实参为准
{
	return a + b + c;
}

/*
* 注意事项:
*	1.如果某个位置已经有了默认参数,那么从这个位置往后,从左到右都必须有默认值
*	2.如果函数声明有默认参数,函数实现就不能有默认参数
*/

int main_01(void)
{
	int sum;

	sum = func(2);
	cout << sum << endl;

	return 0;
}