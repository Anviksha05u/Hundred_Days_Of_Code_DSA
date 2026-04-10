/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/

#include <stdio.h>
#define MAX 100
#define INF 999999
int main()
{
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    int graph[MAX][MAX];
    //Initialize graph with INF
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = INF;
        }
    }
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; //Remove this line for directed graph
    }
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    int dist[MAX], visited[MAX];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;
    //Dijkstra Algorithm
    for (int count = 0; count < V - 1; count++)
    {
        int min = INF, u = -1;
        //Find unvisited vertex with minimum distance
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1)
        break;
        visited[u] = 1;
        //Update neighbors
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("\nShortest distances from source %d:\n", source);
    for (int i = 0; i < V; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }
    return 0;
}