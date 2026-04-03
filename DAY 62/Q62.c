/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.
Input:
- n (vertices)
- m (edges)
- edges (u, v)
Output:
- List of adjacency lists for each vertex
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
int main()
{
    int n, m, u, v, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    //Create array of adjacency lists
    struct Node* adj[n];
    //Initialize all lists as empty
    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Is the graph directed?\n");
    printf("Enter 1 for YES, 0 for NO: ");
    scanf("%d", &choice);
    printf("Enter edges (u v) where vertices are from 0 to %d:\n", n - 1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        //Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        //If undirected, add v -> u also
        if (choice == 0)
        {
            newNode = createNode(u);
            newNode->next = adj[v];
            adj[v] = newNode;
        }
    }
    //Print adjacency list
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", i);
        struct Node* temp = adj[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    return 0;
}