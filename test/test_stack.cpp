#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *base;
    int *top;
    int size;
} Stack;

void InitStack(Stack &s)
{
    s.base = (int *)malloc(sizeof(int) * 100);
    s.size = 0;
    s.top = s.base;
}

void EnStack(Stack &s, int e)
{
    if (s.top - s.base >= s.size)
    {
        s.base = (int *)realloc(s.base, sizeof(int) * (s.size + 100));
        s.top = s.base + s.size;
        s.size += 100;
        
    }
    *s.top = e;
    s.top++;
}

void Pop(Stack &s, int &e)
{
    if (s.top == s.base)
    {
        exit(-1);
    }
    e = *(--s.top);
}

int main()
{
    Stack s;
    InitStack(s);
    EnStack(s, 22);
    EnStack(s,33);
    int e;
    Pop(s, e);
    printf("%d", e);
    Pop(s, e);
    printf("%d", e);

    return 0;
}