#include <iostream>
using namespace std;

//��ӡ����
void show_value(const int& val) //������Ա��������ò����޸�
{
	//val = 1000;
	cout << val << endl;
	return;
}

int main6(void)
{
	//��������
	//ʹ�ó���:���������β�,��ֹ�����

	int a = 10;
	//int& ref = 10; ���ñ�������һ��Ϸ����ڴ�ռ�

	const int& ref = a;

	//ref = 20; ����const֮���Ϊֻ�������޸�

	int b = 100;
	show_value(b);

	b = 200;
	show_value(b);

	system("pause");
	return 0;
}