#include <iostream>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define Length 100

using namespace std;
typedef int Status;
typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;

Status CreateBiTree(BiTree &T)
{
    ElemType e;
    scanf("%c", &e);

    if (e == ' ')
        T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        if (!T)
            exit(-1);

        T->data = e;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

int res = 0;
// 先序遍历构造二叉树
void PreOrderTraverse(BiTree T, void (*visit)(ElemType e))
{
    if (T)
    {
        // visit(T->data);
        if (T->lchild == NULL && T->rchild == NULL)
            res++;
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
}

int CheckHeight(BiTree T)
{
    int h1 = 0, h2 = 0, max = 0;
    if (T)
    {
        h1 = CheckHeight(T->lchild);
        h2 = CheckHeight(T->rchild);
        max = h1 > h2 ? h1 : h2;
        return max + 1;
    }
    return 0;
}

void InOrderTraverse(BiTree T, void (*visit)(ElemType e))
{
    if (T)
    {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
}

void PostOrderTraverse(BiTree T, void (*visit)(ElemType e))
{
    if (T)
    {
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->rchild, visit);
        visit(T->data);
    }
}

// 层序遍历二叉树
void LevelOrder(BiTree T, void (*visit)(ElemType e))
{
    BiTree Queue[100];
    int front, rear;
    if (T == NULL)
        return;
    front = -1;
    rear = 0;
    Queue[rear] = T;
    while (front != rear)
    {
        front++;
        visit(Queue[front]->data);
        if (Queue[front]->lchild)
        {
            rear++;
            Queue[rear] = Queue[front]->lchild;
        }
        if (Queue[front]->rchild)
        {
            rear++;
            Queue[rear] = Queue[front]->rchild;
        }
    }
}



void printData(ElemType e)
{
    printf("%c", e);
}

int main()
{

    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T, printData);
    cout << res << "\n";
    cout << CheckHeight(T) << "\n";
    LevelOrder(T, printData);
    cout << "\n";
    InOrderTraverse(T, printData);
    cout << "\n";
    PostOrderTraverse(T, printData);
    cout << "\n";
    return 0;
}