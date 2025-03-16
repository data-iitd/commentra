
#include <iostream>
#include <vector>
#define MIN(a, b) ((a < b) ? a : b)
#define INF 1000000001
#define N 100000

using namespace std;

struct edge {
  int source;
  int target;
  int weight;
};

vector<edge> edges;

int distances[N];
int prev_distances[N] = {0};

// Main function
int main() {
  int V, E, r; // V: number of vertices, E: number of edges, r: source vertex

  // Read input
  cin >> V >> E >> r;

  // Initialize edges vector
  for (int i = 0; i < E; i++) {
    int source, target, distance;
    cin >> source >> target >> distance;
    edge new_edge = { source, target, distance};
    edges.push_back(new_edge);
    
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
    for (vector<edge>::iterator edgeptr = edges.begin(); edgeptr != edges.end(); edgeptr++) {
      distances[edgeptr->target] = MIN(distances[edgeptr->source] + edgeptr->weight, distances[edgeptr->target]);
    
    }

    // Check if all distances have been updated
    bool same = true;
    for (int j=0; j< V; j++) {
      if (distances[j] != prev_distances[j]) {
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
      cout << "INF" << endl;
    } else {
      cout << distances[i] << endl;
    }
  }
}

