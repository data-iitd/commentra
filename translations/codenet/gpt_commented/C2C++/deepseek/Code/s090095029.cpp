#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  // Declare variables for the number of nodes (n) and edges (m)
  int n, m;
  
  // Read the number of nodes and edges from standard input
  std::cin >> n >> m;
  
  // Initialize an array to track connections (r0) and set all values to false
  std::vector<bool> r0(n, false);
  
  // Initialize an array to store nodes connected to node n (r1) and a counter for it
  std::vector<int> r1;
  
  // Process each edge input
  for (int i = 0; i < m; i++) {
    int a, b;
    
    // Read the endpoints of the edge
    std::cin >> a >> b;
    
    // Ensure a is the smaller node and b is the larger node
    if (a > b) {
      std::swap(a, b);
    }
    
    // Mark the connection from node a to node b in r0
    if (a == 1) r0[b - 1] = true; // If a is 1, mark b-1 as connected
    
    // If b is the last node (n), store a-1 in r1
    if (b == n) r1.push_back(a - 1); // Store a-1 in r1
  }
  
  // Initialize a result variable to determine if a connection is possible
  bool res = false;
  
  // Check if any of the nodes connected to node n are also connected to node 1
  for (int node : r1) {
    if (r0[node]) res = true; // If r0 at node is true, set res to true
  }
  
  // Output the result based on the value of res
  std::cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;
  
  return 0; // End of the program
}
