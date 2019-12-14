#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef struct ha
{
    char name[20];
    int key;
    int filled;
} hashs;
typedef struct hashtable
{
    hashs *data;
    int length;
} hashtable;

int getrandom(int n)
{
    srand(n);
    return rand();
}

void InitHash(hashtable &h)
{
    h.data = (hashs *)malloc(sizeof(hashs) * 100);
    h.length = 100;
}

void createHash(hashtable &h)
{
    int i, j;
    for (i = 0; i < h.length; i++)
    {
        strcpy(h.data[i].name, "0");
        h.data[i].key = 0;
        h.data[i].filled = 0;
    }
    int n; //姓名总数
    cin >> n;

    int key = 0, as_sum = 0;
    char tem[20];
    for (i = 0; i < n; i++)
    {
        key = 0;
        as_sum = 0;
        scanf("%s", tem);
        for (j = 0; j < strlen(tem); j++)
        {
            as_sum += tem[j] - 'a';
        }
        key = as_sum % 47;
        if (h.data[key].filled == 0)
        {
            strcpy(h.data[key].name, tem);
            h.data[key].key = key;
            h.data[key].filled = 1;
        }
        else
        {
            int count = 0;
            int tem_key = key;
            while (count < 2)
            {
                tem_key = (tem_key + getrandom(tem_key)) % h.length;
                if (h.data[tem_key].filled == 0)
                {
                    break;
                }
                count++;
            }
            if (count >= 2)
            {
                cout << "需要重建";
            }
            else
            {
                strcpy(h.data[tem_key].name, tem);
                h.data[tem_key].key = key;
                h.data[tem_key].filled = 1;
            }
        }
    }
}

void searchHash(hashtable &h)
{
    char name[20];
    cin >> name;
    int as_sum = 0;
    int i;
    for (i = 0; i < strlen(name); i++)
    {
        as_sum += name[i] - 'a';
    }
    int key = as_sum % 47;
    if (h.data[key].key == key)
    {
        cout << h.data[key].name << " " << h.data[key].key << endl;
    }
    else if (h.data[key].filled == 0)
    {
        cout << "不存在";
    }
    else
    {
        while (true)
        {
            key = (key + getrandom(key)) % h.length;
            if (h.data[key].key == key)
            {
                cout << h.data[key].name << " " << h.data[key].key << endl;
                break;
            }
            else if (h.data[key].filled == 0)
            {
                cout << "不存在";
                break;
            }
        }
    }
}

int main()
{
    hashtable h;
    InitHash(h);
    createHash(h);
    for (int i = 0; i < h.length; i++)
    {
        if (h.data[i].filled == 1)
        {
            cout << i << " " << h.data[i].name << endl;
        }
    }
    searchHash(h);

    return 0;
}