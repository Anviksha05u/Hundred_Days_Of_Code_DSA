/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//Node for adjacency list
struct Node
{
    int vertex;
    struct Node* next;
};
//Create new node
struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
//Stack for topological order
int stack[MAX];
int top = -1;
//Push into stack
void push(int value)
{
    stack[++top] = value;
}
//DFS function
void dfs(int v, struct Node* adj[], int visited[])
{
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp != NULL)
    {
        int neighbor = temp->vertex;
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
        temp = temp->next;
    }
    push(v); //Push after visiting all neighbors
}
//Topological Sort
void topologicalSort(int V, struct Node* adj[])
{
    int visited[MAX] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
        }
    }
    printf("Topological Order: ");
    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
int main()
{
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Node* adj[MAX];
    for (int i = 0; i < V; i++)
    {
        adj[i] = NULL;
    }
    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }
    topologicalSort(V, adj);
    return 0;
}