#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<queue>

using namespace std;

typedef struct ArcNode
{
    int tnum;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct Node
{
    int data;
    ArcNode *first;
} Node, NList[100];

typedef struct
{
    NList nlist;
    int nodenum, arcnum;
} Graph;

void Create(Graph &g)
{
    int i, j, k, n;
    scanf("%d %d", &g.nodenum, &g.arcnum);
    for (i = 0; i < g.nodenum; i++)
    {
        scanf("%d", &g.nlist[i].data);
        g.nlist[i].first = NULL;
    }

    int a, b;
    for (k = 0; k < g.arcnum; k++)
    {
        scanf("%d %d", &i, &j);

        ArcNode *s;
        s = (ArcNode *)malloc(sizeof(ArcNode));
        s->nextarc = g.nlist[i].first;
        s->tnum = j;
        g.nlist[i].first = s;

        s = (ArcNode *)malloc(sizeof(ArcNode));
        s->tnum = i;
        s->nextarc = g.nlist[j].first;
        g.nlist[j].first = s;
    }
}

int visit[12] = {
    0,
};

void DFS(Graph &g, int w)
{
    ArcNode *p = g.nlist[w].first;
    cout << g.nlist[w].data << " ";
    visit[w] = 1;
    while (p)
    {
        if (!visit[p->tnum])
        {
            DFS(g, p->tnum);
        }
        p = p->nextarc;
    }
}


queue<int> q;
void BFS(Graph &g, int w)
{
    cout << g.nlist[w].data << " ";
    visit[w] = 1;
    ArcNode *p = g.nlist[w].first;
    q.push(w);
    while(!q.empty())
    {
        w = q.front();
        q.pop();
        p = g.nlist[w].first;
        while(p)
        {
            if(!visit[p->tnum])
            {
                visit[p->tnum] = 1;
                cout<<g.nlist[p->tnum].data<<" ";
                q.push(p->tnum);
            }
            p=p->nextarc;
        }
    }
}

int main()
{
    Graph g;
    Create(g);

    // int i;
    // for (i = 0; i < g.nodenum; i++)
    // {
    //     ArcNode *s = g.nlist[i].first;
    //     while (s != NULL)
    //     {
    //         printf("%d", s->tnum);
    //         s = s->nextarc;
    //     }
    // }
    DFS(g, 0);
    return 0;
}