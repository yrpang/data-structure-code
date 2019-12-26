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
        int low = 1, high = i - 1, m;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (input[0] < input[m])
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i; j >= high + 2; j--)
        {
            input[j] = input[j - 1];
        }
        input[high + 1] = input[0];
    }

    for (i = 1; i <= n; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}