#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
}QNode, *QNodeptr;

typedef struct{
    QNodeptr front, rear;
}LQueue;

void InitQueue(LQueue &q)
{
    q.front = (QNodeptr)malloc(sizeof(QNode));
    q.rear = q.front;
    q.rear->next = NULL;
}

void EnQueue(LQueue &q, int e)
{
    QNodeptr node = (QNodeptr)malloc(sizeof(QNode));
    node->data = e;
    node->next = NULL;
    q.rear->next = node;
    q.rear = node;
}

void DeQueue(LQueue &q, int &e)
{
    QNodeptr p = q.front->next;
    e = p->data;
    q.front->next = p->next;
    if(q.rear==p)
    {
        q.rear=q.front;
    }
    free(p);
}

