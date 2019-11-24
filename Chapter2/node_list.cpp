#include <iostream>

#define MAX_SIZE 100
#define OK 0;
#define ERROR 1;

typedef int Status;
typedef int ElemType;

struct LNode
{
    ElemType data;
    struct LNode *next;
};

typedef struct LNode LNode;
typedef struct LNode* LinkList;

void CreateLinkList(LinkList &L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = n; i > 0; --i)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

Status ListDelete(LinkList &L, int index, ElemType &e)
{
    LinkList p = L;
    int i = 0;
    while (p->next && i < index - 1)
    {
        p = p->next;
        i++;
    }
    if (!(p->next) || i > index - 1)
        return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

Status InsertNode(LinkList &L, int index, ElemType e)
{

    return 0;
}

int main()
{
    return 0;
}