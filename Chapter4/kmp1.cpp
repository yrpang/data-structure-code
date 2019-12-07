#include <stdio.h>
#include <stdlib.h>

int next[100];
void get_next(char T[], int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T[0])
    {
        if (j == 0 || T[i] == T[j])
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
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j]) // 继续比较后继字符
        {
            ++i;
            ++j;
        }
        else
            j = next[j]; // 模式串向右移动
    }
    if (j > T[0])
        return i - T[0]; // 匹配成功
    else
        return 0;
}

int main()
{
    

    return 0;
}