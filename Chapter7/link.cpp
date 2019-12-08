#include<stdio.h>
#include<stdlib.h>
#include<iostream>

typedef struct ArcNode{
    int tnum;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct Node{
    int data;
    ArcNode *first;
}Node, NList[100];

typedef struct{
    NList nlist;
    int nodenum, arcnum;
}Graph;

void Create(Graph &g)
{
    int i,j,k,n;
    scanf("%d %d",&g.nodenum, &g.arcnum);
    for(i=0;i<g.nodenum;i++)
    {
        scanf("%d",&g.nlist[i].data);
        g.nlist[i].first=NULL;
    }

    int a,b;
    for(k=0;k<g.arcnum;k++)
    {
        scanf("%d %d",&i, &j);

        ArcNode *s;
        s=(ArcNode *)malloc(sizeof(ArcNode));
        s->nextarc =g.nlist[i].first;
        s->tnum = j;
        g.nlist[i].first = s;

        s=(ArcNode *)malloc(sizeof(ArcNode));
        s->tnum = i;
        s->nextarc = g.nlist[j].first;
        g.nlist[j].first = s;
    }
    
}


int main()
{
    Graph g;
    Create(g);

    int i;
    for(i=0;i<g.nodenum;i++)
    {
        ArcNode *s = g.nlist[i].first;
        while(s!=NULL)
        {
            printf("%d",s->tnum);
            s = s->nextarc;
        }
    }
    using namespace std;
    return 0;
}