#include "menu.h"
#include <iostream>
using namespace std;

//вывод на консоль первоначального меню
void menu()
{
		system("cls");
		cout << "     ----- Проверочное меню -----\n";
		cout << "1. Регистраци нового пользователя\n";
		cout << "2. Вход по логину/паролю\n";
		cout << "3. Просмотр контейнера.\n";
		cout << "0. Выход из программы\n\n";
		cout << "Выберите раздел: ";
}

//выбор раздела
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
			cout << "\nОшибка ввода, повторите попытку.\n";
			system("pause");
			continue;
		}
		if (tmp < 0 || tmp>3)
		{
			cout << "\nВне диапазона, повторите попытку.\n";
			system("pause");
			continue;
		}
		return tmp;
	}
}

//ввод логина
string loginus()
{
	while (true)
	{
		string login;
		cout << "\nВведите логин: ";
		cin >> login;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nОшибка ввода, повторите попытку.\n";
			system("pause");
			continue;
		}
		return login;
	}
}

//ввод пароля
string password()
{
	while (true)
	{
		string pass;
		cout << "\nВведите пароль: ";
		cin >> pass;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nОшибка ввода, повторите попытку.\n";
			system("pause");
			continue;
		}
		return pass;
	}
}