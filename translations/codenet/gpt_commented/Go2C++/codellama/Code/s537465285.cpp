
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Function to read the next line from standard input
string NextLine() {
  string line;
  getline(cin, line);
  return line;
}

// Function to read the next integer from standard input
int NextInt() {
  int n;
  cin >> n;
  return n;
}

// Function to write output to standard output
void Write(int s) {
  cout << s << endl;
}

// Function to check if the graph is bipartite
bool Bipartite(vector<string> *S) {
  int N = S->size(); // Get the number of nodes
  vector<int> D(N); // Distance array to store levels of nodes
  D[0] = 1; // Start with the first node at level 1
  queue<int> Q; // Queue for BFS
  bool ret = true; // Variable to track if the graph is bipartite
  int pos = 1; // Position in the queue

  // Perform BFS to check for bipartiteness
  for (int i = 0; i < N; i++) {
    if (!ret) { break; } // Exit if already determined not bipartite
    int q = Q.front(); // Current node
    Q.pop();
    for (int j = 0; j < N; j++) {
      if ((*S)[q][j] == '0') {
        continue; // Skip if there is no edge
      }
      if (D[j] == 0) {
        // Assign level to the adjacent node
        D[j] = D[q] + 1;
        Q.push(j); // Add to queue
        continue;
      }
      // Check if the adjacent node has the same level
      if (D[j] % 2 == D[q] % 2) {
        ret = false; // Not bipartite
        break;
      }
    }
  }
  return ret; // Return the result of bipartiteness check
}

// Function to perform the Floyd-Warshall algorithm to find the longest shortest path
int WarshallFloyd(vector<string> *S) {
  int N = S->size(); // Get the number of nodes
  vector<vector<int>> G(N); // Initialize the graph matrix

  // Initialize the graph with distances
  for (int i = 0; i < N; i++) {
    G[i] = vector<int>(N);
    for (int j = 0; j < N; j++) {
      if (i == j) { continue; } // Skip self-loops
      if ((*S)[i][j] == '0') {
        G[i][j] = N; // No edge, set to a large value
      } else {
        G[i][j] = 1; // Edge exists, set distance to 1
      }
    }
  }

  // Floyd-Warshall algorithm to find shortest paths
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (G[i][k] + G[k][j] < G[i][j]) {
          G[i][j] = G[i][k] + G[k][j]; // Update shortest path
        }
      }
    }
  }

  // Find the maximum distance in the graph
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (ans < G[i][j]) { ans = G[i][j]; } // Update maximum distance
    }
  }
  return ans + 1; // Return the maximum distance found
}

// Main function to execute the program
int main() {
  int N = NextInt(); // Read the number of nodes
  vector<string> S(N); // Initialize the adjacency matrix
  for (int i = 0; i < N; i++) {
    S[i] = NextLine(); // Read each line of the adjacency matrix
  }
  
  // Check if the graph is bipartite and process accordingly
  if (!Bipartite(&S)) {
    Write(-1); // Output -1 if not bipartite
  } else {
    Write(WarshallFloyd(&S)); // Output the longest shortest path if bipartite
  }
  
  return 0; // Return 0 to end the program
}

