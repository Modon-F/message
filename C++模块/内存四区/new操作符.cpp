#include <iostream>

using namespace std;

int* func()
{
	//在堆区创建整形数据
	//new返回的是改数据类型的指针
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
	delete p;				//利用关键字释放堆内存
	system("pause");		//提示按任意键继续


	//int* p;				//这样写是错的,即使堆里面的内容被释放了,但是该指针的内容没有释放
	p = func2();
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << endl;
	}
	delete [] p;			//利用关键字释放堆内存
	system("pause");
	return 0;
}