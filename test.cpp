#include<iostream>
#include<string.h>

int main()
{
    char *s;
    s = (char *)malloc(sizeof(char)*5);
    for(int i=5-1;i>=1;i--)
    {
        s[i] = 's';

    }

    for(int i=5-1;i>=3;i--)
    {
        s[i] = 'b';

    }

    char res[5];
    strcpy(res, &s[1]);

    std::cout<<res;


    return 0;
}