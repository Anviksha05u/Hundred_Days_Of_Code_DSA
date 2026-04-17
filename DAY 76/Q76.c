/*
Problem Statement
Using DFS or BFS, count number of connected components.
Input Format
n m
edges
Output Format
Number of connected components.
Sample Input
6 3
1 2
2 3
5 6
Sample Output
3
Explanation
Components: {1,2,3}, {4}, {5,6}
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//Adjacency list node
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
    int count = 0;
    //Count connected components
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
            count++;
        }
    }
    printf("Number of connected components: %d\n", count);
    return 0;
}