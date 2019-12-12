#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node, *List;

void Init(List &l)
{
    l = (List)malloc(sizeof(Node));
    l->next = NULL;
}

void create(List &l)
{
    int n;
    cin >> n;
    while (n > 0)
    {
        List p = (List)malloc(sizeof(Node));
        cin >> p->data;
        p->next = l->next;
        l->next = p;
        n--;
    }
}

void print(List &l)
{
    List p = l->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

List rever(List &L)
{
    if(!L->next) return L;
    List l = L->next;
    List p = l->next;
    while (p)
    {
        List q = p->next;
        p->next = l;
        l = p;
        p = q;
    }
    L->next->next = NULL;
    L->next=l;
    return L;
}

int main()
{
    List l;
    Init(l);
    create(l);
    print(l);
    cout << "\n";
    List ll;
    ll= rever(l);
    print(ll);
}