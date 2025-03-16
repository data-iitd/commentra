#include <iostream>
#include <vector>
#define MIN(a, b) ((a < b) ? a : b) // Macro to find the minimum of two values
#define INF 1000000001 // Define a constant for infinity (a large value)
#define N 100000 // Define a constant for the maximum number of vertices

using namespace std;

// Structure to represent an edge in the graph
struct edge {
  int source; // Source vertex of the edge
  int target; // Target vertex of the edge
  int weight; // Weight of the edge
};

vector<edge> edges; // Vector to store all edges of the graph

int distances[N]; // Array to store the shortest distances from the source vertex
int prev_distances[N] = {0}; // Array to store the previous distances for comparison

int main() {
  int V, E, r; // Variables for number of vertices, edges, and the source vertex

  // Read the number of vertices, edges, and the source vertex from input
  cin >> V >> E >> r;

  // Read all edges from input and store them in the edges vector
  for (int i = 0; i < E; i++) {
    int source, target, distance; // Variables to hold edge data
    cin >> source >> target >> distance; // Read edge data
    edge new_edge = { source, target, distance}; // Create a new edge
    edges.push_back(new_edge); // Add the new edge to the edges vector
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
    for (vector<edge>::iterator edgeptr = edges.begin(); edgeptr != edges.end(); edgeptr++) {
      // Update the distance to the target vertex if a shorter path is found
      distances[edgeptr->target] = MIN(distances[edgeptr->source] + edgeptr->weight, distances[edgeptr->target]);
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
      cout << "INF" << endl; // Print "INF" if the vertex is unreachable
    } else {
      cout << distances[i] << endl; // Print the shortest distance
    }
  }
}
