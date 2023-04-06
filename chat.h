#pragma once
#include "hash.h"

#define mem_pass 999999//������������ ��� ������

class Chat {
public:
    Chat();
    void reg(string _login, string _pass);//�����������
    bool login(string _login, string _pass);//�������� ������-������ � ����
    bool check(string login);//�������� ������ �� �������
    void show();//����� ���� �� �������


private:
    void resize();//���������� ���� � 2 ����

    enum pairStatus
    {
        free,//��������
        engaged,//�����
        deleted//������
    };

    struct AuthData {
        AuthData() : login(), passHash(), status(free) { login = "0"; }
        
        ~AuthData() {
        }
        AuthData(string _login, string _pass) 
        {
            login = _login;
            passHash = hash_str(_pass, mem_pass, 0);
            status = engaged;
        }        
        AuthData(string _login, uint _passHash)
        {
            login = _login;
            passHash = _passHash;
            status = engaged;
        }

        AuthData& operator = (const AuthData& other)
        {
            login = other.login;
            passHash = other.passHash;
            status =other.status;
            return *this;
        }
        string login;
        uint passHash;
        pairStatus status;
    };
    AuthData* data= new AuthData [mem_login];
    int mem_login;//������ ����
};