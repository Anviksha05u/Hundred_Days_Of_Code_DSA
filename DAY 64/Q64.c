/*
Problem: Perform BFS from a given source using queue.
Input:
- n
- adjacency list
- source s
Output:
- BFS traversal order
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
//BFS function
void bfs(int s, struct Node* adj[], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    int queue[n];
    int front = 0, rear = 0;
    //Start from source
    visited[s] = 1;
    queue[rear++] = s;
    printf("BFS traversal starting from vertex %d: ", s);
    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);
        struct Node* temp = adj[v];
        while (temp != NULL)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
int main()
{
    int n, m, u, v, s, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    //Create adjacency list
    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;
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
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &s);
    bfs(s, adj, n);
    return 0;
}