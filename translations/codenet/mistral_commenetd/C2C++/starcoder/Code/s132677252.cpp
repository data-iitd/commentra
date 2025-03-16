#include<bits/stdc++.h>

using namespace std;

// Include necessary header files

typedef int32_t i32;
typedef int64_t i64;

// Define custom data types

typedef struct directed_edge {
  int32_t vertex;  // Vertex number
  int32_t next;    // Pointer to next edge
} graph_edge;

typedef struct directedGraph {
  graph_edge *edge;      // Array of edges
  int32_t *start;       // Array to store starting vertices of each edge
  int32_t pointer;       // Index to keep track of memory allocation
  int32_t vertex_num;    // Number of vertices in the graph
  int32_t edge_max_size; // Maximum size of edge array
} graph;

// Define a custom graph data structure

graph* new_graph (const int vertex_num) {
  graph *g = (graph *) calloc (1, sizeof (graph));
  // Allocate memory for graph structure

  g->edge = (graph_edge *) calloc (1, sizeof (graph_edge));
  // Allocate memory for first edge

  g->start = (int32_t *) calloc (vertex_num, sizeof (int32_t));
  // Allocate memory for starting vertices array

  g->pointer = 0;
  g->vertex_num = vertex_num;
  g->edge_max_size = 1;
  // Initialize graph properties

  for (int32_t i = 0; i < vertex_num; ++i) {
    g->start[i] = -1;
  }
  // Initialize starting vertices to -1

  return g;
}

// Function to create a new graph with given number of vertices

void add_edge (graph *g, int32_t from, int32_t to) {
  if (g->pointer == g->edge_max_size) {
    g->edge_max_size *= 2;
    g->edge = (graph_edge *) realloc (g->edge, sizeof (graph_edge) * g->edge_max_size);
  }
  // Check if memory allocation is needed

  g->edge[g->pointer] = (graph_edge) {to, g->start[from]};
  // Add new edge to the graph

  g->start[from] = g->pointer++;
  // Update starting vertex of the new edge
}

// Function to add an edge between two vertices

const i32 mod = 1000000007;

// Define a constant for modular arithmetic

i32 mod_pow (i32 r, i32 n) {
  i64 t = 1;
  i64 s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod;
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return (i32) t;
}

// Function to compute modular exponentiation

typedef struct dp_node {
  i32 one;
  i32 zero;
} node;

// Define a custom data structure for dynamic programming

typedef node deque_val;

typedef struct Deque {
  deque_val *array;
  size_t front;
  size_t last;
  size_t mask;
} deque;

// Define a custom deque data structure

deque* new_deque (void) {
  const size_t len = 2;
  deque *d = (deque *) calloc (len, sizeof (deque));
  d->array = (deque_val *) calloc (len, sizeof (deque_val));
  // Allocate memory for deque structure and its array

  d->front = d->last = 0;
  d->mask = len - 1;
  // Initialize front and last indices and mask

  return d;
}

// Function to create a new deque

void free_deque (deque * const d) {
  free (d->array);
  free (d);
}

// Function to free deque resources

size_t get_size (const deque *d) {
  return (d->last + (~d->front + 1)) & d->mask;
}

// Function to get the size of a deque

void deque_realloc (deque * const d) {
  deque_val *array = (deque_val *) calloc (2 * (d->mask + 1), sizeof (deque_val));
  size_t k = 0;
  for (size_t i = d->front; i!= d->last; i = (i + 1) & d->mask) {
    array[k++] = d->array[i];
  }
  free (d->array);
  d->array = array;
  d->front = 0;
  d->last = k;
  d->mask = 2 * d->mask + 1;
}

// Function to reallocate deque memory

deque_val get_at (const deque *d, size_t x) {
  return d->array[(d->front + x) & d->mask];
}

// Function to get the value at a given index in a deque

void assign_at (const deque *d, size_t x, deque_val v) {
  d->array[(d->front + x) & d->mask] = v;
}

// Function to assign a value to a given index in a deque

