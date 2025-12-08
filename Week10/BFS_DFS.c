#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int visited[MAX];

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int numvertices;
    struct Node **adjlists;
};

struct Node* createNode(int v)
{
    struct Node* newn=(struct Node*)malloc(sizeof(struct Node));
    newn->vertex=v;
    newn->next=NULL;
    return newn;
};

struct Graph* createGraph(int vertices)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numvertices=vertices;
    graph->adjlists=(struct Node**)malloc(vertices*sizeof(struct Node*));
    for(int i=0;i<vertices;i++)
    {
        graph->adjlists[i]=NULL;
        visited[i]=0;
    }
    return graph;
};

void addEdge(struct Graph* graph, int src,int dest)
{
    struct Node* newn=createNode(dest);
    newn->next=graph->adjlists[src];
    graph->adjlists[src]=newn;
    newn=createNode(src);
    newn->next=graph->adjlists[dest];
    graph->adjlists[dest]=newn;
}

void resetVisited(int vertices)
{
    for(int i=0;i<vertices;i++)
        visited[i]=0;
}

void BFS(struct Graph* graph, int start)
{

    int queue[MAX],rear=0,front=0;
    resetVisited(graph->numvertices);
    visited[start]=1;
    queue[rear++]=start;
    while(front!=rear)
    {
        int current=queue[front++];
        printf("%d ",current);
        struct Node* temp=graph->adjlists[current];
        while(temp)
        {
            int adj=temp->vertex;
            if(!visited[adj])
            {
                visited[adj]=1;
                queue[rear++]=adj;
            }
            temp=temp->next;
        }
    }
    printf("\n");
}

void DFS(struct Graph* graph, int start)
{
    struct Node* adjlist=graph->adjlists[start];
    struct Node* temp=adjlist;
    visited[start]=1;
    printf("%d ",start);
    while(temp)
    {
        int connected=temp->vertex;
        if(!visited[connected])
            DFS(graph,connected);
        temp=temp->next;
    }
}

int main()
{
    int vertices=6;
    struct Graph* graph=createGraph(vertices);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,2,4);
    addEdge(graph,3,4);
    addEdge(graph,3,5);
    printf("BFS\n");
    BFS(graph,0);
    printf("DFS\n");
    resetVisited(graph->numvertices);
    DFS(graph,0);
    return 0;
}
