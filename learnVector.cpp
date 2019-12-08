#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stack>
#include <string>

int main()
{
    using namespace std;

    char c;
    while (scanf("%c", &c) == 1)
    {
        if (c == ' ')
            continue;
        printf("%c", c);
    }

    vector<int> a;
    // 调整大小
    a.resize(10, 2);

    // 添加元素
    a.push_back(99);

    // 访问元素
    int i;
    for (i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    // 返回最后一个
    cout << a.back() << " ";
    // 返回第一个
    cout << a.front();

    stack<int> b;
    b.push(2);
    cout << b.top();

    return 0;
}