void push_front (deque * const d, const deque_val v) {
  if(((d->last + 1) & d->mask) == d->front) {
    deque_realloc (d);
  }
  // Check if memory allocation is needed

  d->front = (d->front + d->mask) & d->mask;
  // Update front index

  d->array[d->front] = v;
  // Add new value to the front of the deque
}

// Function to push a value to the front of a deque

int cmp_deque_size (const void *a, const void *b) {
  deque *p = *(deque **)a;
  deque *q = *(deque **)b;
  i32 d = get_size (p) - get_size (q);
  return d == 0? 0 : d > 0? -1 : 1;
}

// Function to compare two deques based on their sizes

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  // Read the number of vertices from the standard input

  i32 *p = (i32 *) calloc (n + 1, sizeof (i32));
  // Allocate memory for an array to store the parent pointers

  i32 *depth = (i32 *) calloc (n + 1, sizeof (i32));
  // Allocate memory for an array to store the depth of each vertex

  i32 *cnt = (i32 *) calloc (n + 1, sizeof (i32));
  // Allocate memory for an array to store the number of nodes at each depth

  cnt[0] = 1;
  // Initialize the number of nodes at depth 0

  graph *g = new_graph (n + 1);
  // Create a new graph with n+1 vertices

  for (i32 i = 1; i <= n; ++i) {
    scanf ("%" SCNi32, p + i);
    // Read the parent pointer for each vertex

    add_edge (g, p[i], i);
    // Add an edge from the parent to the current vertex

    depth[i] = depth[p[i]] + 1;
    // Update the depth of the current vertex

    cnt[depth[i]]++;
    // Increment the number of nodes at the current depth
  }
  // Process all vertices and edges

  deque **dp = (deque **) calloc (n + 1, sizeof (deque *));
  // Allocate memory for an array to store deques for each vertex

  deque **child = (deque **) calloc (n + 1, sizeof (deque *));
  // Allocate memory for an array to store the children deques for each vertex

  node *lst = (node *) calloc (n + 1, sizeof (node));
  // Allocate memory for an array to store the last dp values for each vertex

  for (i32 i = n; i >= 0; --i) {
    i32 v = i;
    if (g->start[v] == -1) {
      dp[v] = new_deque();
      // If the vertex has no children, create a new deque for it

      push_front (dp[v], (node) {1, 1});
      // Add the initial dp values (one and zero)

      continue;
    }
    // Otherwise, process the children

    i32 len = 0;
    for (i32 p = g->start[v]; p!= -1; p = g->edge[p].next) {
      i32 u = g->edge[p].vertex;
      child[len++] = dp[u];
      // Get the children deques
    }
    if (len > 1) {
      qsort (child, len, sizeof (deque *), cmp_deque_size);
      // Sort the children deques based on their sizes

      for (i32 d = 0; d < (i32) get_size (child[1]); ++d) {
        i32 j = 0;
        for (; j < len && d < (i32) get_size (child[j]); ++j) {
          lst[j] = get_at (child[j], d);
          // Get the last dp values from the children deques
        }
        assign_at (child[0], d, merge (lst, j));
        // Merge the last dp values and update the root deque
      }
      for (i32 j = 1; j < len; ++j) {
        free_deque (child[j]);
        // Free the memory of the children deques
      }
    }
    dp[v] = child[0];
    // Update the root deque with the merged dp values

    push_front (dp[v], (node) {1, 1});
    // Add the initial dp values (one and zero)
  }
  // Process all vertices

  i64 ans = 0;
  // Initialize the answer to 0

  for (i32 i = 0; i < (i32) get_size (dp[0]); ++i) {
    ans += (i64) mod_pow (2, n + 1 - cnt[i]) * get_at (dp[0], i).one % mod;
    // Calculate the answer using the dp values
  }
  // Print the answer

  printf ("%" PRIi64 "\n", ans % mod);
  // Print the answer modulo 1000000007

  free (p);
  free (depth);
  free (cnt);
  free (g);
  free (dp);
  free (child);
  free (lst);
  // Free all allocated memory
}

// Main function to run the program

int main (void) {
  run();
  return 0;
}

// Entry point of the program

