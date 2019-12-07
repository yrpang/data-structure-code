#include<stdio.h>
#include<string.h>

void getNext(char* p,int next[])
{
    next[0]= -1;
    int k=-1;
    int j=0;
    while(j<strlen(p)-1)
    {
        if(k==1||p[j]==p[k])
        {
            k++;
            j++;
            next[j]=k;
        }
        else
        {
            k=next[k];
        }
    }
}