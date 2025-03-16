
#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) ((a < b)? a : b) // Macro to find the minimum of two values
#define INF 10000000001 // Define a constant for infinity (a large value)
#define N 100000 // Define a constant for the maximum number of vertices

typedef struct {
  int source; // Source vertex of the edge
  int target; // Target vertex of the edge
  int weight; // Weight of the edge
} edge;

edge* edges; // Pointer to an array of edges
int distances[N]; // Array to store the shortest distances from the source vertex
int prev_distances[N] = {0}; // Array to store the previous distances for comparison

int main() {
  int V, E, r; // Variables for number of vertices, edges, and the source vertex

  // Read the number of vertices, edges, and the source vertex from input
  scanf("%d %d %d", &V, &E, &r);

  // Allocate memory for the edges array
  edges = (edge*)malloc(E * sizeof(edge));

  // Read all edges from input and store them in the edges array
  for (int i = 0; i < E; i++) {
    int source, target, distance; // Variables to hold edge data
    scanf("%d %d %d", &source, &target, &distance); // Read edge data
    edges[i] = (edge){ source, target, distance}; // Create a new edge
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
      if (distances[j]!= prev_distances[j]) {
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

  // Free the memory allocated for the edges array
  free(edges);

  return 0;
}
