#include <iostream>
#include <stdio.h>

#define INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 1

using namespace std;

typedef int Status;
typedef int ElemType;

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.front = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(-1);
    Q.rear = Q.front;
    Q.rear->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue &Q, ElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
Status DeQueue(LinkQueue &Q, ElemType &e)
{
    QueuePtr p;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
}
