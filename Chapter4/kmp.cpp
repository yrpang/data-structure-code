#include <stdio.h>
#include <string.h>

int next[100];
void get_next(char a[], int next[])
{
    next[1] = 0;
    int i = 1, j = 0;
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

int Index_KMP(char a[], char b[], int pos)
{
    int i = pos, j = 1;
    while (i <= strlen(a) - 1 && j <= strlen(b) - 1)
    {
        if (j == 0 || a[i] == b[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > strlen(b) - 1)
        return i - (strlen(b) - 1);
    else
        return -2;
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