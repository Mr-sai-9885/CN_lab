#include <stdio.h>

int main() {
    int cost[10][10]; // Matrix to store the cost between nodes
    int i, j, k, n;

    // Step 1: Input the number of nodes
    printf("Enter matrix size: ");
    scanf("%d", &n);  // Number of nodes in the network

    // Step 2: Input the cost matrix
    printf("Enter matrix (cost between nodes):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);  // cost[i][j] = direct distance from node i to j
        }
    }

    // Step 3: Apply Distance Vector logic
    for (i = 0; i < n; i++) {          // Source node
        for (j = 0; j < n; j++) {      // Destination node
            for (k = 0; k < n; k++) {  // Intermediate node
                // If going through node k is cheaper, update cost[i][j]
                if (cost[i][j] > cost[i][k] + cost[k][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    // Step 4: Print the shortest path costs
    printf("\nFinal Distance Table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Node %d to %d via shortest path = %d\n", i + 1, j + 1, cost[i][j]);
        }
    }

    return 0;
}
