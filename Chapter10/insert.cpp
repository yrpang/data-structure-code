#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int input[100];

    int i;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &input[i]);
    }

    int j;

    for (i = 2; i <= n; i++)
    {
        input[0] = input[i];
        for (j = i - 1; input[0] < input[j]; j--)
        {
            input[j + 1] = input[j];
        }
        input[j + 1] = input[0];
    }

    for (i = 1; i <= n; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}