#include <iostream>
using namespace std;

//1.��Ҫ���ؾֲ�����������
int& test01()
{
	int a = 10;
	return a;
}
//2.�����ĵ��ÿ�����Ϊ��ֵ
int& test02()
{
	static int b = 100;  //��̬����,�����ȫ��ȥ,ȫ�����ϵ������ڳ��������ϵͳ�ͷ�
	return b;
}

int main4(void)
{
	//1.��Ҫ���ؾֲ�����������
	int& ref1 = test01();
	cout << ref1 << endl;  //�������ֲ���������Ϊ�������������Ż�,�����Ǳ��������ֵ ��Ȼ���ڷǷ�����

	//2.�����ĵ��ÿ�����Ϊ��ֵ
	int& ref2 = test02();
	cout << ref2 << endl;
	test02() = 1000;		//�������ֺ����ĵ��ÿ�����Ϊ��ֵ
	cout << ref2 << endl;
	
	return 0;
}