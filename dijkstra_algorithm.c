#include <stdio.h>
#define INFINITY 9999
#define MAX 10

// Function to perform Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int n, int startNode) {
    int distance[MAX];         // Stores shortest distance from startNode
    int visited[MAX];          // Keeps track of visited nodes
    int predecessor[MAX];      // Stores the predecessor of each node
    int i, j, count, minDist, nextNode;

    // Step 1: Initialize distance, visited, and predecessor arrays
    for (i = 0; i < n; i++) {
        distance[i] = graph[startNode][i];
        predecessor[i] = startNode;
        visited[i] = 0;
    }

    distance[startNode] = 0;  // Distance to self is 0
    visited[startNode] = 1;   // Start node is visited
    count = 1;

    // Step 2: Loop until all nodes are visited
    while (count < n - 1) {
        minDist = INFINITY;
        nextNode = -1;

        // Find the unvisited node with the smallest distance
        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDist) {
                minDist = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        // Update distances of neighboring unvisited nodes
        for (i = 0; i < n; i++) {
            if (!visited[i] && (minDist + graph[nextNode][i] < distance[i]) && graph[nextNode][i] != 0) {
                distance[i] = minDist + graph[nextNode][i];
                predecessor[i] = nextNode;
            }
        }
        count++;
    }

    // Step 3: Print shortest distances and paths
    for (i = 0; i < n; i++) {
        if (i != startNode) {
            printf("\nDistance to node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            while (j != startNode) {
                j = predecessor[j];
                printf(" <- %d", j);
            }
            printf("\n");
        }
    }
}

int main() {
    int graph[MAX][MAX], n, i, j, startNode;

    // Get number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Get the adjacency matrix
    printf("Enter the adjacency matrix (0 for no direct edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INFINITY;  // No direct edge
        }
    }

    // Get starting node
    printf("Enter the starting node (0 to %d): ", n - 1);
    scanf("%d", &startNode);

    // Call Dijkstra function
    dijkstra(graph, n, startNode);

    return 0;
}
