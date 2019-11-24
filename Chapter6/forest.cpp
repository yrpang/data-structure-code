#include <stdio.h>
#include <stack>
#include <queue>

typedef struct CSNode
{
    char data;
    struct CSNode *firstchild, *nexitbrother;
} CSNode, *CSTree;

typedef struct BiNode
{
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void CreateBiTree(BiTree &T)
{
    char e;
    scanf("%c", &e);

    if (e == ' ')
        T = NULL;

    else
    {
        T = (BiTree)malloc(sizeof(BiNode));
        if (!T)
            exit(-1);
        T->data = e;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void InOrderTraverse(BiTree T)
{
    if (T)
    {
        printf("%c", T->data);
        InOrderTraverse(T->lchild);
        InOrderTraverse(T->rchild);
    }
}

int main()
{
    using namespace std;
    BiTree ll;
    CreateBiTree(ll);
    InOrderTraverse(ll);

    return 0;
}