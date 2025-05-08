// Simple Distance Vector Routing Algorithm
#include<stdio.h>

// Structure to store distance and source node
struct node {
    unsigned dist[10];   // Distance to other nodes
    unsigned from[10];   // From which node this distance comes
} rt[10];  // Routing table for each node

int main() {
    int cost[10][10];   // Cost matrix
    int n, i, j, k, count = 0;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input cost matrix
    printf("Enter cost matrix (999 for no link):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            rt[i].dist[j] = cost[i][j];  // Initialize distance
            rt[i].from[j] = j;           // Initially each node assumes it can reach others directly
        }
    }

    // Distance Vector Algorithm
    do {
        count = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                for(k = 0; k < n; k++) {
                    // If going through k is better
                    if(rt[i].dist[j] > cost[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = cost[i][k] + rt[k].dist[j];
                        rt[i].from[j] = k; // Update via node
                        count++;
                    }
                }
            }
        }
    } while(count != 0);  // Repeat until no changes

    // Print final routing table
    for(i = 0; i < n; i++) {
        printf("\nRouting table for Router %d:\n", i + 1);
        for(j = 0; j < n; j++) {
            printf("Node %d via %d Distance %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }

    return 0;
}
