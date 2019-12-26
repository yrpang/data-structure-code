#include <stdio.h>
#include <iostream>

using namespace std;

int partiton(int data[], int low, int high)
{
    int par = data[low];
    while (low < high)
    {
        // 特别注意有等号
        while (low < high && data[high] >= par)
            --high;
        data[low] = data[high];
        while (low < high && data[low] <= par)
            ++low;
        data[high] = data[low];
    }
    data[low] = par;
    return low;
}

void QSort(int data[], int low, int high)
{
    if (low < high)
    {
        int mid = partiton(data, low, high);
        QSort(data, low, mid - 1);
        QSort(data, mid + 1, high);
    }
}

int main()
{
    int input[10] = {3, 1, 5, 3, 7, 9, 1};
    QSort(input, 0, 6);
    int i;
    for (i = 0; i < 7; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}