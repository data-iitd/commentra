#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

// Define a structure for a directed edge in the graph
typedef struct directed_edge {
  int32_t vertex; // The destination vertex of the edge
  int32_t next;   // The index of the next edge in the adjacency list
} graph_edge;

// Define a structure for the directed graph
typedef struct directedGraph {
  graph_edge *edge;       // Array of edges
  int32_t *start;         // Array of start pointers for each vertex
  int32_t pointer;        // Current number of edges
  int32_t vertex_num;     // Number of vertices
  int32_t edge_max_size;  // Maximum size of the edge array
} graph;

// Function to initialize a new graph with a given number of vertices
graph* new_graph (const int vertex_num) {
  graph *g = (graph *) calloc (1, sizeof (graph));
  g->edge = (graph_edge *) calloc (1, sizeof (graph_edge));
  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  g->pointer = 0;
  g->vertex_num = vertex_num;
  g->edge_max_size = 1;
  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1; // Initialize all start pointers to -1 (no edges initially)
  }
  return g;
}

// Function to add a directed edge to the graph
void add_edge (graph *g, int32_t from, int32_t to) {
  if (g->pointer == g->edge_max_size) {
    g->edge_max_size *= 2;
    g->edge = (graph_edge *) realloc (g->edge, sizeof (graph_edge) * g->edge_max_size);
  }
  g->edge[g->pointer] = (graph_edge) {to, g->start[from]}; // Set the new edge and update the start pointer
  g->start[from] = g->pointer++; // Update the start pointer to the new edge
}

// Define the modulo constant
const i32 mod = 1000000007;

// Function to compute r^n % mod using exponentiation by squaring
i32 mod_pow (i32 r, i32 n) {
  i32 t = 1;
  i32 s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod; // If n is odd, multiply t by s
    s = (i64) s * s % mod; // Square s
    n >>= 1; // Halve n
  }
  return t;
}

// Define a structure for a node in the dynamic programming array
typedef struct dp_node {
  i32 one;  // Number of ways to have exactly one edge
  i32 zero; // Number of ways to have exactly zero edges
} node;

// Function to merge two nodes in the dynamic programming array
node merge (node *a, i32 n) {
  i64 one = 0;
  i64 zero = 1;
  i64 total = 1;
  for (i32 i = 0; i < n; ++i) {
    one = (one * a[i].zero + zero * a[i].one) % mod; // Calculate the number of ways to have exactly one edge
    zero = zero * a[i].zero % mod; // Calculate the number of ways to have exactly zero edges
    total = total * (a[i].zero + a[i].one) % mod; // Calculate the total number of ways
  }
  return (node) {one, (total + mod - one) % mod}; // Return the merged node
}

// Define the type for values stored in the deque
typedef node deque_val;

// Define a structure for the deque
typedef struct Deque {
  deque_val *array;
  size_t front;
  size_t last;
  size_t mask;
} deque;

// Function to initialize a new deque
deque* new_deque (void) {
  const size_t len = 2;
  deque *d = (deque *) calloc (len, sizeof (deque));
  d->array = (deque_val *) calloc (len, sizeof (deque_val));
  d->front = d->last = 0;
  d->mask = len - 1;
  return d;
}

// Function to free the memory allocated for a deque
void free_deque (deque * const d) {
  free (d->array);
  free (d);
}

// Function to get the number of elements in the deque
size_t get_size (const deque *d) {
  return (d->last + (~d->front + 1)) & d->mask;
}

// Function to reallocate the deque when necessary
void deque_realloc (deque * const d) {
  deque_val *array = (deque_val *) calloc (2 * (d->mask + 1), sizeof (deque_val));
  size_t k = 0;
  for (size_t i = d->front; i != d->last; i = (i + 1) & d->mask) {
    array[k++] = d->array[i];
  }
  free (d->array);
  d->array = array;
  d->front = 0;
  d->last = k;
  d->mask = 2 * d->mask + 1;
}

// Function to get the value at a specific index in the deque
deque_val get_at (const deque *d, size_t x) {
  return d->array[(d->front + x) & d->mask];
}

// Function to assign a value at a specific index in the deque
void assign_at (const deque *d, size_t x, deque_val v) {
  d->array[(d->front + x) & d->mask] = v;
}

// Function to add an element to the front of the deque
void push_front (deque * const d, const deque_val v) {
  if(((d->last + 1) & d->mask) == d->front) {
    deque_realloc (d);
  }
  d->front = (d->front + d->mask) & d->mask;
  d->array[d->front] = v;
}

// Function to compare the sizes of two deques
int cmp_deque_size (const void *a, const void *b) {
  deque *p = *(deque **)a;
  deque *q = *(deque **)b;
  i32 d = get_size (p) - get_size (q);
  return d == 0 ? 0 : d > 0 ? -1 : 1;
}

// Function to run the main logic of the program
void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n); // Read the number of vertices
  i32 *p = (i32 *) calloc (n + 1, sizeof (i32)); // Array to store parent pointers
  i32 *depth = (i32 *) calloc (n + 1, sizeof (i32)); // Array to store depths of vertices
  i32 *cnt = (i32 *) calloc (n + 1, sizeof (i32)); // Array to count vertices at each depth
  cnt[0] = 1; // There is one way to have zero edges (the root itself)
  graph *g = new_graph (n + 1); // Initialize the graph
  for (i32 i = 1; i <= n; ++i) {
    scanf ("%" SCNi32, p + i); // Read the parent of each vertex
    add_edge (g, p[i], i); // Add the edge to the graph
    depth[i] = depth[p[i]] + 1; // Calculate the depth of each vertex
    cnt[depth[i]]++; // Increment the count of vertices at the current depth
  }
  deque **dp = (deque **) calloc (n + 1, sizeof (deque *)); // Array to store dynamic programming results
  deque **child = (deque **) calloc (n + 1, sizeof (deque *)); // Array to store child deques
  node *lst = (node *) calloc (n + 1, sizeof (node)); // Array to store merged nodes
  for (i32 i = n; i >= 0; --i) {
    i32 v = i;
    if (g->start[v] == -1) {
      dp[v] = new_deque();
      push_front (dp[v], (node) {1, 1}); // Initialize the dp array for leaf nodes
      continue;
    }
    i32 len = 0;
    for (i32 p = g->start[v]; p != -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      child[len++] = dp[u]; // Collect child deques
    }
    if (len > 1) {
      qsort (child, len, sizeof (deque *), cmp_deque_size); // Sort child deques by size
      for (i32 d = 0; d < (i32) get_size (child[1]); ++d) {
        i32 j = 0;
        for (; j < len && d < (i32) get_size (child[j]); ++j) {
          lst[j] = get_at (child[j], d); // Get nodes at the current depth
        }
        assign_at (child[0], d, merge (lst, j)); // Merge nodes and assign to the first child deque
      }
      for (i32 j = 1; j < len; ++j) {
	free_deque (child[j]); // Free memory of unused child deques
      }
    }
    dp[v] = child[0]; // Assign the merged deque to the current vertex
    push_front (dp[v], (node) {1, 1}); // Add the current node to the dp array
  }
  i64 ans = 0;
  for (i32 i = 0; i < (i32) get_size (dp[0]); ++i) {
    ans += (i64) mod_pow (2, n + 1 - cnt[i]) * get_at (dp[0], i).one % mod; // Calculate the answer
  }
  printf ("%" PRIi64 "\n", ans % mod); // Print the result
}

// Main function to run the program
int main (void) {
  run();
  return 0;
}