#include "menu.h"
#include <iostream>
using namespace std;

//����� �� ������� ��������������� ����
void menu()
{
		system("cls");
		cout << "     ----- ����������� ���� -----\n";
		cout << "1. ���������� ������ ������������\n";
		cout << "2. ���� �� ������/������\n";
		cout << "3. �������� ����������.\n";
		cout << "0. ����� �� ���������\n\n";
		cout << "�������� ������: ";
}

//����� �������
int choice()
{
	while (true)
	{
		int tmp;
		cin >> tmp;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\n������ �����, ��������� �������.\n";
			system("pause");
			continue;
		}
		if (tmp < 0 || tmp>3)
		{
			cout << "\n��� ���������, ��������� �������.\n";
			system("pause");
			continue;
		}
		return tmp;
	}
}

//���� ������
string loginus()
{
	while (true)
	{
		string login;
		cout << "\n������� �����: ";
		cin >> login;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\n������ �����, ��������� �������.\n";
			system("pause");
			continue;
		}
		return login;
	}
}

//���� ������
string password()
{
	while (true)
	{
		string pass;
		cout << "\n������� ������: ";
		cin >> pass;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\n������ �����, ��������� �������.\n";
			system("pause");
			continue;
		}
		return pass;
	}
}