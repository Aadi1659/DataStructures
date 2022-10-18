#include <stdio.h>
#include <stdlib.h>

#define maxnodes 20
typedef struct node
{
    int data;
    struct node *link;

} graph;

void initgraph(graph **nodep, int n)
{
    for (int i = 1; i <= n; i++)
    {
        nodep[i] = NULL;
    }
}

void insertnode(graph **nodep, int i, int j)
{
    graph *newnode = (graph *)malloc(sizeof(graph));
    graph *current;
    newnode->data = j;
    newnode->link = NULL;

    current = nodep[i];
    if (current == NULL)
    {
        nodep[i] = newnode;
    }
    else
    {
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = newnode;
    }
}
void create_graph(graph **nodep, int n)
{
    int i, j;
    while (1)
    {
        printf("Enter the node and its adjacent nodes info\n");
        scanf("%d %d", &i, &j);
        if (i == 0 && j == 0)
        {
            break;
        }
        else
            insertnode(nodep, i, j);
    }
}

void display(graph **nodep, int n)
{
    graph *current;
    for (int i = 1; i <= n; i++)
    {
        printf("The nodes adjacent to %d are ", i);
        current = nodep[i];
        while (current != NULL)
        {
            printf("%5d\n", current->data);
            current = current->link;
        }
    }
}

void init_visited(int *visited, int n)
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
};

void dfs(graph **nodep, int *visited, int s, int n)
{
    visited[s] = 1;
    int adj;
    printf("The dfs traversal is with source %d is ", s);
    printf("%d\n", s);

    for (graph *p = nodep[s]; p != NULL; p = p->link)
    {
        adj = p->data;
        if (visited[adj] == 0)
        {
            dfs(nodep, visited, adj, n);
        }
    }
};

void bfs(graph **nodep, int *visited, int s, int n)
{
    int q[20], f = 0, r = -1;
    visited[s] = 1;
    printf("Nodes visited using BFS traversal with source %d\n", s);
    q[++r] = s;
    int adj;
    while (f <= r)
    {
        s = q[f++];
        for (graph *p = nodep[s]; p != NULL; p = p->link)
        {
            adj = p->data;
            if (visited[adj] == 0)
            {
                q[++r] = adj;
                visited[adj] = 1;
                printf("%d\n", adj);
            }
        }
    }
}

int main()
{

    graph *listnode[maxnodes];
    int ch, n, flag = 0, visited[maxnodes];
    int s;
    do
    {
        printf("1:CREATE_Graph\n2:Display\n3:DFS\n4:BFS\n5:Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of nodes in a graph\n");
            scanf("%d", &n);
            initgraph(listnode, n);
            create_graph(listnode, n);
            break;
        case 2:
            display(listnode, n);
            break;
        case 3:
            printf("DFS travsersal\n");
            init_visited(visited, n);
            printf("Enter the source node to visit \n");
            scanf("%d", &s);
            dfs(listnode, visited, s, n);
            break;
        case 4:
            printf("BFS traversal\n");
            init_visited(visited, n);
            printf("Enter the source node to visit\n");
            scanf("%d", &s);
            bfs(listnode, visited, s, n);
            break;
        default:
            break;
        }
    } while (ch != 5);
}
