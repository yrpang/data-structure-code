#include <stdio.h>
#include <iostream>

using namespace std;

void Shell(int data[], int dk, int length)
{
    int i, j;
    for (i = dk + 1; i <= length; i += dk)
    {
        data[0] = data[i];
        for (j = i - dk; j >= 1 && data[j] > data[0]; j -= dk)
        {
            data[j + dk] = data[j];
        }
        data[j + dk] = data[0];
    }
}

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

    int list[5] = {7, 4, 2, 1};
    for (i = 0; i < 4; i++)
    {
        Shell(input, list[i], n);
    }

    for (i = 1; i <= n; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}