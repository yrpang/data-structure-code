#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

typedef enum
{
    unvisited,
    visited
} Visitif;
typedef struct Ebox
{
    Visitif flag;
    int ivex, jvex;
    struct Ebox *ilink, *jlink;
} Ebox;

typedef struct VexBox
{
    int data;
    Ebox *firstedge;
} VexBox;

typedef struct
{
    VexBox adjmulist[31];
    int vexnum, edgenum;
} AMLGraph;

void AddEdge(AMLGraph &g, int i, int j)
{
    Ebox *edge = (Ebox *)malloc(sizeof(Ebox));
    edge->ivex = i;
    edge->jvex = j;

    Ebox *p = g.adjmulist[i].firstedge;
    if (!p)
    {
        g.adjmulist[i].firstedge = edge;
        edge->ilink = NULL;
    }
    else
    {
        g.adjmulist[i].firstedge = edge;
        edge->ilink = p;
    }

    Ebox *q = g.adjmulist[j].firstedge;
    if (!q)
    {
        g.adjmulist[j].firstedge = edge;
        edge->jlink = p;
    }
    else
    {
        g.adjmulist[j].firstedge = edge;
        edge->jlink = p;
    }
}

void CreateGrapg(AMLGraph &g, int n, int edgenum)
{
    g.vexnum = n;
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> g.adjmulist[i].data;
        g.adjmulist[i].firstedge = NULL;
    }

    int nodei, nodej;
    while (edgenum > 0)
    {
        cin >> nodei >> nodej;
        for (i = 0; i < g.vexnum; i++)
        {
            if (g.adjmulist[i].data == nodei)
                break;
        }
        for (j = 0; j < g.vexnum; j++)
        {
            if (g.adjmulist[j].data == nodej)
                break;
        }
        AddEdge(g, i, j);
        edgenum--;
    }
}

void PrintG(AMLGraph g)
{
    int i;
    Ebox *p;
    for (i = 0; i < g.vexnum; i++)
    {
        p = g.adjmulist[i].firstedge;
        cout << g.adjmulist[i].data << ": ";
        while (p != NULL)
        {
            cout << p->ivex << ":" << p->jvex << "-->";
            p = p->ilink;
        }
        cout << endl;
    }
}

int visit[21] = {
    0};
queue<Ebox *> gent;
void DFS(AMLGraph &g, int w)
{
    int i;
    visit[w] = visited;
    cout << g.adjmulist[w].data << " ";
    Ebox *p = g.adjmulist[w].firstedge;

    while (p)
    {
        if (!visit[p->jvex])
        {
            gent.push(p);
            DFS(g, p->jvex);
        }
        p = p->ilink;
    }
}

queue<int> tem;
queue<Ebox *> gent1;
int now;
void BFS(AMLGraph &g, int w)
{
    visit[w] = visited;
    cout << g.adjmulist[w].data << " ";
    tem.push(w);
    while (!tem.empty())
    {
        now = tem.front();
        tem.pop();
        Ebox *p = g.adjmulist[now].firstedge;
        while (p)
        {
            if (visit[p->jvex] == unvisited)
            {
                visit[p->jvex] = visited;
                gent1.push(p);
                cout << g.adjmulist[p->jvex].data << " ";
                tem.push(p->jvex);
            }
            p = p->ilink;
        }
    }
}

int main()
{
    AMLGraph g;
    int n,m,start;
    cin >> n >>m;

    CreateGrapg(g, n, m);
    DFS(g, start);

    cout << "输出边集：{";
    while (!gent.empty())
    {
        cout << gent.front()->ivex + 1 << "->" << gent.front()->jvex + 1 << " ";
        gent.pop();
    }
    cout << "}\n";

    for (int i = 0; i < 31; i++)
    {
        visit[i] = unvisited;
    }

    BFS(g, start);
    cout << "输出边集：{";
    while (!gent1.empty())
    {
        cout << gent1.front()->ivex + 1 << "->" << gent1.front()->jvex + 1 << " ";
        gent1.pop();
    }
    cout << "}\n";

    return 0;
}