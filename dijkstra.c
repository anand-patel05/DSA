#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[])
{   
    printf("+---------+----------------------+\n| Vertexs | Distance from Source |");
    printf("\n+---------+----------------------+\n");
    for (int i = 0; i < V; i++)
    {
        printf("|    %d    |", i);

        if (dist[i]>=10)
        {
            printf("          %d          |", dist[i]);
        }

        else
        {
            printf("          0%d          |", dist[i]);
        }

        printf("\n");
    }

    printf("+---------+----------------------+\n");
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];

    bool sptSet[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] = {{0, 21, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 21, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 13, 14, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 11, 0, 1, 6},
                       {8, 1, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 22, 0, 0, 0, 5, 17, 0}};

    dijkstra(graph, 0);

    return 0;
}


























