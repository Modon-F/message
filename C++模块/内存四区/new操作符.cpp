#include <iostream>

using namespace std;

int* func()
{
	//�ڶ���������������
	//new���ص��Ǹ��������͵�ָ��
	int* p = new int(10);
	return p;
}

int* func2()
{
	int* p = new int[10];
	for (int i = 0; i < 10; i++)
	{
		p[i] = i + 100;
	}
	return p;
}

int main(void)
{
	int* p = func();
	cout << *p << endl;
	delete p;				//���ùؼ����ͷŶ��ڴ�
	system("pause");		//��ʾ�����������


	//int* p;				//����д�Ǵ��,��ʹ����������ݱ��ͷ���,���Ǹ�ָ�������û���ͷ�
	p = func2();
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << endl;
	}
	delete [] p;			//���ùؼ����ͷŶ��ڴ�
	system("pause");
	return 0;
}