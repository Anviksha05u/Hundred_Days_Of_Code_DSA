/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//Node for adjacency list
struct Node
{
    int vertex;
    struct Node* next;
};
//Create new adjacency list node
struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
int main()
{
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Node* adj[MAX];
    int indegree[MAX] = {0};
    for (int i = 0; i < V; i++)
    {
        adj[i] = NULL;
    }
    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        //Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        indegree[v]++;
    }
    //Queue implementation
    int queue[MAX];
    int front = 0, rear = 0;
    //Insert all vertices with indegree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }
    int count = 0;
    printf("Topological Order: ");
    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);
        count++;
        struct Node* temp = adj[current];
        while (temp != NULL)
        {
            int neighbor = temp->vertex;
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    //Cycle detection
    if (count != V)
    {
        printf("\nCycle detected! Topological sorting not possible.\n");
    }
    return 0;
}