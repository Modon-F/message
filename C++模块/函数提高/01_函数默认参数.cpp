#include <iostream>
using namespace std;

int func(int a, int b = 20, int c = 30) //��ʵ��Ϊ׼
{
	return a + b + c;
}

/*
* ע������:
*	1.���ĳ��λ���Ѿ�����Ĭ�ϲ���,��ô�����λ������,�����Ҷ�������Ĭ��ֵ
*	2.�������������Ĭ�ϲ���,����ʵ�־Ͳ�����Ĭ�ϲ���
*/

int main_01(void)
{
	int sum;

	sum = func(2);
	cout << sum << endl;

	return 0;
}