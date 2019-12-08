#include<stdio.h>

void hannoi(int n, char x,char y,char z)
{
    if(n==1)
    {
        printf("%d号 从%c到%c\n",n,x,z);
    }
    else{
        hannoi(n-1,x,z,y);
        printf("%d号 从%c到%c\n",n,x,z);
        hannoi(n-1,y,x,z);

    }
}


int main()
{

    hannoi(12,'a','b','c');


    return 0;
}