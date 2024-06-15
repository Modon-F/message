#include <iostream>
#include <string.h>

using namespace std;

#define MAX 10

struct person
{
	string name;// ���� 
	int sex;//�Ա� 
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
	cout << "*** 1.�����ϵ�� ***" << endl;
	cout << "*** 2.��ʾ��ϵ�� ***" << endl;
	cout << "*** 3.ɾ����ϵ�� ***" << endl;
	cout << "*** 4.������ϵ�� ***" << endl;
	cout << "*** 5.�޸���ϵ�� ***" << endl;
	cout << "*** 6.�����ϵ�� ***" << endl;
	cout << "*** 0.�˳�ͨѶ¼ ***" << endl;
	cout << "********��ʾ********" << endl;
	cout << "********************" << endl;
	return;
}

void add_person(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "��������ϵ������:" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;
		int sex;
		cout << "��������ϵ���Ա�:" << endl;
		cout << "1------------��:" << endl;
		cout << "2------------Ů:" << endl;
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
				cout << "�����������,����������" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		
		cout << "����������: " << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age > 130)
			{
				cout << "�����������,����������" << endl;
			}
			else
			{
				abs->personarray[abs->size].age = age;
				break;
			}
		}

		cout << "������绰����: " << endl;
		string phone_number;
		while (true)
		{
			cin >> phone_number;
			if (phone_number.length() != 11)
			{
				cout << "�����������,����������" << endl;
			}
			else
			{
				abs->personarray[abs->size].phone_number = phone_number;
				break;
			}
		}
		
		cout << "�������ͥסַ: " << endl;
		string addr;
		cin >> addr;

		abs->personarray[abs->size].addr = addr;

		abs->size++;
		cout << "��ӳɹ�" << endl;
	}
	return;
}

void show_person(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "��ϵ��Ϊ��" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "��ϵ��:" << i+1 << "\t";
			cout << "����:" << abs->personarray[i].name << "\t";
			if (abs->personarray[i].sex == 1)
			{
				cout << "�Ա�:��" << "\t";
			}
			else
			{
				cout << "�Ա�:Ů" << "\t";
			}
			cout << "����:" << abs->personarray[i].age << "\t";
			cout << "�绰����:" << abs->personarray[i].phone_number << "\t";
			cout << "��ͥ��ַ:" << abs->personarray[i].addr << endl;
		}
	}
}
//�ҵ����������±�
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
	cout << "������ɾ����ϵ�˵�����" << endl;
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
		cout << "���޴���" << endl;
	}
	return;
}

void search(Addressbooks* abs)
{
	string name;
	cout << "�����������ϵ�˵�����" << endl;
	cin >> name;
	int addr = find_person(abs, name);

	if (addr != -1)
	{
		cout << "��ϵ��:" << addr+1 << "\t";
		cout << "����:" << abs->personarray[addr].name << "\t";
		if (abs->personarray[addr].sex == 1)
		{
			cout << "�Ա�:��" << "\t";
		}
		else
		{
			cout << "�Ա�:Ů" << "\t";
		}
		cout << "����:" << abs->personarray[addr].age << "\t";
		cout << "�绰����:" << abs->personarray[addr].phone_number << "\t";
		cout << "��ͥ��ַ:" << abs->personarray[addr].addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	return;
}
//�޸���ϵ��
void modify_person(Addressbooks* abs)
{
	string name;
	cout << "�������޸���ϵ�˵�����" << endl;
	cin >> name;
	int addr = find_person(abs, name);

	if (addr != -1)
	{
		abs->personarray[addr].name = name;
		int sex;
		cout << "��������ϵ���Ա�:" << endl;
		cout << "1------------��:" << endl;
		cout << "2------------Ů:" << endl;
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
				cout << "�����������,����������" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		cout << "����������: " << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 0 || age > 130)
			{
				cout << "�����������,����������" << endl;
			}
			else
			{
				abs->personarray[addr].age = age;
				break;
			}
		}

		cout << "������绰����: " << endl;
		string phone_number;
		while (true)
		{
			cin >> phone_number;
			if (phone_number.length() != 11)
			{
				cout << "�����������,����������" << endl;
			}
			else
			{
				abs->personarray[addr].phone_number = phone_number;
				break;
			}
		}

		cout << "�������ͥסַ: " << endl;
		string addr1;
		cin >> addr1;

		abs->personarray[abs->size].addr = addr1;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}


int main(void)
{
	string name;
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.size = 0;
	int select = 0;//�����û�ѡ���������

	while (true)
	{
		system("pause");
		system("cls");
		show_menu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ�� 
			add_person(&abs); 
			break;
		case 2://��ʾ��ϵ��
			show_person(&abs);
			break;
		case 3://ɾ����ϵ��
			delete_person(&abs);
			break;
		case 4://������ϵ��
			search(&abs);
			break;
		case 5://�޸���ϵ��
			modify_person(&abs);
			break;
		case 6://�����ϵ��
			abs.size = 0;
			break;
		case 0://�˳�ͨѶ¼
			cout << "welecome next use" << endl;
			system("pause");
			return 0;
		default:
			cout << "�������� ����������" << endl;
		}
	}
	system("pause");
	return 0;
}