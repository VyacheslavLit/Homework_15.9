#include "chat.h"
#include "menu.h"
#include <iostream>
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //закуск класса Chat и загрузка первоночальной базы
    Chat Chat;
    Chat.reg("user1", "pass1");
    Chat.reg("user2", "pass2");
    Chat.reg("user3", "pass3");
    Chat.reg("user4", "pass4");
    Chat.reg("user5", "pass5");
    Chat.reg("user6", "pass6");
    Chat.reg("user7", "pass7");
    Chat.reg("user8", "pass8");
    Chat.reg("user9", "pass9");
    Chat.reg("user10", "pass10");

    while (true)
    {
        //вывод на экран начального меню и выбор раздела
        menu();
        int tmp = choice();
        if (tmp == 0)break;
        //ввод логина и пароля с последующей регистрацией
        if (tmp == 1)
        {
            string login = loginus();            
            if (Chat.check(login))//проверка введенного логина на повторы
            {
                cout << "\nЛогин занят.\n";
                system("pause");
                continue;
            }
            string pass = password();
            Chat.reg(login, pass);//добавление новых логина и пароля в базу
            continue;
        }
        //ввод логина и пароля с последующей проверкой их в базе
        if (tmp == 2)
        {
            string login = loginus();
            string pass = password();
            if (Chat.login(login, pass))cout << "\nВход возможен, логин пароль совпали.\n"; else cout << "\nВход НЕ возможен, логин пароль НЕ совпали.\n";
            system("pause");
            continue;
        }
        //вывод данных базы на консоль
        if (tmp == 3)
        {
            Chat.show();
            continue;
        }
    }
    return 0;
}
