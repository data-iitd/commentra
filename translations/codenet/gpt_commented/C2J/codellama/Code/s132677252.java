#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// Define types for 32-bit and 64-bit integers
typedef int32_t i32;
typedef int64_t i64;

// Structure to represent a directed edge in the graph
typedef struct directed_edge {
  int32_t vertex; // The destination vertex of the edge
  int32_t next;   // The index of the next edge in the adjacency list
} graph_edge;

// Structure to represent a directed graph
typedef struct directedGraph {
  graph_edge *edge;          // Array of edges
  int32_t *start;            // Array to store the starting index of edges for each vertex
  int32_t pointer;           // Current number of edges in the graph
  int32_t vertex_num;        // Number of vertices in the graph
  int32_t edge_max_size;     // Maximum size of the edges array
} graph;

// Function to create a new directed graph with a specified number of vertices
graph* new_graph (const int vertex_num) {
  // Allocate memory for the graph structure
  graph *g = (graph *) calloc (1, sizeof (graph));
  // Allocate memory for edges and initialize the start array
  g->edge = (graph_edge *) calloc (1, sizeof (graph_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0; // Initialize edge count to 0
  g->vertex_num = vertex_num; // Set the number of vertices
  g->edge_max_size = 1; // Initialize maximum edge size
  // Initialize the start array to -1 (indicating no edges)
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  return g; // Return the created graph
}

// Function to add a directed edge from 'from' to 'to' in the graph
void add_edge (graph *g, int32_t from, int32_t to) {
  // Check if the edges array needs to be resized
  if (g->pointer == g->edge_max_size) {
    g->edge_max_size *= 2; // Double the maximum size
    g->edge = (graph_edge *) realloc (g->edge, sizeof (graph_edge) * g->edge_max_size);
  }
  // Add the edge to the graph
  g->edge[g->pointer] = (graph_edge) {to, g->start[from]};
  g->start[from] = g->pointer++; // Update the start index for 'from'
}

// Define a constant for modulo operations
const i32 mod = 1000000007;

// Function to compute modular exponentiation
i32 mod_pow (i32 r, i32 n) {
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
typedef struct dp_node {
  i32 one;  // Count of paths ending with 1
  i32 zero; // Count of paths ending with 0
} node;

// Function to merge multiple dp nodes
node merge (node *a, i32 n) {
  i64 one = 0; // Initialize count of paths ending with 1
  i64 zero = 1; // Initialize count of paths ending with 0
  i64 total = 1; // Initialize total paths
  // Iterate through the nodes to merge their counts
  for (i32 i = 0; i < n; ++i) {
    one = (one * a[i].zero + zero * a[i].one) % mod; // Update count of paths ending with 1
    zero = zero * a[i].zero % mod; // Update count of paths ending with 0
    total = total * (a[i].zero + a[i].one) % mod; // Update total paths
  }
  return (node) {one, (total + mod - one) % mod}; // Return merged node
}

// Define a type for deque values
typedef node deque_val;

// Structure to represent a deque (double-ended queue)
typedef struct Deque {
  deque_val *array; // Array to store deque values
  size_t front;     // Index of the front element
  size_t last;      // Index of the last element
  size_t mask;      // Mask for circular indexing
} deque;

// Function to create a new deque
deque* new_deque (void) {
  const size_t len = 2; // Initial length of the deque
  deque *d = (deque *) calloc (len, sizeof (deque)); // Allocate memory for the deque
  d->array = (deque_val *) calloc (len, sizeof (deque_val)); // Allocate memory for the array
  d->front = d->last = 0; // Initialize front and last indices
  d->mask = len - 1; // Set the mask for circular indexing
  return d; // Return the created deque
}

// Function to free the memory allocated for a deque
void free_deque (deque * const d) {
  free (d->array); // Free the array
  free (d); // Free the deque structure
}

// Function to get the size of the deque
size_t get_size (const deque *d) {
  return (d->last + (~d->front + 1)) & d->mask; // Calculate the size using circular indexing
}

// Function to reallocate memory for the deque when it is full
void deque_realloc (deque * const d) {
  // Allocate a new array with double the size
  deque_val *array = (deque_val *) calloc (2 * (d->mask + 1), sizeof (deque_val));
  size_t k = 0; // Index for the new array
  // Copy elements from the old array to the new array
  for (size_t i = d->front; i != d->last; i = (i + 1) & d->mask) {
    array[k++] = d->array[i];
  }
  free (d->array); // Free the old array
  d->array = array; // Update the deque's array to the new array
  d->front = 0; // Reset front index
  d->last = k; // Update last index
  d->mask = 2 * d->mask + 1; // Update the mask for the new size
}

// Function to get the value at a specific index in the deque
deque_val get_at (const deque *d, size_t x) {
  return d->array[(d->front + x) & d->mask]; // Return the value using circular indexing
}

// Function to assign a value at a specific index in the deque
void assign_at (const deque *d, size_t x, deque_val v) {
  d->array[(d->front + x) & d->mask] = v; // Assign the value using circular indexing
}

// Function to push a value to the front of the deque
void push_front (deque * const d, const deque_val v) {
  // Check if the deque is full
  if(((d->last + 1) & d->mask) == d->front) {
    deque_realloc (d); // Reallocate if full
  }
  d->front = (d->front + d->mask) & d->mask; // Move front index backwards
  d->array[d->front] = v; // Assign the value at the front
}

// Comparison function for sorting deques based on their size
int cmp_deque_size (const void *a, const void *b) {
  deque *p = *(deque **)a; // Get the first deque
  deque *q = *(deque **)b; // Get the second deque
  i32 d = get_size (p) - get_size (q); // Calculate the size difference
  return d == 0 ? 0 : d > 0 ? -1 : 1; // Return comparison result
}

// Main function to run the algorithm
void run (void) {
  i32 n; // Number of vertices
  scanf ("%" SCNi32, &n); // Read the number of vertices
  // Allocate memory for parent, depth, and count arrays
  i32 *p = (i32 *) calloc (n + 1, sizeof (i32));
  i32 *depth = (i32 *) calloc (n + 1, sizeof (i32));
  i32 *cnt = (i32 *) calloc (n + 1, sizeof (i32));
  cnt[0] = 1; // Initialize count for depth 0
  graph *g = new_graph (n + 1); // Create a new graph
  // Read edges and build the graph
  for (i32 i = 1; i <= n; ++i) {
    scanf ("%" SCNi32, p + i); // Read parent for vertex i
    add_edge (g, p[i], i); // Add edge from parent to current vertex
    depth[i] = depth[p[i]] + 1; // Update depth of current vertex
    cnt[depth[i]]++; // Increment count for the current depth
  }
  // Allocate memory for dynamic programming arrays
  deque **dp = (deque **) calloc (n + 1, sizeof (deque *));
  deque **child = (deque **) calloc (n + 1, sizeof (deque *));
  node *lst = (node *) calloc (n + 1, sizeof (node));
  // Process vertices in reverse order
  for (i32 i = n; i >= 0; --i) {
    i32 v = i; // Current vertex
    // If the vertex has no outgoing edges
    if (g->start[v] == -1) {
      dp[v] = new_deque(); // Create a new deque for this vertex
      push_front (dp[v], (node) {1, 1}); // Initialize with base case
      continue; // Move to the next vertex
    }
    i32 len = 0; // Length of child deques
    // Collect child deques for the current vertex
    for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex; // Get child vertex
      child[len++] = dp[u]; // Store child deque
    }
    // If there are multiple child deques, merge them
    if (len > 1) {
      qsort (child, len, sizeof (deque *), cmp_deque_size); // Sort child deques by size
      // Merge the child deques
      for (i32 d = 0; d < (i32) get_size (child[1]); ++d) {
        i32 j = 0;
        for (; j < len && d < (i32) get_size (child[j]); ++j) {
          lst[j] = get_at (child[j], d); // Get nodes from child deques
        }
        assign_at (child[0], d, merge (lst, j)); // Merge and assign to the first child
      }
      // Free the other child deques
      for (i32 j = 1; j < len; ++j) {
        free_deque (child[j]);
      }
    }
    dp[v] = child[0]; // Assign the merged deque to the current vertex
    push_front (dp[v], (node) {1, 1}); // Add the base case to the front
  }
  i64 ans = 0; // Variable to store the final answer
  // Calculate the final answer based on the dp values
  for (i32 i = 0; i < (i32) get_size (dp[0]); ++i) {
    ans += (i64) mod_pow (2, n + 1 - cnt[i]) * get_at (dp[0], i).one % mod; // Update answer
  }
  printf ("%" PRIi64 "\n", ans % mod); // Print the final answer
}

// Main function to execute the program
int main (void) {
  run(); // Call the run function
  return 0; // Return success
}

