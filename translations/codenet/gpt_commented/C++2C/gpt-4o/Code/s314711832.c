#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN(a, b) ((a < b) ? a : b) // Macro to find the minimum of two values
#define INF 1000000001 // Define a constant for infinity (a large value)
#define N 100000 // Define a constant for the maximum number of vertices

// Structure to represent an edge in the graph
struct edge {
    int source; // Source vertex of the edge
    int target; // Target vertex of the edge
    int weight; // Weight of the edge
};

struct edge edges[N]; // Array to store all edges of the graph

int distances[N]; // Array to store the shortest distances from the source vertex
int prev_distances[N]; // Array to store the previous distances for comparison

int main() {
    int V, E, r; // Variables for number of vertices, edges, and the source vertex

    // Read the number of vertices, edges, and the source vertex from input
    scanf("%d %d %d", &V, &E, &r);

    // Read all edges from input and store them in the edges array
    for (int i = 0; i < E; i++) {
        int source, target, distance; // Variables to hold edge data
        scanf("%d %d %d", &source, &target, &distance); // Read edge data
        edges[i].source = source; // Create a new edge
        edges[i].target = target;
        edges[i].weight = distance;
    }

    // Initialize distances array to infinity for all vertices
    for (int i = 0; i < N; i++) {
        distances[i] = INF; // Set all distances to a maximum value (infinity)
    }

    distances[r] = 0; // Set the distance to the source vertex to 0

    // Main loop to relax edges V-1 times
    for (int i = 1; i < V; i++) {
        // Copy current distances to previous distances for comparison
        for (int j = 0; j < V; j++) {
            prev_distances[j] = distances[j];  
        }
        
        // Relax all edges
        for (int j = 0; j < E; j++) {
            // Update the distance to the target vertex if a shorter path is found
            distances[edges[j].target] = MIN(distances[edges[j].source] + edges[j].weight, distances[edges[j].target]);
        }

        // Check if any distance was updated in this iteration
        bool same = true; // Flag to check if distances remain the same
        for (int j = 0; j < V; j++) {
            if (distances[j] != prev_distances[j]) {
                same = false; // If any distance changed, set flag to false
                break;
            }
        }

        // If no distances were updated, break out of the loop early
        if (same) break;
    }

    // Output the shortest distances from the source vertex to all other vertices
    for (int i = 0; i < V; i++) {
        if (distances[i] == INF) {
            printf("INF\n"); // Print "INF" if the vertex is unreachable
        } else {
            printf("%d\n", distances[i]); // Print the shortest distance
        }
    }

    return 0;
}

// <END-OF-CODE>
