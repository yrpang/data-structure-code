#include <stdio.h>
#include <string.h>

int index(char a[], char b[], int pos)
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
    if(j>=strlen(b)) return i-strlen(b);
    else return -2;

}

int main()
{
    char a[20] = "abcbbcdd";
    char b[4] = "d";
    int res=-1;
    while(res!=-2)
    {
        res = index(a,b,res+1);
        printf("%d ",res);
    }
}