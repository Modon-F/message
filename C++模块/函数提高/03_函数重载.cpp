#include <iostream>
using namespace std;

/*
* ��������:
*	����:������������ͬ,��߸�����
* 
*	����������������:
*		ͬһ����������
*		����������ͬ
*		�����������Ͳ�ͬ ���� ������ͬ ���� ˳��ͬ
* 
*	ע��:
*		�����ķ���ֵ��������Ϊ�������ص�����
*/

int func()
{
	cout << "func�ĵ���" << endl;
	return 0;
}

//������ͬ
int func(int a)
{
	cout << "func(int a) �ĵ���" << endl;
	return 0;
}

//���Ͳ�ͬ
int func(double a)
{
	cout << "func(double a) �ĵ���" << endl;
	return 0;
}

//˳��ͬ
int func(double a, int b)
{
	cout << "func(double a, int b) �ĵ���" << endl;
	return 0;
}

//˳��ͬ
int func(int b, double a)
{
	cout << "func(int b, double a) �ĵ���" << endl;
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