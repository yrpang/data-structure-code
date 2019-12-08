#include <stdio.h>
#include <string.h>

int next[100];
void get_next(char a[], int next[])
{
    next[1] = 0;
    int i = 1, j = 0;
    next[1] = 0;
    while (i < strlen(a) - 1)
    {
        if (j == 0 || a[i] == a[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int Index_KMP(char S[], char T[], int pos)
{
    int i = pos, j = 1;
    while (i <= strlen(S) - 1 && j <= strlen(T) - 1)
    {
        if (j == 0 || S[i] == T[j]) // 继续比较后继字符
        {
            ++i;
            ++j;
        }
        else
            j = next[j]; // 模式串向右移动
    }
    if (j > strlen(T) - 1)
        return i - (strlen(T) - 1); // 匹配成功
    else
        return 0;
}

int main()
{
    char a[10] = " acacca";
    char b[10] = " a";
    get_next(b, next);
    for (int i = 1; i < strlen(b); i++)
    {
        printf("%d ", next[i]);
    }
    printf("\n");
    printf("%d", Index_KMP(a, b, 0));
    return 0;
}