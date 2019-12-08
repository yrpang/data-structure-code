#include <stdio.h>
#include <string.h>

int next[100];

void g_next(char a[], int next[])
{
    int len = strlen(a) - 1;
    int i = 1, j = 0;
    while (i < len)
    {
        if (j == 0 || a[j] == a[i])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

void finds(char a[], char b[])
{
    int len = strlen(a) - 1;
    int lenb = strlen(b) - 1;
    int i = 1, j = 1;
    while (i <= len && j <= lenb)
    {
        if (j == 0 || a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= strlen(b))
    {
        printf("%d", i - lenb);
    }
    else
    {
        printf("ERROR");
    }
}

int main()
{
    char a[10] = " acacca";
    char b[10] = " cca";
    g_next(b, next);
    // for (int i = 1; i < strlen(a); i++)
    // {
    //     printf("%d ", next[i]);
    // }
    finds(a, b);

    return 0;
}