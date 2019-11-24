#include <iostream>
#include <stdio.h>
#include <string.h>

#define INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0

typedef struct QNode
{
    char data;
    struct QNode *next;
} QNode, *QNodePtr;

typedef struct
{
    QNodePtr front;
    QNodePtr rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = (QNodePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(-1);
    Q.rear = Q.front;
    Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q, char e)
{
    QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}
void DeQueue(LinkQueue &Q, char &e)
{
    QNodePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
}

typedef struct StackNode
{
    char *base;
    char *top;
    int size;
} SqStack;

void InitStack(SqStack &s)
{
    s.base = (char *)malloc(sizeof(char) * INIT_SIZE);
    s.top = s.base;
    s.size = INIT_SIZE;
}

void Push(SqStack &s, char e)
{
    if (s.top - s.base >= s.size)
    {
        s.base = (char *)realloc(s.base, (s.size + STACKINCREMENT) * sizeof(char));
        if (!s.base)
            exit(-1);
    }
    *s.top = e;
    s.top++;
}

void Pop(SqStack &s, char &e)
{
    if (s.top == s.base)
        exit(-2);
    --s.top;
    e = *(s.top);
}

int main()
{
    SqStack s;
    InitStack(s);
    LinkQueue q;
    InitQueue(q);

    char input[50];
    scanf("%s", input);

    char a[4] = "sae";
    char b[5] = "tAdA";

    int i, j, k;
    for (i = strlen(input) - 1; i >= 0; i--)
    {
        if (input[i] == 'B')
        {
            for (j = strlen(b) - 1; j >= 0; j--)
            {
                Push(s, b[j]);
            }
        }
        else
        {
            Push(s, input[i]);
        }
    }

    char e;
    while (s.top > s.base)
    {
        Pop(s, e);
        if (e == 'A')
        {
            for (i =0 ; i <strlen(a); i++)
            {
                EnQueue(q, a[i]);
            }
        }
        else
        {
            EnQueue(q, e);
        }
    }

    int flag = 0;
    char tmp, c;
    while (q.front != q.rear)
    {
        DeQueue(q, e);
        if (e == '(' && flag == 0)
        {
            flag = 1;
        }
        else if (flag == 1)
        {
            tmp = e;
            flag = 2;
            Push(s, tmp);

        }
        else if (flag == 2 && e == ')')
        {
            while (s.top > s.base)
            {
                Pop(s, c);
                std::cout << c;
            }
            flag = 0;
        }
        else if (flag == 2)
        {
            Push(s, e);
            Push(s, tmp);
        }
        
        else if(flag==0){
            std::cout << e;
        }
        
    }

    while (q.front != q.rear)
    {
        DeQueue(q, e);
        std::cout << e;
    }

    return 0;
}