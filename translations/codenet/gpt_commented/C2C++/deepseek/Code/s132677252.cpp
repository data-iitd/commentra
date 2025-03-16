#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

// Define types for 32-bit and 64-bit integers
typedef int32_t i32;
typedef int64_t i64;

// Structure to represent a directed edge in the graph
struct directed_edge {
  int32_t vertex; // The destination vertex of the edge
  int32_t next;   // The index of the next edge in the adjacency list
};

// Structure to represent a directed graph
struct directedGraph {
  std::vector<directed_edge> edge;          // Array of edges
  std::vector<int32_t> start;               // Array to store the starting index of edges for each vertex
  int32_t pointer;                          // Current number of edges in the graph
  int32_t vertex_num;                       // Number of vertices in the graph
  int32_t edge_max_size;                    // Maximum size of the edges array
};

// Function to create a new directed graph with a specified number of vertices
directedGraph new_graph(const int vertex_num) {
  directedGraph g;
  // Allocate memory for edges and initialize the start array
  g.edge.reserve(1);
  g.start.resize(vertex_num, -1);
  g.pointer = 0; // Initialize edge count to 0
  g.vertex_num = vertex_num; // Set the number of vertices
  g.edge_max_size = 1; // Initialize maximum edge size
  return g; // Return the created graph
}

// Function to add a directed edge from 'from' to 'to' in the graph
void add_edge(directedGraph &g, int32_t from, int32_t to) {
  // Check if the edges array needs to be resized
  if (g.pointer == g.edge_max_size) {
    g.edge_max_size *= 2; // Double the maximum size
    g.edge.reserve(g.edge_max_size);
  }
  // Add the edge to the graph
  g.edge.push_back({to, g.start[from]});
  g.start[from] = g.pointer++; // Update the start index for 'from'
}

// Define a constant for modulo operations
const i32 mod = 1000000007;

// Function to compute modular exponentiation
i32 mod_pow(i32 r, i32 n) {
  i32 t = 1; // Result variable
  i32 s = r; // Base
  // Loop until the exponent is zero
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod; // If n is odd, multiply the result by the base
    s = (i64) s * s % mod; // Square the base
    n >>= 1; // Divide n by 2
  }
  return t; // Return the result
}

// Structure to represent a node in dynamic programming
struct dp_node {
  i32 one;  // Count of paths ending with 1
  i32 zero; // Count of paths ending with 0
};

// Function to merge multiple dp nodes
dp_node merge(const std::vector<dp_node> &a) {
  i64 one = 0; // Initialize count of paths ending with 1
  i64 zero = 1; // Initialize count of paths ending with 0
  i64 total = 1; // Initialize total paths
  // Iterate through the nodes to merge their counts
  for (const auto &node : a) {
    one = (one * node.zero + zero * node.one) % mod; // Update count of paths ending with 1
    zero = zero * node.zero % mod; // Update count of paths ending with 0
    total = total * (node.zero + node.one) % mod; // Update total paths
  }
  return {static_cast<i32>(one), static_cast<i32>((total + mod - one) % mod)}; // Return merged node
}

// Structure to represent a deque (double-ended queue)
struct Deque {
  std::vector<dp_node> array; // Array to store deque values
  size_t front;     // Index of the front element
  size_t last;      // Index of the last element
  size_t mask;      // Mask for circular indexing
};

// Function to create a new deque
Deque new_deque() {
  const size_t len = 2; // Initial length of the deque
  Deque d;
  d.array.resize(len); // Allocate memory for the array
  d.front = d.last = 0; // Initialize front and last indices
  d.mask = len - 1; // Set the mask for circular indexing
  return d; // Return the created deque
}

// Function to free the memory allocated for a deque
void free_deque(Deque &d) {
  d.array.clear(); // Free the array
}

// Function to get the size of the deque
size_t get_size(const Deque &d) {
  return (d.last + (~d.front + 1)) & d.mask; // Calculate the size using circular indexing
}

// Function to reallocate memory for the deque when it is full
void deque_realloc(Deque &d) {
  // Allocate a new array with double the size
  std::vector<dp_node> array(2 * (d.mask + 1));
  size_t k = 0; // Index for the new array
  // Copy elements from the old array to the new array
  for (size_t i = d.front; i != d.last; i = (i + 1) & d.mask) {
    array[k++] = d.array[i];
  }
  d.array = std::move(array); // Update the deque's array to the new array
  d.front = 0; // Reset front index
  d.last = k; // Update last index
  d.mask = 2 * d.mask + 1; // Update the mask for the new size
}

