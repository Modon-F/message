#include <iostream>
using namespace std;

/*
*	1.���ñ����ʼ��
*	2.�����ڳ�ʼ����,�����Ըı�
*/

int main2(void)
{
	int a = 10;
	//int& b; //����,����Ҫ��ʼ��
	int& b = a;
	int c = 20;

	b = c;//��ֵ����,�����Ǹ�������

	cout << a << endl;  //20
	cout << b << endl;  //20
	cout << c << endl;  //20
	return 0;
}