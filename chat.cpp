#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat()
{
    mem_login=10;
    data = new AuthData[mem_login];
    for (int i = 0; i < mem_login; ++i)data[i].status = free;
};

//����������� ������ ������������, ��� ������������ ����, �� ���������� � 2 ����
void Chat::reg(string _login, string _pass) 
{
    uint index = 0;
    int i=0;
    for(; i < mem_login; ++i)
    {
        index = hash_str(_login, mem_login, i);
        if (data[index].status == pairStatus::free)break;
    }

    if (i >= mem_login) {
        resize();
        reg(_login, _pass);
    }
    else {
        data[index] = AuthData(_login, _pass);
    }
}

//�������� ���� ����� - ������, ��� ���������� ���������� ������� true
bool Chat::login(string _login, string _pass)
{
    uint index = 0;
    uint _passHash = hash_str(_pass, mem_pass, 0);
    for (int i=0; i < mem_login; ++i)
    {
        index = hash_str(_login, mem_login, i);
        if (data[index].status == pairStatus::engaged && data[index].login == _login && data[index].passHash == _passHash)return true;
    }
    return false;
}

//�������� ������ �� �������, ��� ����������� ������� ������� true
bool Chat::check(string login)
{
    for (int i = 0; i < mem_login; ++i)
    {
        if (data[i].login == login)return true;
    }
    return false;
}

//����� ���� �� �������
void Chat::show()
{
    system("cls");
    cout << "             ---=== ������ ���������� ===---\n\n";
    for (int i = 0; i < mem_login; ++i)
    {
        cout << i << "\t�����:\t" << data[i].login << "\t��� ������:\t" << data[i].passHash << "\t������:\t" << data[i].status << endl;
    }
    system("pause");
}

//���������� ���� � 2 ���� ��� �� ����������
void Chat::resize() {
    AuthData* save = data;
    int save_ms = mem_login;
    mem_login *= 2;
    data = new AuthData[mem_login];
    for (int i = 0; i < save_ms; i++) {
        AuthData& old_pair = save[i];
        if (old_pair.status == pairStatus::engaged) {
            uint index = 0;
            int j = 0;
            for (; j < mem_login; ++j)
            {
                index = hash_str(old_pair.login, mem_login, j);
                if (data[index].status == pairStatus::free) break;
            }
            data[index] = AuthData(old_pair.login, old_pair.passHash);
        }
    }
    delete[] save;
}