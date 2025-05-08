#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>  // Required for sqrt()

#define MAX_NODES 10
#define MAX_ENERGY 100
#define THRESHOLD_ENERGY 20

typedef struct {
    int id;
    int is_active;
    int energy;
    int x, y; // position
} Node;

Node nodes[MAX_NODES];
int node_count = 0;

// Utility function to calculate distance between two nodes
double distance(Node a, Node b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// Initialize network nodes via user input
void init_nodes() {
    printf("Enter number of nodes (max %d):", MAX_NODES);
    scanf("%d", &node_count);

    for (int i = 0; i < node_count; i++) {
        printf("Node %d - Enter x y energy: \n", i);
        scanf("%d %d %d", &nodes[i].x, &nodes[i].y, &nodes[i].energy);
        nodes[i].id = i;
        nodes[i].is_active = 1;
    }

    // Deactivate unused nodes
    for (int i = node_count; i < MAX_NODES; i++) {
        nodes[i].is_active = 0;
    }
}

// Simulate sleep scheduling (duty cycling)
void sleep_schedule() {
    for (int i = 0; i < node_count; i++) {
        if (nodes[i].energy < THRESHOLD_ENERGY) {
            nodes[i].is_active = 0;
            printf("Node %d entering sleep mode (low energy)\n", nodes[i].id);
        } else {
            nodes[i].is_active = 1;
        }
    }
}

// Find the next hop based on residual energy and distance
int select_next_hop(int source, int dest) {
    int next = -1;
    double min_metric = 1e9;

    for (int i = 0; i < node_count; i++) {
        if (i == source || !nodes[i].is_active) continue;

        double d = distance(nodes[source], nodes[i]);
        double energy_factor = (double)nodes[i].energy / MAX_ENERGY;

        if (energy_factor <= 0) continue;

        double metric = d / energy_factor;
        if (metric < min_metric) {
            min_metric = metric;
            next = i;
        }
    }

    return next;
}

// Simulate data transmission
void transmit_data(int source, int dest) {
    if (!nodes[source].is_active || !nodes[dest].is_active) {
        printf("Transmission failed: Node %d or %d is inactive.\n", source, dest);
        return;
    }

    int current = source;
    printf("Transmitting from Node %d to Node %d\n", source, dest);

    while (current != dest) {
        int next = select_next_hop(current, dest);
        if (next == -1) {
            printf("No available path from Node %d to Node %d\n", current, dest);
            return;
        }

        double d = distance(nodes[current], nodes[next]);
        int energy_used = (int)(d / 5);  // simulate energy use

        if (nodes[current].energy < energy_used) {
            printf("Node %d has insufficient energy to transmit.\n", current);
            return;
        }

        nodes[current].energy -= energy_used;
        printf("Node %d -> Node %d | Energy used: %d | Remaining: %d\n", current, next, energy_used, nodes[current].energy);

        current = next;
    }

    printf("Data successfully delivered to Node %d\n", dest);
}

// Energy monitoring
void monitor_energy() {
    for (int i = 0; i < node_count; i++) {
        printf("Node %d - Energy: %d\n", i, nodes[i].energy);
    }
}

int main() {
    init_nodes();
    monitor_energy();

    sleep_schedule();

    int source, dest;
    printf("Enter source and destination node IDs: ");
    scanf("%d %d", &source, &dest);

    if (source >= node_count || dest >= node_count || source < 0 || dest < 0) {
        printf("Invalid source or destination ID.\n");
        return 1;
    }

    transmit_data(source, dest);

    printf("\nAfter transmission:\n");
    monitor_energy();

    return 0;
}
