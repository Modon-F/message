#include <stdio.h>
//while(k++)这样的语句中，k++确实会先执行，但while循环会使用k++返回的原始k值来进行条件判断。 这句话是重点
int main(void)
{
	int i = 2;
	while (i++ < 4) //先判断 在加一  所以他使用的是原始值
	{
		printf("i = %d\n", i);//1 0
	}
	printf("i = %d\n", i);//-1

	int j = 2;
	while (++j < 4) //先加一 在判断  所以他使用的不是原始值
	{
		printf("j = %d\n", j); //1
	}
	printf("j = %d\n", j);//0

	int k = 0;
	while (k++) //先使用 再加一
	{
		printf("i am k++\n");
		break;
	}

	int b = 0;
	while (++b) //先加一 在使用
	{
		printf("i am ++b\n");
		break;
	}
	return 0;
}