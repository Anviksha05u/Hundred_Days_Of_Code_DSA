/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.
Input:
- n (vertices)
- m (edges)
- m pairs (u, v)
Output:
- n x n adjacency matrix
*/

#include <stdio.h>
int main()
{
    int n, m, i, u, v, choice;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int adj[n][n];
    //Initialize matrix with 0
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Is the graph directed?\n");
    printf("Enter 1 for YES, 0 for NO: ");
    scanf("%d", &choice);
    printf("Enter the edges (u v) where vertices are numbered from 0 to %d:\n", n - 1);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        //If undirected, add both directions
        if (choice == 0) 
        {
            adj[v][u] = 1;
        }
    }
    //Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}