#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char a[], char b[], int pos)
{
    int i = pos, j = 0;
    while (i < strlen(a) && j < strlen(b))
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= strlen(b))
    {
        return i - strlen(b);
    }
    else
    {
        return -2;
    }
}

int main()
{
    char a[20] = "asdddddddfdfgdd";
    char b[10] = "f";
    int i = 0;

    while (i != -2)
    {
        i = check(a, b, i + 1);
        if (i == -2)
            break;
        printf("%d ", i);
    }
    printf("\n%s", strstr(a, b));

    return 0;
}