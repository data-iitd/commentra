#include <iostream>
#include <cstring>

int main() {
  // Declare variables for the number of nodes (n) and edges (m)
  int n, m;
  
  // Read the number of nodes and edges from standard input
  std::cin >> n >> m;
  
  // Initialize an array to track connections (r0) and set all values to false
  bool r0[n];
  memset(r0, 0x00, n); // Set all elements of r0 to false (0)
  
  // Initialize an array to store nodes connected to node n (r1) and a counter for it
  int r1[n];
  int nr1 = 0;
  
  // Process each edge input
  for (int i = 0; i < m; i++) {
    int a, b;
    
    // Read the endpoints of the edge
    std::cin >> a >> b;
    
    // Ensure a is the smaller node and b is the larger node
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }
    
    // Mark the connection from node a to node b in r0
    if (a == 1) r0[b - 1] = true; // If a is 1, mark b-1 as connected
    
    // If b is the last node (n), store a-1 in r1
    if (b == n) r1[nr1++] = a - 1; // Store a-1 in r1 and increment the count
  }
  
  // Initialize a result variable to determine if a connection is possible
  bool res = false;
  
  // Check if any of the nodes connected to node n are also connected to node 1
  for (int i = 0; i < nr1; i++) {
    if (r0[r1[i]]) res = true; // If r0 at r1[i] is true, set res to true
  }
  
  // Output the result based on the value of res
  std::cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;
  
  return 0; // End of the program
}

