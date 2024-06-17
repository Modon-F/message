#include <iostream>
using namespace std;

//	��������

//	1.ֵ����
void my_swap01(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "swap01: a = " << a << endl;
	cout << "swap01: b = " << b << endl;
}

// 2.��ַ����
void my_swap02(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	cout << "swap02: a = " << *a << endl;
	cout << "swap02: b = " << *b << endl;
}

// 3.���ô���
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

	my_swap01(a, b);				//ֵ����,�ββ�������ʵ��
	cout << " a = " << a << endl;
	cout << " a = " << b << endl;

	my_swap02(&a, &b);				//��ַ����,�βλ�����ʵ��
	cout << " a = " << a << endl;
	cout << " a = " << b << endl;

	my_swap03(a, b);				//���ô���,�βλ�����ʵ��
	cout << " a = " << a << endl;
	cout << " a = " << b << endl;
	
	return 0;
}