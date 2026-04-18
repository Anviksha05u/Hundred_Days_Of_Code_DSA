/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.
Input Format
n m
edges
Output Format
CONNECTED
NOT CONNECTED
Sample Input
4 2
1 2
3 4
Sample Output
NOT CONNECTED
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//Node structure for adjacency list
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
//DFS function
void dfs(int v, struct Node* adj[], int visited[])
{
    visited[v] = 1;
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
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    struct Node* adj[MAX];
    //Initialize adjacency list
    for (int i = 1; i <= n; i++)
    {
        adj[i] = NULL;
    }
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        //Undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
    int visited[MAX] = {0};
    //Start DFS from node 1
    dfs(1, adj, visited);
    //Check if all nodes are visited
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }
    printf("CONNECTED\n");
    return 0;
}