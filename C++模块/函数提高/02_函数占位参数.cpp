#include <iostream>
using namespace std;

//ռλ����
/*
*	����ֵ���� ������ (��������) {}
*/

//Ŀǰ�׶ε�ռλ���� ���ǻ��ò���,����γ��л��õ�
//ռλ���� ��������Ĭ�ϲ���

int func(int a, int = 10) 
{
	cout << "this is func" << endl;
	return 0;
}

int main_02(void)
{
	func(10, 10);

	return 0;
}