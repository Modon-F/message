#include <iostream>
using namespace std;

// ����: ���õı�����c++�ڲ�ʵ����һ��ָ�볣��

void func(int& ref)
{
	ref = 100;
}

int main5(void)
{
	int a = 10;
	//�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸ�,Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref = a;
	ref = 20; // �ڲ�����ref������,�Զ�������ת��Ϊ"*ref = 20;"

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);

	return 0;
}