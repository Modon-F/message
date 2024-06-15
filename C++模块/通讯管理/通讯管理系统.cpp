#include <iostream>
#include <string.h>

using namespace std;

#define MAX 10

struct person
{
	string name;// 姓名 
	int sex;//性别 
	int age;
	string phone_number;
	string addr;
};

struct  Addressbooks
{
	struct person personarray[MAX];
	int size;
};

void show_menu()
{
	cout << "********************" << endl;
	cout << "*** 1.添加联系人 ***" << endl;
	cout << "*** 2.显示联系人 ***" << endl;
	cout << "*** 3.删除联系人 ***" << endl;
	cout << "*** 4.查找联系人 ***" << endl;
	cout << "*** 5.修改联系人 ***" << endl;
	cout << "*** 6.清空联系人 ***" << endl;
	cout << "*** 0.退出通讯录 ***" << endl;
	cout << "********提示********" << endl;
	cout << "********************" << endl;
	return;
}

void add_person(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入联系人姓名:" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;
		int sex;
		cout << "请输入联系人性别:" << endl;
		cout << "1------------男:" << endl;
		cout << "2------------女:" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->size].sex = sex;
				break;
			}
			else
			{
				cout << "你的输入有误,请重新输入" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		
		cout << "请输入年龄: " << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age > 130)
			{
				cout << "你的输入有误,请重新输入" << endl;
			}
			else
			{
				abs->personarray[abs->size].age = age;
				break;
			}
		}

		cout << "请输入电话号码: " << endl;
		string phone_number;
		while (true)
		{
			cin >> phone_number;
			if (phone_number.length() != 11)
			{
				cout << "你的输入有误,请重新输入" << endl;
			}
			else
			{
				abs->personarray[abs->size].phone_number = phone_number;
				break;
			}
		}
		
		cout << "请输入家庭住址: " << endl;
		string addr;
		cin >> addr;

		abs->personarray[abs->size].addr = addr;

		abs->size++;
		cout << "添加成功" << endl;
	}
	return;
}

void show_person(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "联系人为空" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "联系人:" << i+1 << "\t";
			cout << "姓名:" << abs->personarray[i].name << "\t";
			if (abs->personarray[i].sex == 1)
			{
				cout << "性别:男" << "\t";
			}
			else
			{
				cout << "性别:女" << "\t";
			}
			cout << "年龄:" << abs->personarray[i].age << "\t";
			cout << "电话号码:" << abs->personarray[i].phone_number << "\t";
			cout << "家庭地址:" << abs->personarray[i].addr << endl;
		}
	}
}
//找到返回数组下标
int find_person(Addressbooks* abs ,string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personarray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void delete_person(Addressbooks* abs)
{
	string name;
	cout << "请输入删除联系人的姓名" << endl;
	cin >> name;
	int addr = find_person(abs, name);
	if (addr != -1)
	{
		for (addr; addr < abs->size; addr++)
		{
			abs->personarray[addr] = abs->personarray[addr + 1];
		}
		abs->size--;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	return;
}

void search(Addressbooks* abs)
{
	string name;
	cout << "请输入查找联系人的姓名" << endl;
	cin >> name;
	int addr = find_person(abs, name);

	if (addr != -1)
	{
		cout << "联系人:" << addr+1 << "\t";
		cout << "姓名:" << abs->personarray[addr].name << "\t";
		if (abs->personarray[addr].sex == 1)
		{
			cout << "性别:男" << "\t";
		}
		else
		{
			cout << "性别:女" << "\t";
		}
		cout << "年龄:" << abs->personarray[addr].age << "\t";
		cout << "电话号码:" << abs->personarray[addr].phone_number << "\t";
		cout << "家庭地址:" << abs->personarray[addr].addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	return;
}
//修改联系人
void modify_person(Addressbooks* abs)
{
	string name;
	cout << "请输入修改联系人的姓名" << endl;
	cin >> name;
	int addr = find_person(abs, name);

	if (addr != -1)
	{
		abs->personarray[addr].name = name;
		int sex;
		cout << "请输入联系人性别:" << endl;
		cout << "1------------男:" << endl;
		cout << "2------------女:" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[addr].sex = sex;
				break;
			}
			else
			{
				cout << "你的输入有误,请重新输入" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		cout << "请输入年龄: " << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age > 130)
			{
				cout << "你的输入有误,请重新输入" << endl;
			}
			else
			{
				abs->personarray[addr].age = age;
				break;
			}
		}

		cout << "请输入电话号码: " << endl;
		string phone_number;
		while (true)
		{
			cin >> phone_number;
			if (phone_number.length() != 11)
			{
				cout << "你的输入有误,请重新输入" << endl;
			}
			else
			{
				abs->personarray[addr].phone_number = phone_number;
				break;
			}
		}

		cout << "请输入家庭住址: " << endl;
		string addr1;
		cin >> addr1;

		abs->personarray[abs->size].addr = addr1;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}


int main(void)
{
	string name;
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.size = 0;
	int select = 0;//创建用户选择输入变量

	while (true)
	{
		system("pause");
		system("cls");
		show_menu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人 
			add_person(&abs); 
			break;
		case 2://显示联系人
			show_person(&abs);
			break;
		case 3://删除联系人
			delete_person(&abs);
			break;
		case 4://查找联系人
			search(&abs);
			break;
		case 5://修改联系人
			modify_person(&abs);
			break;
		case 6://清空联系人
			abs.size = 0;
			break;
		case 0://退出通讯录
			cout << "welecome next use" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入有误 请重新输入" << endl;
		}
	}
	system("pause");
	return 0;
}