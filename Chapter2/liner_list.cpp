/*
 * @Author: yrpang 
 * @Date: 2019-09-16 23:02:02 
 * @Last Modified by: yrpang
 * @Last Modified time: 2019-09-17 00:01:27
 */

#include <stdio.h>
#include <mm_malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 1

typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */
typedef int Status;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;

} SqList;

Status InitList(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status Compare(ElemType a, ElemType b)
{
    if (a == b)
        return 1;
    else
        return 0;
}

int LocateElem_Sq(SqList L, ElemType e)
{
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length && !(*Compare)(*p++, e)) //为什么要这样引用函数？
        ++i;
    if (i <= L.length)
        return i;
    else
        return 0;
}

Status List_Insert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length >= L.listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L.elem, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(ElemType));
        if (newbase)
        {
            L.elem = newbase;
            L.listsize += LISTINCREMENT;
        }
        else
            exit(ERROR);
    }
    ElemType *q = &(L.elem[i - 1]);
    for (ElemType *p = &L.elem[L.length - 1]; p >= q; --p) //这里--p和p--有区别吗？
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;
    return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    ElemType *p = &(L.elem[i - 1]);
    e = *p;
    ElemType *q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p;
    }
    L.length--;
    return OK;
}

Status DestroyList(SqList &L)
{
    ElemType *start = L.elem + L.length;
    for (ElemType *i = start; i > L.elem; i++)
        free(i);
    return OK;
}

int main()
{
    SqList list;
    InitList(list);
    DestroyList(list);

    int input;
    scanf("%d", &input);

    for (int i = 1; i <= input; i++)
    {
        List_Insert(list, i, 78 * i);
    }

    int res = LocateElem_Sq(list, 156);
    int del;
    ListDelete_Sq(list, 6, del);

    printf("%d\n", res);

    printf("%d %d\n", del, list.length);

    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", list.elem[i]);
    }

    return 0;
}
