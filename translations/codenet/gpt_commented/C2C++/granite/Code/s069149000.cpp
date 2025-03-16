
#include<iostream>
#define INF 100000  // Define a constant for infinity
#define MAX 101     // Define the maximum number of vertices
#define NIL -6      // Define a constant for a non-existent parent
#define WHITE 0     // Define color for unvisited nodes
#define GRAY 1      // Define color for nodes being visited
#define BLACK 2     // Define color for visited nodes

using namespace std;

int G[MAX][MAX]; // Adjacency matrix to represent the graph
int n;           // Number of vertices in the graph

// Function to implement Prim's algorithm for finding the Minimum Spanning Tree (MST)
void prim(){
  int i, j;
  int d[MAX];    // Array to store the minimum distance to each vertex
  int pi[MAX];   // Array to store the parent of each vertex in the MST
  int color[MAX]; // Array to track the state of each vertex (WHITE, GRAY, BLACK)
  int min, u, v, sum = 0; // Variables for minimum distance, current vertex, and total weight of MST

  // Initialize the arrays
  for(i = 0; i < n; i++){
    d[i] = INF;   // Set all distances to infinity
    pi[i] = NIL;  // Set all parents to NIL
    color[i] = WHITE; // Set all vertices to unvisited
  }

  d[0] = 0; // Start from the first vertex, set its distance to 0

  // Main loop of Prim's algorithm
  while(1){
    min = INF; // Initialize minimum distance
    u = NIL;   // Initialize current vertex

    // Find the vertex with the minimum distance that hasn't been visited
    for(i = 0; i < n; i++){
      if(color[i]!= BLACK && d[i] < min){
        min = d[i];
        u = i; // Update the current vertex
      }
    }
    
    // If no vertex is found, break out of the loop
    if(u == NIL){
      break;
    }

    color[u] = BLACK; // Mark the current vertex as visited

    // Update the distances and parents for adjacent vertices
    for(v = 0; v < n; v++){
      if(color[v]!= BLACK && G[u][v]!= INF){
        // If the edge weight is less than the current known distance
        if(d[v] > G[u][v]){
          d[v] = G[u][v]; // Update the distance
          pi[v] = u;      // Update the parent
          color[v] = GRAY; // Mark the vertex as being visited
        }
      }
    }
  }

  // Calculate the total weight of the MST
  for(i = 0; i < n; i++){
    if(pi[i]!= NIL) sum += G[i][pi[i]]; // Add the weight of the edges in the MST
  }
  
  // Print the total weight of the Minimum Spanning Tree
  cout << sum << endl;
}

// Main function to read input and execute Prim's algorithm
int main(){
  int e; // Variable to store edge weights
  int i, j;

  // Read the number of vertices
  cin >> n;

  // Read the adjacency matrix representation of the graph
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      cin >> e;
      if(e == -1){
        G[i][j] = INF; // If input is -1, set the edge weight to infinity
      } else {
        G[i][j] = e;   // Otherwise, set the edge weight to the input value
      }
    }
  }

  // Call the Prim's algorithm function to find the MST
  prim();
  return 0; // Return success
}

