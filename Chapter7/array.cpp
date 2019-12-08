#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

typedef struct ArcCell
{
    int adj;
} ArxCell, AdjM[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
    int vexs[MAX_VERTEX_NUM];
    AdjM arcs;
    int vexnum, arcnum;
} MGraph;

void Create(MGraph &g)
{
    int i, j, k;
    scanf("%d %d", &g.vexnum, &g.arcnum);
    for (i = 0; i < g.vexnum; i++)
    {
        scanf("%d", &g.vexs[i]);
    }
    for (i = 0; i < g.vexnum; i++)
    {
        for (j = 0; j < g.vexnum; j++)
        {
            g.arcs[i][j].adj = INFINITY;
        }
    }
    int a, b;
    int i1, j1;
    for (k = 0; k < g.arcnum; k++)
    {
        scanf("%d %d", &a, &b);
        for (i = 0; i1 < g.vexnum; i1++)
        {
            if (g.vexs[i1] == a)
            {
                i = i1;
                break;
            }
        }
        for (j1 = 0; j1 < g.vexnum; j1++)
        {
            if (g.vexs[j1] == b)
            {
                j = j1;
                break;
            }
        }
        scanf("%d", &g.arcs[i][j].adj);
        g.arcs[j][i] = g.arcs[i][j];
    }
}

int main()
{
    MGraph g;
    Create(g);

    int i, j;
    for (i = 0; i < g.vexnum; i++)
    {
        for (j = 0; j < g.vexnum; j++)
        {
            printf("%13d ", g.arcs[i][j].adj);
        }
        printf("\n");
    }

    using namespace std;
    cout << INT_MAX;
    return 0;
}