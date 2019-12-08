#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <set>

struct data
{
    int pos;
    int key;
    int npos;
};

typedef struct LNode
{
    int data, pos, npos;
    struct LNode *next;
} LNode, *List;

void findNode(struct data data[], int n, int *pos, int *key, int *npos)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (data[i].pos == *pos)
        {
            *pos = data[i].pos;
            *key = data[i].key;
            *npos = data[i].npos;
            break;
        }
    }
}

void InitList(List &l)
{
    l = (List)malloc(sizeof(LNode));
    l->next = NULL;
}

int main()
{
    struct data data[10000];

    int head, n;
    scanf("%d %d", &head, &n);

    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &data[i].pos, &data[i].key, &data[i].npos);
    }

    List list;
    InitList(list);
    List end = list;

    int pos, key, npos;
    pos = head;
    int count = n;
    while (count > 0)
    {
        findNode(data, n, &pos, &key, &npos);

        List tem = (List)malloc(sizeof(LNode));

        tem->data = key;
        tem->pos = pos;

        tem->next = NULL;
        end->next = tem;
        end = end->next;

        pos = npos;
        count--;
    }

    using namespace std;

    set<int> check;
    if (!list->next)
        return 0;
    List l = list->next;
    List deleated;
    InitList(deleated);
    List end_d = deleated;

    List res;
    InitList(res);
    List end_r = res;
    List past_r = NULL, past_d = NULL;
    while (l != NULL)
    {
        if (check.find(abs(l->data)) != check.end())
        {
            List de = (List)malloc(sizeof(LNode));
            de->data = l->data;
            de->pos = l->pos;

            if (past_r)
                past_r->npos = de->pos;
            past_r = de;

            de->next = NULL;
            end_d->next = de;
            end_d = end_d->next;
        }
        else
        {
            check.insert(abs(l->data));
            List rn = (List)malloc(sizeof(LNode));

            rn->data = l->data;
            rn->pos = l->pos;
            if (past_d)
                past_d->npos = rn->pos;
            past_d = rn;

            rn->next = NULL;
            end_r->next = rn;
            end_r = end_r->next;
        }
        l = l->next;
    }

    end_d->npos = -1;
    end_r->npos = -1;

    if (res->next)
    {
        l = res->next;
        while (l != NULL)
        {
            if (l->npos == -1)
            {
                printf("%05d %d %d\n", l->pos, l->data, l->npos);
            }
            else
            {
                printf("%05d %d %05d\n", l->pos, l->data, l->npos);
            }
            l = l->next;
        }
    }

    if (deleated->next)
    {
        l = deleated->next;
        while (l != NULL)
        {
            if (l->npos == -1)
            {
                printf("%05d %d %d\n", l->pos, l->data, l->npos);
            }
            else
            {
                printf("%05d %d %05d\n", l->pos, l->data, l->npos);
            }

            l = l->next;
        }
    }
}