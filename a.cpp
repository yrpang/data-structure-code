#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

int main()
{
    using namespace std;
    int *a;
    int b;
    cin >> b;
    a = (int *)malloc(200 * sizeof(int));

    printf("%d", *a + 100);
    return 0;
}
