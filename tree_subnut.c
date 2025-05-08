
// AIM: Display directly connected nodes in a subnet
#include <stdio.h>

int a[10][10], n;

// Function to print adjacent nodes for the given root
void adj(int root) {
    printf("\nAdjacent nodes to node %d:\n", root);
    for (int j = 0; j < n; j++) {
        if (a[root][j] == 1 || a[j][root] == 1)
            printf("%d\t", j); // Print if connection exists
    }
    printf("\n");
}

int main() {
    int root;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Connection from %d to %d: ", i, j);
            scanf("%d", &a[i][j]);
        }

    printf("\nEnter root node index: ");
    scanf("%d", &root);

    adj(root); // Call to display adjacent nodes
    return 0;
}
