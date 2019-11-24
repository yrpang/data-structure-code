#include <iostream>
#include <stdio.h>

#define OK 0
#define ERROR 1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int ElemType;

// 链式结构实现
typedef struct Node
{
    int data;
    int num;
    struct Node *next;
} Node, *NodeList;

void InitLinkList(NodeList &L, int n)
{
    L = (NodeList)malloc(sizeof(Node));
    scanf("%d", &L->data);
    L->num = 1;
    L->next = L;
    NodeList now = L;
    for (int i = 0; i < n - 1; i++)
    {
        NodeList p = (NodeList)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = now->next;
        p->num = i + 2;
        now->next = p;
        now = p;
    }
}

// 线性结构实现

typedef struct SqList
{
    ElemType *elem;
    int *num;
    int length;
    int listsize;
} SqList;

Status InitLinerList(SqList &L)
{
    L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    L.num = (int *)malloc(sizeof(int) * LIST_INIT_SIZE);
    if (!L.elem)
        exit(1);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
Status AddList(SqList &L, ElemType e, int n)
{
    if (L.length >= L.listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L.elem, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(ElemType));
        int *newnum = (int *)realloc(L.num, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(int));
        if (newbase && newnum)
        {
            L.elem = newbase;
            L.num = newnum;
            L.listsize += LISTINCREMENT;
        }
        else
            exit(ERROR);
    }
    L.elem[L.length] = e;
    L.num[L.length] = n;
    ++L.length;
    return OK;
}
Status RemoveListElem(SqList &L, int i)
{
    if (i > L.length || i < 1)
        return ERROR;
    for (ElemType *q = &L.elem[i - 1]; q < &L.elem[L.length - 1]; q++)
    {
        *q = *(q + 1);
    }
    for (ElemType *q = &L.num[i - 1]; q < &L.num[L.length - 1]; q++)
    {
        *q = *(q + 1);
    }
    L.length--;
    return OK;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    // 链式结构实现
    NodeList L;
    InitLinkList(L, n);

    NodeList past = L, now = L;
    while (n > 0)
    {
        for (int i = m - 1; i > 0; i--)
        {
            past = now;
            now = now->next;
        }
        printf("%d ", now->num);
        m = now->data;
        past->next = now->next;
        free(now);
        past = past->next;
        now = past;

        n--;
    }

    // // 线性实现
    // SqList L;
    // InitLinerList(L);
    // for (int i = 1; i <= n; i++)
    // {
    //     ElemType t;
    //     scanf("%d", &t);
    //     AddList(L, t, i);
    // }
    // int last = 0;
    // while (L.length > 0)
    // {
    //     int tem = L.elem[(last + m - 1) % L.length];
    //     printf("%d ", L.num[(last + m - 1) % L.length]);
    //     last = (last + m - 1) % L.length;
    //     RemoveListElem(L, last + 1);
    //     m = tem;
    // }

    return 0;
}
