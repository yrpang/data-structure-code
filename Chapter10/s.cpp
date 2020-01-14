#include<stdio.h>


int main()
{
    int a[100];

    int n;
    scanf("%d",&n);

    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int tem;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i+1;j++)
        {
            if(a[j]<a[j+1])
            {
                tem = a[j];
                a[j]=a[j+1];
                a[j+1] = tem;

            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

    return 0;
}