#include "hash.h"
#include <string.h>

//��
uint hash_str(string str, int mem_size, int i)
{
    int sum = 0;
    int len = str.length();

    for (int j = 0; j < len; ++j)
    {
        sum += str[j];
    }
    i++;
    sum = sum + 7 * i * i;//� ����� 7 ��� �������� ������� ���������� ����

    return  uint (mem_size * double (H * sum - int(H * sum)));
}