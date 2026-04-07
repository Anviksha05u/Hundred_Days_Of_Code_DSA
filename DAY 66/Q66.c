/*
Problem: Detect cycle in directed graph using DFS and recursion stack.
Output:
- YES if cycle exists
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int vertex;
    struct Node* next;
};
struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
bool dfs(int v, struct Node* adj[], bool visited[], bool recStack[])
{
    visited[v] = true;
    recStack[v] = true;
    struct Node* temp = adj[v];
    while (temp != NULL)
    {
        int neighbor = temp->vertex;
        if (!visited[neighbor])
        {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        } else if (recStack[neighbor])
        {
            return true;
        }
        temp = temp->next;
    }
    recStack[v] = false;
    return false;
}
//Accept edges[][] and number of edges E
bool isCyclic(int V, int edges[][2], int E)
{
    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }
    bool visited[V];
    bool recStack[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, recStack))
                return true;
        }
    }
    return false;
}
int main()
{
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    int edges[E][2];
    printf("Enter %d directed edges (u v):\n", E);
    for (int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    if (isCyclic(V, edges, E))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}