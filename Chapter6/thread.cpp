#include <iostream>
#include <stdio.h>
#include <queue>

#define OK 1
#define ERROR 0
#define Length 100

using namespace std;
typedef int Status;
typedef char ElemType;

enum PointerTag
{
    Link,
    Thread
};

typedef struct BiThrNode
{
    ElemType data;
    enum PointerTag ltag, rtag;
    struct BiThrNode *lchild, *rchild;
} BiThrNode, *BiThrTree;

BiThrTree pre;

void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            p->ltag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild)
        {
            pre->rtag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
    Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
    if (!Thrt)
        exit(-1);

    Thrt->ltag = Link;
    Thrt->rtag = Thread;
    Thrt->rchild = Thrt;

    if (!T)
        Thrt->lchild = Thrt;
    else
    {
        Thrt->lchild = T;
        pre = Thrt;
    }
    InThreading(T);
    Thrt->rchild = pre;
    pre->rtag = Thread;
    pre->rchild = Thrt;
    return OK;
}

void CreateBiThrTree(BiThrTree &T)
{
    char tem;
    scanf("%c", &tem);

    if (tem == ' ')
    {
        T = NULL;
    }
    else
    {
        T = (BiThrTree)malloc(sizeof(BiThrNode));
        if (!T)
            exit(-1);
        T->data = tem;
        CreateBiThrTree(T->lchild);
        CreateBiThrTree(T->rchild);
    }
}

void InOrderTraverse(BiThrTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        printf("%c", T->data);
        InOrderTraverse(T->rchild);
    }
}

void Traverse(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;
    while (p != T)
    {
        while (p->ltag == Link)
            (p = p->lchild);
        printf("%c", p->data);
        while (p->rtag == Thread && p->rchild != T)
        {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}

int main()
{
    BiThrTree T;
    CreateBiThrTree(T);
    BiThrTree res;
    InOrderThreading(res, T);
    Traverse(res);
    return 0;
}
