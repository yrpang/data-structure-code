#include <iostream>
#include <stdio.h>

#define INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 0
#define ERROR 1
#define TRUE 1
#define FALSE 0
#define OVERFLOW 1

using namespace std;

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int size;
} SqStack;

Status InitStack(SqStack &S)
{
    S.base = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.size = INIT_SIZE;
    return OK;
}

Status GetTop(SqStack S, ElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, ElemType e)
{
    if (S.top - S.base >= S.size)
    {
        S.base = (ElemType *)realloc(S.base, (S.size + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.size;
        S.size = S.size + STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}

Status Pop(SqStack &S, ElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    S.top--;
    e = *(S.top);
    return OK;
}

int main()
{
    SqStack S;
    InitStack(S);
    for(int i=10;i>0;i--)
    {
        Push(S, i);
    }
    for (int i = 10; i > 0; i--)
    {
        int e;
        Pop(S, e);
        cout<<e<<" ";
    }

    return 0;
}