/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
Output:
- YES or NO
*/

#include <stdio.h>
#include <stdlib.h>
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
//DFS function to detect cycle
int dfs(int v, int parent, struct Node* adj[], int visited[])
{
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp != NULL)
    {
        int neighbor = temp->vertex;
        if (!visited[neighbor])
        {
            if (dfs(neighbor, v, adj, visited))
                return 1;
        }
        else if (neighbor != parent)
        {
            return 1; // cycle found
        }
        temp = temp->next;
    }
    return 0;
}
int main()
{
    int n, m, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    struct Node* adj[n];
    for (int i = 0; i < n; i++)
    adj[i] = NULL;
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (u v) for undirected graph:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        //Add u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        //Add v -> u
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
    int visited[n];
    for (int i = 0; i < n; i++)
    visited[i] = 0;
    int hasCycle = 0;
    //Check all components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited))
            {
                hasCycle = 1;
                break;
            }
        }
    }
    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}