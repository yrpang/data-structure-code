#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct LNode
{
    int num;
    int rate;
    struct LNode *next;
} LNode, *List;

void InitList(List &l)
{
    l = (List)malloc(sizeof(LNode));
    l->next = NULL;
}

void CreateList(List &l, int n)
{
    int a, e;
    List end = l;
    l->num = n;
    while (n > 0)
    {
        scanf("%d %d", &a, &e);
        List tem = (List)malloc(sizeof(LNode));
        tem->num = a;
        tem->rate = e;
        tem->next = NULL;
        end->next = tem;
        end = tem;
        n--;
    }
}

void Delete(List &l, List e)
{
    List now = l;
    while (now->next != e)
    {
        now = now->next;
    }
    now->next = e->next;
    free(e);
}

void InsertB(List &l, List e, List d)
{
    List n = (List)malloc(sizeof(LNode));
    n->num = d->num;
    n->rate = d->rate;
    List now = l;
    while (now->next != e)
    {
        now = now->next;
    }
    now->next = n;
    n->next = e;
}

void AddList(List &a, List &b)
{
    List n1 = a->next, n2 = b->next;
    List before, tem;

    while (n1 != NULL && n2 != NULL)
    {
        if (n1->rate > n2->rate)
        {
            before = n1;
            n1 = n1->next;
        }
        else if (n1->rate == n2->rate)
        {
            n1->num = n1->num + n2->num;
            if (n1->num == 0)
            {
                tem = n1->next;
                Delete(a, n1);
                n1 = tem;
            }
            tem = n2->next;
            Delete(b, n2);
            n2 = tem;
        }
        else
        {
            InsertB(a, n1, n2);
            tem = n2->next;
            Delete(b, n2);
            n2 = tem;
        }
    }
    if (n2 != NULL)
    {
        tem = a;
        while (tem->next != NULL)
        {
            tem = tem->next;
        }
        while (n2 != NULL)
        {
            tem->next = n2;
            tem = tem->next;
            n2 = n2->next;
        }
    }
}

List MultList(List &l, List e)
{
    List n = l->next;

    List res = (List)malloc(sizeof(LNode));
    res->next = NULL;
    List end = res;
    while (n != NULL)
    {
        List tem = (List)malloc(sizeof(LNode));
        tem->num = n->num * e->num;
        tem->rate = n->rate + e->rate;
        tem->next = NULL;

        end->next = tem;
        end = end->next;

        n = n->next;
    }
    return res;
}

int main()
{
    List a, b;
    int n1, n2;
    scanf("%d", &n1);
    InitList(a);
    InitList(b);
    CreateList(a, n1);
    scanf("%d", &n2);
    CreateList(b, n2);

    List tem = b->next;
    List t;
    List res;
    InitList(res);
    while (tem != NULL)
    {
        t = MultList(a, tem);
        AddList(res, t);
        tem = tem->next;
    }
    if (res->next == NULL)
    {
        printf("0 0");
    }
    else
    {
        List l = res->next;
        while (l->next != NULL)
        {
            if (l->num == 0)
            {
                l = l->next;
                continue;
            }

            printf("%d ", l->num);
            printf("%d ", l->rate);
            l = l->next;
        }
        printf("%d %d", l->num, l->rate);
    }
    printf("\n");

    AddList(a, b);
    if (a->next == NULL)
    {
        printf("0 0");
    }
    else
    {
        List l = a->next;
        while (l->next != NULL)
        {
            if (l->num == 0)
            {
                l = l->next;
                continue;
            }

            printf("%d ", l->num);
            printf("%d ", l->rate);
            l = l->next;
        }
        printf("%d %d", l->num, l->rate);
    }
}