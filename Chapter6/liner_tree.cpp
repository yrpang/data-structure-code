#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_TREE_SIZE 100
#define OK 0;
#define ERROR 1;
typedef char SqBiTree[MAX_TREE_SIZE];
typedef char Status;

Status CreateBiTree(SqBiTree &T, int length)
{
    char tem;
    for (int i = 0; i < length; i++)
    {
        scanf("%c", &tem);
        T[i] = tem;
    }
    return OK;
}

Status visit(int e)
{
    printf("%c ", e);
    return 1;
}

Status PreOrderTraverse(SqBiTree &T, Status (*visit)(int e), int start, int length)
{
    int i = start;

    if (i < length)
    {
        if (visit(T[i]))
        {
            if (PreOrderTraverse(T, visit, 2 * i + 1, length))
                if (PreOrderTraverse(T, visit, 2 * i + 2, length))
                    return 1;
        }
        return 0;
    }
    return 0;
}

void PreOrder(SqBiTree t, int i, int length)
{
    if(i<length)
    {
        cout<<t[i];
        if(2*i<length) PreOrder(t, 2*i, length);
        if(2*i+1<length) PreOrder(t, 2*i+1, length);
    }
}

int main()
{
    SqBiTree lalala;
    int length;
    scanf("%d", &length);
    CreateBiTree(lalala, length);
    PreOrderTraverse(lalala, visit, 0, length);
    return 0;
}