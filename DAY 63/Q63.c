/*
Problem: Perform DFS starting from a given source vertex using recursion.
Input:
- n
- adjacency list
- starting vertex s
Output:
- DFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>
//Node structure for adjacency list
struct Node
{
    int vertex;
    struct Node* next;
};
//Function to create a new node
struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
//DFS function
void dfs(int v, struct Node* adj[], int visited[])
{
    visited[v] = 1;
    printf("%d ", v);
    struct Node* temp = adj[v];
    while (temp != NULL)
    {
        if (!visited[temp->vertex])
        {
            dfs(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}
int main()
{
    int n, m, u, v, s, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    //Create adjacency list
    struct Node* adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Is the graph directed? Enter 1 for YES, 0 for NO: ");
    scanf("%d", &choice);
    printf("Enter edges (u v) with vertices numbered from 0 to %d:\n", n-1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        //Add u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        //If undirected, add v -> u
        if (choice == 0)
        {
            newNode = createNode(u);
            newNode->next = adj[v];
            adj[v] = newNode;
        }
    }
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &s);
    //DFS
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("DFS traversal starting from vertex %d: ", s);
    dfs(s, adj, visited);
    printf("\n");
    return 0;
}