// Function to get the value at a specific index in the deque
dp_node get_at(const Deque &d, size_t x) {
  return d.array[(d.front + x) & d.mask]; // Return the value using circular indexing
}

// Function to assign a value at a specific index in the deque
void assign_at(Deque &d, size_t x, const dp_node &v) {
  d.array[(d.front + x) & d.mask] = v; // Assign the value using circular indexing
}

// Function to push a value to the front of the deque
void push_front(Deque &d, const dp_node &v) {
  // Check if the deque is full
  if(((d.last + 1) & d.mask) == d.front) {
    deque_realloc(d); // Reallocate if full
  }
  d.front = (d.front + d.mask) & d.mask; // Move front index backwards
  d.array[d.front] = v; // Assign the value at the front
}

// Comparison function for sorting deques based on their size
int cmp_deque_size(const void *a, const void *b) {
  Deque *p = *(Deque **)a; // Get the first deque
  Deque *q = *(Deque **)b; // Get the second deque
  int d = get_size(p) - get_size(q); // Calculate the size difference
  return d == 0 ? 0 : d > 0 ? -1 : 1; // Return comparison result
}

// Main function to run the algorithm
void run() {
  i32 n; // Number of vertices
  std::cin >> n; // Read the number of vertices
  // Allocate memory for parent, depth, and count arrays
  std::vector<i32> p(n + 1);
  std::vector<i32> depth(n + 1);
  std::vector<i32> cnt(n + 1);
  cnt[0] = 1; // Initialize count for depth 0
  directedGraph g = new_graph(n + 1); // Create a new graph
  // Read edges and build the graph
  for (i32 i = 1; i <= n; ++i) {
    std::cin >> p[i]; // Read parent for vertex i
    add_edge(g, p[i], i); // Add edge from parent to current vertex
    depth[i] = depth[p[i]] + 1; // Update depth of current vertex
    cnt[depth[i]]++; // Increment count for the current depth
  }
  // Allocate memory for dynamic programming arrays
  std::vector<Deque *> dp(n + 1);
  std::vector<Deque *> child(n + 1);
  std::vector<dp_node> lst(n + 1);
  // Process vertices in reverse order
  for (i32 i = n; i >= 0; --i) {
    i32 v = i; // Current vertex
    // If the vertex has no outgoing edges
    if (g.start[v] == -1) {
      dp[v] = new Deque(); // Create a new deque for this vertex
      push_front(*dp[v], {1, 1}); // Initialize with base case
      continue; // Move to the next vertex
    }
    i32 len = 0; // Length of child deques
    // Collect child deques for the current vertex
    for (i32 p = g.start[v]; p != -1; p = g.edge[p].next) {
      i32 u = g.edge[p].vertex; // Get child vertex
      child[len++] = dp[u]; // Store child deque
    }
    // If there are multiple child deques, merge them
    if (len > 1) {
      std::qsort(child.data(), len, sizeof(Deque *), cmp_deque_size); // Sort child deques by size
      // Merge the child deques
      for (i32 d = 0; d < static_cast<i32>(get_size(*child[1])); ++d) {
        i32 j = 0;
        for (; j < len && d < static_cast<i32>(get_size(child[j])); ++j) {
          lst[j] = get_at(child[j], d); // Get nodes from child deques
        }
        assign_at(child[0], d, merge({lst.begin(), lst.begin() + j})); // Merge and assign to the first child
      }
      // Free the other child deques
      for (i32 j = 1; j < len; ++j) {
        free_deque(child[j]);
      }
    }
    dp[v] = child[0]; // Assign the merged deque to the current vertex
    push_front(*dp[v], {1, 1}); // Add the base case to the front
  }
  i64 ans = 0; // Variable to store the final answer
  // Calculate the final answer based on the dp values
  for (i32 i = 0; i < static_cast<i32>(get_size(*dp[0])); ++i) {
    ans += (i64) mod_pow(2, n + 1 - cnt[i]) * get_at(*dp[0], i).one % mod; // Update answer
  }
  std::cout << ans % mod << std::endl; // Print the final answer
}

// Main function to execute the program
int main() {
  run(); // Call the run function
  return 0; // Return success
}

