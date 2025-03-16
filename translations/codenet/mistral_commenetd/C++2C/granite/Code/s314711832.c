

#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) ((a < b)? a : b)
#define INF 1000000001

#define N 100000

struct edge {
  int source;
  int target;
  int weight;
};

struct edge *edges;

int distances[N];
int prev_distances[N] = {0};

int main() {
  int V, E, r; // V: number of vertices, E: number of edges, r: source vertex

  // Read input
  scanf("%d %d %d", &V, &E, &r);

  // Allocate memory for edges
  edges = (struct edge*)malloc(E * sizeof(struct edge));

  // Read edges and store in edges array
  for (int i = 0; i < E; i++) {
    int source, target, distance;
    scanf("%d %d %d", &source, &target, &distance);
    edges[i].source = source;
    edges[i].target = target;
    edges[i].weight = distance;
  }

  // Initialize distances array with maximum value
  for (int i = 0; i < N; i++) {
    distances[i] = INF ; // max value
  }

  // Set initial distance of source vertex to 0
  distances[r] = 0;

  // Bellman-Ford algorithm
  for (int i = 1; i < V; i++) {
    // Initialize previous distances array with current distances
    for (int j=0; j< V; j++) {
      prev_distances[j] = distances[j];  
    }

    // Update distances for all vertices
    for (int j=0; j< E; j++) {
      distances[edges[j].target] = MIN(distances[edges[j].source] + edges[j].weight, distances[edges[j].target]);
    
    }

    // Check if all distances have been updated
    bool same = true;
    for (int j=0; j< V; j++) {
      if (distances[j]!= prev_distances[j]) {
	same = false;
	break;
      }
    }

    // If all distances have been updated, break the loop
    if (same) break;
  }

  // Print results
  for (int i = 0; i < V; i++) {
    if (distances[i] == INF) {
      printf("INF\n");
    } else {
      printf("%d\n", distances[i]);
    }
  }

  // Free memory for edges
  free(edges);

  return 0;
}
