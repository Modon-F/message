#include <stdio.h>
//while(k++)����������У�k++ȷʵ����ִ�У���whileѭ����ʹ��k++���ص�ԭʼkֵ�����������жϡ� ��仰���ص�
int main(void)
{
	int i = 2;
	while (i++ < 4) //���ж� �ڼ�һ  ������ʹ�õ���ԭʼֵ
	{
		printf("i = %d\n", i);//1 0
	}
	printf("i = %d\n", i);//-1

	int j = 2;
	while (++j < 4) //�ȼ�һ ���ж�  ������ʹ�õĲ���ԭʼֵ
	{
		printf("j = %d\n", j); //1
	}
	printf("j = %d\n", j);//0

	int k = 0;
	while (k++) //��ʹ�� �ټ�һ
	{
		printf("i am k++\n");
		break;
	}

	int b = 0;
	while (++b) //�ȼ�һ ��ʹ��
	{
		printf("i am ++b\n");
		break;
	}
	return 0;
}