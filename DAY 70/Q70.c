/*
Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
Input:
- n vertices
- m edges (u,v,w)
Output:
- Shortest distances OR NEGATIVE CYCLE
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 999999
int main()
{
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    int u[m], v[m], w[m];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    int dist[n];
    //Initialize distances
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;
    //Relax all edges (n-1) times
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]])
                {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }
    //Check for negative cycle
    for (int j = 0; j < m; j++)
    {
        if (dist[u[j]] != INF &&
            dist[u[j]] + w[j] < dist[v[j]])
            {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }
    //Print shortest distances
    printf("\nShortest distances from source %d:\n", source);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("To %d = INF\n", i);
        else
            printf("To %d = %d\n", i, dist[i]);
    }
    return 0;
}