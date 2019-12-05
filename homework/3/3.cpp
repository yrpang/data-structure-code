#include <stdio.h>
#include <mm_malloc.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>

#define N 50
#define M 2 * N - 1
#define MAXINT 32767

using namespace std;
typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
} HFNode, HFTree[M + 1];

void Slect(HFTree ht, int pos, int *s1, int *s2)
{
    int j, m1, m2;
    m1 = MAXINT;
    m2 = MAXINT;
    for (j = 1; j <= pos; j++)
    {
        if (ht[j].weight < m1 && ht[j].parent == 0)
        {
            m2 = m1;
            *s2 = *s1;
            *s1 = j;
            m1 = ht[j].weight;
        }
        else if (ht[j].weight < m2 && ht[j].parent == 0)
        {
            *s2 = j;
            m2 = ht[j].weight;
        }
    }
}

void CreatHTTree(HFTree ht, int w[], int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        ht[i].weight = w[i];
        ht[i].parent = 0;
        ht[i].lchild = 0;
        ht[i].rchild = 0;
    }
    int m = 2 * n - 1;
    for (i = n + 1; i <= m; i++)
    {
        ht[i].weight = 0;
        ht[i].parent = 0;
        ht[i].lchild = 0;
        ht[i].rchild = 0;
    }

    int s1, s2;
    for (i = n + 1; i <= m; i++)
    {
        Slect(ht, i - 1, &s1, &s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].lchild = s1;
        ht[i].rchild = s2;
    }
}

void CreateHfCode(HFTree ht, char **hc, int n)
{
    int start, current, p;
    char *cd;
    cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for (int i = 1; i <= n; i++)
    {
        start = n - 1;
        current = i;
        p = ht[i].parent;
        while (p != 0)
        {
            --start;
            if (ht[p].lchild == current)
            {
                cd[start] = '0';
            }
            else
            {
                cd[start] = '1';
            }
            current = p;
            p = ht[p].parent;
        }
        hc[i] = (char *)malloc(sizeof(char) * (n - start));
        strcpy(hc[i], &cd[start]);
    }
    free(cd);
}

void DeCode(HFTree ht, char data[], char words[], int n)
{
    ofstream res;
    res.open("TextFile.txt");
    int c = 2 * n - 1;
    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == '0')
            c = ht[c].lchild;
        else
            c = ht[c].rchild;
        if (ht[c].lchild == 0)
        {
            if(words[c]==',')
            {
                printf(" ");
            }
            else{
                printf("%c", words[c]);
            }
            
            res << words[c];
            c = 2 * n - 1;
        }
    }
}

void PrintTree(HFTree ht, int c, int lev_num, ofstream &savetree, int lev = 1)
{

    if (c != 0)
    {
        cout.width(4 * lev);
        cout << ht[c].weight;
        savetree.width(4 * lev);
        savetree << ht[c].weight;
        for (int i = 0; i < lev_num * 10 - 4 * lev; i++)
        {
            cout << "-";
            savetree << "-";
        }
        cout << "|" << endl;
        savetree << "|" << endl;
        PrintTree(ht, ht[c].lchild, lev_num, savetree, ++lev);
        PrintTree(ht, ht[c].rchild, lev_num, savetree, lev);
    }
}

void LoadHfTree(HFTree &tem_tree, char *words, int n)
{
    ifstream hfcodef;
    hfcodef.open("hfmTree.txt");
    int i = 1;
    while (!hfcodef.eof())
    {
        hfcodef >> words[i] >> tem_tree[i].weight >> tem_tree[i].parent >> tem_tree[i].lchild >> tem_tree[i].rchild;
        i++;
    }
    hfcodef.close();
}

int main()
{
    char choice;
    int n;
    printf("请首先输入字符集自负总数:");
    cin >> n;

    while (true)
    {
        choice = getchar();
        if (choice == 'Q')
            return 0;
        else if (choice == 'I')
        {
            int w[n + 1];
            char word[n + 1];
            for (int i = 1; i <= n; i++)
            {
                cin >> word[i];
                cin >> w[i];
            }
            HFTree hftree;
            CreatHTTree(hftree, w, n);

            // 存储哈夫曼树
            ofstream ht_file;
            ht_file.open("hfmTree.txt");
            for (int i = 1; i <= 2 * n - 1; i++)
            {
                if (i > n)
                {
                    ht_file << "- " << hftree[i].weight << " " << hftree[i].parent << " " << hftree[i].lchild << " " << hftree[i].rchild << endl;
                }
                else
                {
                    ht_file << word[i] << " " << hftree[i].weight << " " << hftree[i].parent << " " << hftree[i].lchild << " " << hftree[i].rchild << endl;
                }
            }
            ht_file.close();
        }

        else if (choice == 'E')
        {
            HFTree tem_tree;
            char words[n + 1];
            LoadHfTree(tem_tree, words, n);

            char *codes[n + 1];
            CreateHfCode(tem_tree, codes, n);

            ifstream f;
            f.open("ToBeTran.txt");
            ofstream res;
            res.open("CodeFile.txt");

            char c;
            while (!f.eof())
            {
                f >> c;
                if (f.good())
                {

                    for (int i = 1; i <= n; i++)
                    {
                        if (c == words[i])
                        {
                            cout << codes[i];
                            res << codes[i];
                        }
                    }
                }
            }
            f.close();
            res.close();
        }

        else if (choice == 'D')
        {
            char data[100];
            ifstream data_file;
            data_file.open("CodeFile.txt");
            data_file >> data;

            HFTree tem_tree;
            char words[n + 1];
            LoadHfTree(tem_tree, words, n);

            DeCode(tem_tree, data, words, n);
            printf("\n");
        }

        else if (choice == 'P')
        {
            char data[100];
            ifstream data_file;
            data_file.open("CodeFile.txt");
            data_file >> data;

            ofstream codepr;
            codepr.open("CodePrin.txt");

            for (int i = 1; i < strlen(data); i++)
            {
                printf("%c", data[i]);
                codepr << data[i];
                if (i % 50 == 0)
                {
                    printf("\n");
                    codepr << endl;
                }
            }
        }
        else if (choice == 'T')
        {
            HFTree tem_tree;
            char words[n + 1];
            LoadHfTree(tem_tree, words, n);
            int sum_lev = (int)(log2(n) + 1);

            ofstream savetree;
            savetree.open("TreePrint.txt");
            PrintTree(tem_tree, 2 * n - 1, sum_lev, savetree);
            savetree.close();
        }
    }

    return 0;
}