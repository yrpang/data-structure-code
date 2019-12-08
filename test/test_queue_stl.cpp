#include <stdio.h>
#include <queue>

typedef struct BiNode
{
    int data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void InitBiTree(BiTree &t)
{
    t = (BiTree)malloc(sizeof(BiNode));
    t->lchild = NULL;
    t->rchild = NULL;
}

int main()
{
    using namespace std;

    queue<int> q;

    BiTree a;
    q.push(1);
    q.push(2);
    if(!q.empty())
    {
        printf("%d",q.front());
    }

    return 0;
}