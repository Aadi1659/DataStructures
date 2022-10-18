#include <stdio.h>
#define maxnodes 20

void intgraph(int adjmat[][maxnodes],int n){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjmat[i][j]=0;
        }
        
    }
}

void create_graph(int adjmat[][maxnodes],int n){
    int i,j;
    while (1)

    {
        printf("Enter the nodes and its adjacent nodes information\n");
        scanf("%d %d",&i,&j);
        if (i==0 && j==0)
        {
            break;
        }
        else{
            adjmat[i][j]=1;
        }
        
    }
    
}
    
void  display(int adjmat[][maxnodes],int n){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%5d",adjmat[i][j]);
        }
        printf("\n");

        
    }
}

void init_visited(int *visited,int n){
    for (int i = 0; i <= n; i++)
    {
        visited[i]=0;
    }
    
}
    
void dfs(int adjmat[][maxnodes],int *visted,int s,int n){
    visted[s]=1;
    printf("The dfs travsersal is with source as %d is ",s);
    printf("%d\n",s);
    
    for (int i = 1; i <= n; i++)
    {
        if (adjmat[s][i]==1 && visted[i]==0)
        {
            dfs(adjmat,visted,i,n);    
        }
        
    }
    
}

void bfs(int adjmat[][maxnodes],int * visited ,int s,int n){
    int q[20],f= 0 ,r= - 1;
    visited[s] = 1;
    printf("Nodes visited using BFS travsersal %d\n",s);
    q[++r] = s;
    while(f<=r){
        s=q[f++];
        for(int i=1;i<=n;i++){
            if (adjmat[s][i]==1 && visited[i]==0)
            {
                q[++r] = i;
                visited[i]= 1;
                printf("%d\n",i);
            }
            
        }
    }
}

int main(){

    int adjmat[maxnodes][maxnodes],visited[maxnodes],s;
    int ch,n,flag=0;
    do
    {
        printf("1:CREATE_Graph\n2:Display\n3:DFS\n4:BFS\n5:Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of nodes in a graph\n");
            scanf("%d",&n);
            intgraph(adjmat,n);
            create_graph(adjmat,n);
            break;
        case 2:
            display(adjmat,n);
            break;
        case 3:
            init_visited(visited,n);
            printf("Enter the source node\n");
            scanf("%d",&s);
            dfs(adjmat,visited,s,n);
            for (int i = 0; i < n; i++)
            {
                if (visited[i]==0)
                {
                    flag=1;
                    break;
                }
                
                
            }
            
            if (flag==1)
            {
                printf("Graph is not connected\n");
            }
            else
                printf("Graph is connected\n");
            

            
            break;
        case 4:
            printf("BFS traversal\n");
            
            init_visited(visited,n);
            printf("Enter source node");
            scanf("%d",&s);
            bfs(adjmat,visited,s,n);
            break;
        default:
            break;
        }
    } while (ch!=5);
    
}
